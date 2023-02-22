
// SampleMDIView.cpp : CSampleMDIView クラスの実装
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS は、プレビュー、縮小版、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "SampleMDI.h"
#endif

#include "SampleMDIDoc.h"
#include "SampleMDIView.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSampleMDIView

IMPLEMENT_DYNCREATE(CSampleMDIView, /*CView*/CScrollView)

BEGIN_MESSAGE_MAP(CSampleMDIView, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &/*CView*/CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &/*CView*/CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSampleMDIView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_WM_MOUSEHWHEEL()
	ON_WM_MOUSEWHEEL()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CSampleMDIView コンストラクション/デストラクション

CSampleMDIView::CSampleMDIView() noexcept
	: mViewportFitMode(false)
	, mMouseButtonL(false)
	, mMouseButtonR(false)
{
	// TODO: 構築コードをここに追加します。

}

CSampleMDIView::~CSampleMDIView()
{
}

BOOL CSampleMDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return /*CView*/CScrollView::PreCreateWindow(cs);
}

// CSampleMDIView 描画

void CSampleMDIView::OnDraw(CDC* pDC)
{
	CSampleMDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。


	/////////////////////////////////////////
	/*           ↓ここから描画処理↓          */
	/////////////////////////////////////////

	if (!pDoc->mImage.IsNull())
	{
		/*ダブルバッファリング*/
	    // https://hf-labo.net/mfc-gdi-double-buffering/
		CDC memDC;      // 仮想デバイスコンテキスト
		CBitmap memBmp; // 仮想デバイスコンテキスト用ビットマップ
		CBrush memBrush;                     // 背景色
		memDC.CreateCompatibleDC(pDC);       // 仮想デバイスコンテキストの生成
		int width = pDoc->mImage.GetWidth();
		int height = pDoc->mImage.GetHeight();
		memBmp.CreateCompatibleBitmap(pDC, width, height); // 仮想Bitmap
		memDC.SelectObject(&memBmp);
		memBrush.CreateSolidBrush(WHITE_BRUSH);      // 背景色の作成
		memDC.PatBlt(0, 0, width, height, PATCOPY);  // 仮想Bitmapに背景を設定

		pDoc->mImage.Draw(memDC.m_hDC, 0, 0);

		// 仮想デバイスコンテキストを実デバイスコンテキストに貼り付け
		pDC->BitBlt(0, 0, width, height, &memDC, 0, 0, SRCCOPY);

		//// 破棄
		memDC.DeleteDC();
		memBmp.DeleteObject();
	}

	//////////////////////////////////////////
	/*           ↑ここまで描画処理↑           */
	//////////////////////////////////////////

}


// CSampleMDIView の印刷


void CSampleMDIView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSampleMDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CSampleMDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CSampleMDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}



void CSampleMDIView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSampleMDIView の診断

#ifdef _DEBUG
void CSampleMDIView::AssertValid() const
{
	/*CView*/CScrollView::AssertValid();
}

void CSampleMDIView::Dump(CDumpContext& dc) const
{
	/*CView*/CScrollView::Dump(dc);
}

CSampleMDIDoc* CSampleMDIView::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSampleMDIDoc)));
	return (CSampleMDIDoc*)m_pDocument;
}
#endif //_DEBUG


// CSampleMDIView メッセージ ハンドラー


void CSampleMDIView::OnInitialUpdate()
{
	/*CView*/CScrollView::OnInitialUpdate();

	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。

	CSampleMDIDoc* pDoc = GetDocument();
	if (!pDoc->mImage.IsNull())
	{
		mViewSize.cx = pDoc->mImage.GetWidth();
		mViewSize.cy = pDoc->mImage.GetHeight();
		SetScrollSizes(MM_TEXT, mViewSize);
	}
	else
	{
		CWnd* ownerFrame = CWnd::GetOwner();
		if (dynamic_cast<CChildFrame*>(ownerFrame))
		{
			CRect ownerClientRect;
			dynamic_cast<CChildFrame*>(ownerFrame)->GetClientRect(&ownerClientRect);
			mViewSize.cx = ownerClientRect.Width();
			mViewSize.cy = ownerClientRect.Height();
		}
		else
		{
			mViewSize.cx = 0;
			mViewSize.cy = 0;
		}
	}
	SetScrollSizes(MM_TEXT, mViewSize);
	

	mViewportFitMode = true;
	if (mViewportFitMode)
	{
		ResizeParentToFit(); // 親フレームサイズをビューサイズに合わせる
	}
}


void CSampleMDIView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	CScrollView::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CSampleMDIView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	CScrollView::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CSampleMDIView::OnMouseHWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// この機能には Windows Vista 以降のバージョンが必要です。
	// シンボル _WIN32_WINNT は >= 0x0600 にする必要があります。
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	CScrollView::OnMouseHWheel(nFlags, zDelta, pt);
}


BOOL CSampleMDIView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	return CScrollView::OnMouseWheel(nFlags, zDelta, pt);
}


void CSampleMDIView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	// スクロール考慮マウス位置(原点はビュー左上隅)
	mScrolledMousePoint = point + mScrollValue;

	if (mMouseButtonL)
	{
		// 左ドラッグ中
		_tprintf(_T("Left Mouse Button Drag!\n"));
	}

	if (mMouseButtonR)
	{
		// 右ドラッグ中
		_tprintf(_T("Right Mouse Button Drag!\n"));
	}

	CScrollView::OnMouseMove(nFlags, point);
}


void CSampleMDIView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	mMouseButtonR = true;

	InvalidateRect(NULL, false);

	CScrollView::OnRButtonDown(nFlags, point);
}


void CSampleMDIView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{

	mMouseButtonR = false;

	InvalidateRect(NULL, false);

	ClientToScreen(&point);
	OnContextMenu(this, point);
}


void CSampleMDIView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	mMouseButtonL = true;

	InvalidateRect(NULL, false);

	CScrollView::OnLButtonDown(nFlags, point);
}


void CSampleMDIView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	mMouseButtonL = false;

	InvalidateRect(NULL, false);

	CScrollView::OnLButtonUp(nFlags, point);
}


void CSampleMDIView::OnSize(UINT nType, int cx, int cy)
{
	CScrollView::OnSize(nType, cx, cy);

	// TODO: ここにメッセージ ハンドラー コードを追加します。

	InvalidateRect(NULL, false);
}
