
// MainFrm.cpp : CMainFrame クラスの実装
//

#include "pch.h"
#include "framework.h"
#include "SampleMFC.h"

#include "MainFrm.h"

#include "SampleMFCDlg.h"
#include "CmnCtrlMFCDlg.h"

#include "BaseMFCDialog.h"

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
	for (auto ptr : mEmployeeDlgs)
	{
		if (!ptr->IsDeleteThisOnNcDestroy())
		{
			delete ptr;
			ptr = nullptr;
		}
		else
		{
			// PosNcDestroy()で消える所有される側のダイアログには
			// 所有者が無効になることを事前通知
			ptr->SetValidOwner(false);
		}
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

	/*SampleMFCDlgの生成*/
	SampleMFCDlg* mSampleDlg = new SampleMFCDlg(this);
	mSampleDlg->Create(IDD_SampleMFCDlg);
	mSampleDlg->ShowWindow(SW_SHOW);

	/*CmnCtrlDlgの生成*/
	CmnCtrlMFCDlg* mCmnCtrlDlg = new CmnCtrlMFCDlg(this);
	mCmnCtrlDlg->Create(IDD_CmnCtrlMFCDlg);
	mCmnCtrlDlg->ShowWindow(SW_SHOW);

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

	
}

/*以下, 自作関数*/


void CMainFrame::AddDialog(BaseMFCDialog* dlg)
{
	_tprintf(_T("Add CMainFrame Before mEmployeeDlgs size: %d\n"), mEmployeeDlgs.size());
	mEmployeeDlgs.push_back(dlg);
	_tprintf(_T("Add CMainFrame After mEmployeeDlgs size: %d\n"), mEmployeeDlgs.size());
}

void CMainFrame::RemoveDialog(BaseMFCDialog* dlg)
{
	_tprintf(_T("Remove CMainFrame Before mEmployeeDlgs size: %d\n"), mEmployeeDlgs.size());
	auto iter = std::find(mEmployeeDlgs.begin(), mEmployeeDlgs.end(), dlg);
	if (iter != mEmployeeDlgs.end())
	{
		std::iter_swap(iter, mEmployeeDlgs.end() - 1);
		mEmployeeDlgs.pop_back();
	}
	_tprintf(_T("Remove CMainFrame After mEmployeeDlgs size: %d\n"), mEmployeeDlgs.size());
}



