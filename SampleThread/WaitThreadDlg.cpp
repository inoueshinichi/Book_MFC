#include "pch.h"

#include "SampleThread.h"

#include "WaitThreadDlg.h"

#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNAMIC(WaitThreadDlg, BaseMFCDialog)

WaitThreadDlg::WaitThreadDlg(CWnd* pOwner)
	: BaseMFCDialog(IDD_WaitThreadDlg, pOwner)
	, mFileName(_T(""))
	, mPeekThread(FALSE)
	, mTimerID(1)
{

}

WaitThreadDlg::~WaitThreadDlg()
{

}

void WaitThreadDlg::DoDataExchange(CDataExchange* pDX)
{
	BaseMFCDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_WaitThreadDlg_File, mFileName);
	DDX_Control(pDX, IDC_PROGRESS_WaitThreadDlg, mProgressCtrl);
	DDX_Control(pDX, IDC_BUTTON_WaitThreadDlg_Start, mButtonStart);
	DDX_Control(pDX, IDC_BUTTON_WaitThreadDlg_Stop, mButtonStop);
	DDX_Check(pDX, IDC_CHECK_PEEK_THREAD, mPeekThread);
}


BEGIN_MESSAGE_MAP(WaitThreadDlg, BaseMFCDialog)

	ON_BN_CLICKED(IDC_BUTTON_WaitThreadDlg_File, &WaitThreadDlg::OnBnClickedButtonWaitthreaddlgFile)
	ON_BN_CLICKED(IDC_BUTTON_WaitThreadDlg_Stop, &WaitThreadDlg::OnBnClickedButtonWaitthreaddlgStop)
	ON_BN_CLICKED(IDC_BUTTON_WaitThreadDlg_Start, &WaitThreadDlg::OnBnClickedButtonWaitthreaddlgStart)
	ON_WM_TIMER()
END_MESSAGE_MAP()

void WaitThreadDlg::OnBnClickedButtonWaitthreaddlgFile()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	CString filter = _T("すべてのファイル(*.*)|*.*|");
	CFileDialog fileDialog(true, nullptr, nullptr, OFN_HIDEREADONLY, filter);
	if (fileDialog.DoModal() == IDOK)
	{
		mFileName = fileDialog.GetPathName();
		CWnd::UpdateData(false);
	}
}


void WaitThreadDlg::OnBnClickedButtonWaitthreaddlgStop()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	mRunningThread = false;
}

static constexpr const int BUFFER_SIZE = 1024;

// private
void WaitThreadDlg::NoThreadPattern()
{
	mRunningThread = false;
	CFile readFile;
	if (readFile.Open(mFileName, CFile::modeRead))
	{
		int count = (int)(readFile.GetLength() / BUFFER_SIZE) + 1;
		mProgressCtrl.SetRange32(0, count);
		mButtonStart.EnableWindow(false);
		mButtonStart.EnableWindow(true);
		for (int i = 0; i < count; ++i)
		{
			BYTE buffer[BUFFER_SIZE];
			readFile.Read(buffer, sizeof(buffer));
			mProgressCtrl.SetPos(i + 1);

			_tprintf(_T("Read bytes : %d\n"), (i + 1) * sizeof(buffer));
			if (mRunningThread)
			{
				_tprintf(_T("Break reading file!\n"));
				break;
			}
		}
		readFile.Close();
		_tprintf(_T("Finish reading file!\n"));
	}
}


// thread func v1 (static)
static UINT ThreadReadFile_ver1_with_gui_process(LPVOID pParam)
{
	_tprintf(_T("Start worker thread!\n"));
	WaitThreadDlg* dlg = (WaitThreadDlg*)(pParam);
	dlg->mRunningThread = false;
	CFile readFile;
	if (readFile.Open(dlg->mFileName, CFile::modeRead))
	{
		BYTE buffer[BUFFER_SIZE];
		int count = (int)(readFile.GetLength() / sizeof(buffer)) + 1;
		for (int i = 0; i < count; ++i)
		{
			readFile.Read(buffer, sizeof(buffer));
			dlg->mProgressCtrl.SetPos(i + 1); // デッドロックの原因になる
			_tprintf(_T("Read bytes : %d\n"), (i + 1) * sizeof(buffer));

			if (dlg->mRunningThread)
			{
				_tprintf(_T("Break reading file!\n"));
				break;
			}
		}
		readFile.Close();
	}
	_tprintf(_T("Finish worker thread!\n"));
	return 0;
}

