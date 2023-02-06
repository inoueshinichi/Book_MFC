
// SampleMFCView.cpp : CSampleMFCView クラスの実装
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS は、プレビュー、縮小版、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "SampleMFC.h"
#endif

#include "SampleMFCDoc.h"
#include "SampleMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSampleMFCView

IMPLEMENT_DYNCREATE(CSampleMFCView, CView)

BEGIN_MESSAGE_MAP(CSampleMFCView, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSampleMFCView コンストラクション/デストラクション

CSampleMFCView::CSampleMFCView() noexcept
{
	// TODO: 構築コードをここに追加します。

}

CSampleMFCView::~CSampleMFCView()
{
}

BOOL CSampleMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CSampleMFCView 描画

void CSampleMFCView::OnDraw(CDC* /*pDC*/)
{
	CSampleMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}


// CSampleMFCView の印刷

BOOL CSampleMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CSampleMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CSampleMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CSampleMFCView の診断

#ifdef _DEBUG
void CSampleMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CSampleMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSampleMFCDoc* CSampleMFCView::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSampleMFCDoc)));
	return (CSampleMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CSampleMFCView メッセージ ハンドラー
