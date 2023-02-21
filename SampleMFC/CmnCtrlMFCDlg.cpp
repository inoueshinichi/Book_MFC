// CmnCtrlMFCDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "SampleMFC.h"
#include "CmnCtrlMFCDlg.h"
#include "afxdialogex.h"

#include "MainFrm.h"



// CmnCtrlMFCDlg ダイアログ

IMPLEMENT_DYNAMIC(CmnCtrlMFCDlg, CDialogEx)

CmnCtrlMFCDlg::CmnCtrlMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CmnCtrlMFCDlg, pParent)
	, mValidParent(false)
	, mDeleteThisOnNcDestroy(true)
	, mMainFrame(nullptr)
	, mTimerID(0)
{
	if (dynamic_cast<CMainFrame*>(pParent))
	{
		mValidParent = true;
		mMainFrame = dynamic_cast<CMainFrame*>(pParent);
		mMainFrame->AddDialog(this);
	}
	else
	{
		mValidParent = false;
		mMainFrame = nullptr;
	}

	// 現在時刻を取得
	//mDate = COleDateTime::GetCurrentTime();
	//mTime = COleDateTime::GetCurrentTIme();
}

CmnCtrlMFCDlg::~CmnCtrlMFCDlg()
{
	if (mValidParent && !mDeleteThisOnNcDestroy)
	{
		mMainFrame->RemoveDialog(this);
	}
}

void CmnCtrlMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_TIMER, mButtonProgressBar);
	DDX_Control(pDX, IDC_PROGRESS, mProgressCtrl);
	DDX_Control(pDX, IDC_IPADDRESS, mIPAddressCtrl);
}


BEGIN_MESSAGE_MAP(CmnCtrlMFCDlg, CDialogEx)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_SHOW_DATETIME, &CmnCtrlMFCDlg::OnBnClickedButtonShowDatetime)
	ON_BN_CLICKED(IDC_BUTTON_TIMER, &CmnCtrlMFCDlg::OnBnClickedButtonTimer)
	ON_BN_CLICKED(IDC_BUTTON_SET_IP, &CmnCtrlMFCDlg::OnBnClickedButtonSetIp)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CmnCtrlMFCDlg メッセージ ハンドラー


BOOL CmnCtrlMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: ここに初期化を追加してください

	// 日時の設定
	mDate.SetDate(2023, 2, 7);
	mTime.SetTime(11, 30, 0);

	// プログレスバーの設定
	mProgressCtrl.SetRange32(0, 100); // 4bytes
	//mProgressCtrl.SetRange(0, 100); // 2bytes

	// IPアドレスの設定
	mIPAddressCtrl.SetAddress((BYTE)192, (BYTE)168, (BYTE)11, (BYTE)20);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 例外 : OCX プロパティ ページは必ず FALSE を返します。
}

void CmnCtrlMFCDlg::PostNcDestroy()
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。

	// UI消滅時に所属するオブジェクト(自身)を消す.
	if (mValidParent && mDeleteThisOnNcDestroy)
	{
		mMainFrame->RemoveDialog(this);
		delete this;
	}
	

	CDialogEx::PostNcDestroy();
}


void CmnCtrlMFCDlg::OnOK()
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。

	Default();  // Enterキーを押しても何もしない
	//CDialogEx::OnOK();
}


void CmnCtrlMFCDlg::OnCancel()
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。

	DestroyWindow(); // 自身のウィンドウを破棄
	//CDialogEx::OnCancel();
}


int CmnCtrlMFCDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: ここに特定な作成コードを追加してください。

	return 0;
}


void CmnCtrlMFCDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	// プログレスバーの更新
	int posInt = mProgressCtrl.GetPos() + 1;
	mProgressCtrl.SetPos(posInt);
	//UpdateData(false);
	if (mProgressCtrl.GetPos() >= 100)
	{
		KillTimer(mTimerID); // タイマーの削除
	}

	_tprintf(_T("ProgressBar: %d\n"), posInt);

	CDialogEx::OnTimer(nIDEvent);
}





void CmnCtrlMFCDlg::OnBnClickedButtonShowDatetime()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	UpdateData(true);
	CString dateStr = mDate.Format(_T("%Y/%m/%d"));
	CString timeStr = mTime.Format(_T("%H:%M:%S"));
	AfxMessageBox(dateStr + _T(" ") + timeStr);
}


void CmnCtrlMFCDlg::OnBnClickedButtonTimer()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	// プログレスバーの開始
	if (mProgressCtrl.GetPos() < 100)
	{
		CString text;
		mButtonProgressBar.GetWindowText(text);
		if (text == _T("Start Timer"))
		{
			mTimerID = 1;
			SetTimer(mTimerID, 500, NULL);
			mButtonProgressBar.SetWindowText(_T("Stop Timer"));
		}
		else
		{
			KillTimer(mTimerID);
			mButtonProgressBar.SetWindowText(_T("Start Timer"));
		}
	}
}


void CmnCtrlMFCDlg::OnBnClickedButtonSetIp()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	// IP アドレスのチェック
	BYTE f0, f1, f2, f3;
	if (mIPAddressCtrl.GetAddress(f0, f1, f2, f3))
	{
		CString ipAddressStr;
		ipAddressStr.Format(_T("%d.%d.%d.%d"), f0, f1, f2, f3);
		AfxMessageBox(ipAddressStr);
	}
}


void CmnCtrlMFCDlg::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
					   // TODO: ここにメッセージ ハンドラー コードを追加します。
					   // 描画メッセージで CDialogEx::OnPaint() を呼び出さないでください。

	// CPaintDCでRTAAをしない場合
	PAINTSTRUCT ps;
	CDC* pDC = BeginPaint(&ps);

	CPen myPen;
	myPen.CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	CPen* oldPen = pDC->SelectObject(&myPen);
	pDC->MoveTo(300, 20);
	pDC->LineTo(500, 120);
	pDC->SelectObject(oldPen);

	EndPaint(&ps);
}
