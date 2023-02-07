
// MainFrm.cpp : CMainFrame クラスの実装
//

#include "pch.h"
#include "framework.h"
#include "SampleMFC.h"

#include "MainFrm.h"

#include "SampleMFCDlg.h"
#include "CmnCtrlMFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_FILE_CLOSE, &CMainFrame::OnFileClose)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ステータス ライン インジケーター
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame コンストラクション/デストラクション

CMainFrame::CMainFrame() noexcept
{
	// TODO: メンバー初期化コードをここに追加してください。
}

CMainFrame::~CMainFrame()
{
	while (!mMFCDlgs.empty())
	{
		delete mMFCDlgs.back();
	}
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("ツール バーの作成に失敗しました。\n");
		return -1;      // 作成できない場合
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("ステータス バーの作成に失敗しました。\n");
		return -1;      // 作成できない場合
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: ツール バーをドッキング可能にしない場合は、これらの 3 行を削除してください。
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return TRUE;
}

// CMainFrame の診断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame メッセージ ハンドラー


BOOL CMainFrame::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext)
{
	// 基底クラスが実際の動作を行います

	if (!CFrameWnd::LoadFrame(nIDResource, dwDefaultStyle, pParentWnd, pContext))
	{
		return FALSE;
	}

	CWinApp* pApp = AfxGetApp();
	if (pApp->m_pMainWnd == nullptr)
		pApp->m_pMainWnd = this;

	// 2 番目のウィンドウで、[ファイル] メニューの [終了] オプションを [閉じる] に置き換えます。
	if (AfxGetApp()->m_pMainWnd != this)
	{
		CMenu *pMenu = GetMenu();
		ASSERT(pMenu);
		BOOL bNameValid;
		CString strTemp;
		bNameValid = strTemp.LoadString(IDS_CLOSE);
		ASSERT(bNameValid);
		pMenu->ModifyMenu(ID_APP_EXIT, MF_BYCOMMAND | MF_STRING, ID_FILE_CLOSE, strTemp);
	}

	return TRUE;
}

void CMainFrame::OnFileClose()
{
	DestroyWindow();
}


void CMainFrame::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CFrameWnd::OnShowWindow(bShow, nStatus);

	// TODO: ここにメッセージ ハンドラー コードを追加します。

	/*SampleMFCDlgの生成*/
	SampleMFCDlg* mSampleDlg = new SampleMFCDlg(this);
	mSampleDlg->Create(IDD_SampleMFCDlg);
	mSampleDlg->ShowWindow(SW_SHOW);

	/*CmnCtrlDlgの生成*/
	CmnCtrlMFCDlg* mCmnCtrlDlg = new CmnCtrlMFCDlg(this);
	mCmnCtrlDlg->Create(IDD_CmnCtrlMFCDlg);
	mCmnCtrlDlg->ShowWindow(SW_SHOW);
}

/*以下, 自作関数*/


void CMainFrame::AddDialog(class CDialogEx* dlg)
{
	mMFCDlgs.push_back(dlg);
}

void CMainFrame::RemoveDialog(class CDialogEx* dlg)
{
	auto iter = std::find(mMFCDlgs.begin(), mMFCDlgs.end(), dlg);
	if (iter != mMFCDlgs.end())
	{
		std::iter_swap(iter, mMFCDlgs.end() - 1);
		mMFCDlgs.pop_back();
	}
}



