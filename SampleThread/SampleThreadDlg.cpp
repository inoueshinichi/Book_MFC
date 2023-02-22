
// SampleThreadDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "SampleThread.h"
#include "SampleThreadDlg.h"
#include "afxdialogex.h"

#include "WaitThreadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSampleThreadDlg ダイアログ



CSampleThreadDlg::CSampleThreadDlg(CWnd* /*pParent*/pOwner /*=nullptr*/)
	: BaseMFCDialog(IDD_SAMPLETHREAD_DIALOG, /*pParent*/pOwner)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CSampleThreadDlg::~CSampleThreadDlg()
{
	_tprintf(_T("Dest CSampleThreadDlg\n"));
}

void CSampleThreadDlg::DoDataExchange(CDataExchange* pDX)
{
	BaseMFCDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSampleThreadDlg, BaseMFCDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_WAIT_THREAD, &CSampleThreadDlg::OnBnClickedButtonWaitThread)
	ON_BN_CLICKED(IDC_BUTTON_PEEK_THREAD, &CSampleThreadDlg::OnBnClickedButtonPeekThread)
	ON_BN_CLICKED(IDC_BUTTON_SEMAPHORE, &CSampleThreadDlg::OnBnClickedButtonSemaphore)
	ON_BN_CLICKED(IDC_BUTTON_MUTEX, &CSampleThreadDlg::OnBnClickedButtonMutex)
	ON_BN_CLICKED(IDC_BUTTON_CRITICAL_SECTION, &CSampleThreadDlg::OnBnClickedButtonCriticalSection)
	ON_BN_CLICKED(IDC_BUTTON_EVENT, &CSampleThreadDlg::OnBnClickedButtonEvent)
END_MESSAGE_MAP()


// CSampleThreadDlg メッセージ ハンドラー

BOOL CSampleThreadDlg::OnInitDialog()
{
	BaseMFCDialog::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CSampleThreadDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		BaseMFCDialog::OnSysCommand(nID, lParam);
	}
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CSampleThreadDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		BaseMFCDialog::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CSampleThreadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSampleThreadDlg::OnBnClickedButtonWaitThread()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	WaitThreadDlg* waitThreadDlg = new WaitThreadDlg(this);
	waitThreadDlg->Create(IDD_WaitThreadDlg);
	waitThreadDlg->ShowWindow(SW_SHOW);
}


void CSampleThreadDlg::OnBnClickedButtonPeekThread()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}


void CSampleThreadDlg::OnBnClickedButtonSemaphore()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}


void CSampleThreadDlg::OnBnClickedButtonMutex()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}


void CSampleThreadDlg::OnBnClickedButtonCriticalSection()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}


void CSampleThreadDlg::OnBnClickedButtonEvent()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}