// thread func v2 (static)
static UINT ThreadReadFile_ver2_without_gui_process(LPVOID pParam)
{
	_tprintf(_T("Start worker thread!\n"));
	WaitThreadDlg* dlg = (WaitThreadDlg*)(pParam);
	dlg->mRunningThread = false;
	dlg->mCount = 0;
	CFile readFile;
	if (readFile.Open(dlg->mFileName, CFile::modeRead))
	{
		BYTE buffer[BUFFER_SIZE];
		int count = (int)(readFile.GetLength() / sizeof(buffer)) + 1;
		for (int i = 0; i < count; ++i)
		{
			readFile.Read(buffer, sizeof(buffer));
			//dlg->mProgressCtrl.SetPos(i + 1); // デッドロックの原因になる
			dlg->mCount = i + 1;
			_tprintf(_T("Read bytes : %d\n"), (i + 1) * sizeof(buffer));

			if (dlg->mRunningThread)
			{
				_tprintf(_T("Break reading file!\n"));
				break;
			}
		}
		readFile.Close();
	}
	_tprintf(_T("Finish worker thread!\n"));
	return 0;
}

// private
void WaitThreadDlg::ThreadPattern_NoWait()
{
	mRunningThread = false;
	CFileStatus fileStatus;
	if (CFile::GetStatus(mFileName, fileStatus))
	{
		mProgressCtrl.SetRange32(0, (int)(fileStatus.m_size / BUFFER_SIZE) + 1);
		mButtonStart.EnableWindow(false);
		mButtonStop.EnableWindow(true);
		CWinThread* thread = AfxBeginThread(ThreadReadFile_ver1_with_gui_process, this);
	}
}

// private
void WaitThreadDlg::ThreadPattern_Wait()
{
	mRunningThread = false;
	CFileStatus fileStatus;
	if (CFile::GetStatus(mFileName, fileStatus))
	{
		mProgressCtrl.SetRange32(0, (int)(fileStatus.m_size / BUFFER_SIZE) + 1);
		mButtonStart.EnableWindow(false);
		mButtonStop.EnableWindow(true);
		//CWinThread* thread = AfxBeginThread(ThreadReadFile_ver1, this);

		CWinThread* thread = AfxBeginThread(ThreadReadFile_ver2_without_gui_process,
											this,
											THREAD_PRIORITY_NORMAL,
											0, // stack size
											0  // no_suspend or suspend
											);
		mButtonStart.EnableWindow(true);
		mButtonStop.EnableWindow(false);

		// メインスレッド側で待機
		WaitForSingleObject(thread->m_hThread, INFINITE);
		_tprintf(_T("Pass WaitForSingleObject in main therad.\n"));
	}
}

// private
void WaitThreadDlg::ThreadPattern_Peek()
{
	mRunningThread = false;
	CFileStatus fileStatus;
	if (CFile::GetStatus(mFileName, fileStatus))
	{
		mProgressCtrl.SetRange32(0, (int)(fileStatus.m_size / BUFFER_SIZE) + 1);
		mButtonStart.EnableWindow(false);
		mButtonStop.EnableWindow(true);
		//CWinThread* thread = AfxBeginThread(ThreadReadFile_ver1, this);

		mThread = AfxBeginThread(ThreadReadFile_ver2_without_gui_process,
			this,
			THREAD_PRIORITY_NORMAL,
			0, // stack size
			CREATE_SUSPENDED  // no_suspend or suspend
		);
		/*mButtonStart.EnableWindow(true);
		mButtonStop.EnableWindow(false);*/

		_tprintf(_T("Suspend thread.\n"));

		mThread->m_bAutoDelete = false; // 自動破棄されないように
		mThread->ResumeThread();

		_tprintf(_T("Restart thread.\n"));

		mTimerID = 1;
		CWnd::SetTimer(mTimerID, 50/*[ms]*/, NULL); // WaitThreadDlg宛て送信されるタイムアウトメッセージをOnTimer()ハンドラで取得する
		_tprintf(_T("Set peek timer for thread.\n"));
	}
}


void WaitThreadDlg::OnBnClickedButtonWaitthreaddlgStart()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	CWnd::UpdateData(true);
	if (mPeekThread)
	{
		ThreadPattern_Peek();
	}
	else
	{
		//NoThreadPattern();
		//ThreadPattern_NoWait();
		ThreadPattern_Wait();
	}
}


void WaitThreadDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	DWORD result = WaitForSingleObject(mThread->m_hThread, 0); // 一瞬覗き見る(Peek)
	_tprintf(_T("Peek thread in OnTimer!\n"));
	mProgressCtrl.SetPos(mCount);
	if (result == WAIT_ABANDONED || result == WAIT_OBJECT_0)
	{
		CWnd::KillTimer(mTimerID);
		mButtonStart.EnableWindow(true);
		mButtonStop.EnableWindow(false);
		delete mThread;
		mThread = nullptr;
		_tprintf(_T("Stop thread in OnTimer.\n"));
	}

	BaseMFCDialog::OnTimer(nIDEvent);
}
