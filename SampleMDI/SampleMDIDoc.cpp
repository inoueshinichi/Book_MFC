
// SampleMDIDoc.cpp : CSampleMDIDoc クラスの実装
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS は、プレビュー、縮小版、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "SampleMDI.h"
#endif

#include "SampleMDIDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSampleMDIDoc

IMPLEMENT_DYNCREATE(CSampleMDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CSampleMDIDoc, CDocument)
END_MESSAGE_MAP()


// CSampleMDIDoc コンストラクション/デストラクション

CSampleMDIDoc::CSampleMDIDoc() noexcept
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CSampleMDIDoc::~CSampleMDIDoc()
{
}

BOOL CSampleMDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。

	return TRUE;
}




// CSampleMDIDoc のシリアル化

void CSampleMDIDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 格納するコードをここに追加してください。
	}
	else
	{
		// TODO: 読み込むコードをここに追加してください。
	}
}

#ifdef SHARED_HANDLERS

//縮小版のサポート
void CSampleMDIDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// このコードを変更してドキュメントのデータを描画します
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 検索ハンドラーのサポート
void CSampleMDIDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ドキュメントのデータから検索コンテンツを設定します。
	// コンテンツの各部分は ";" で区切る必要があります

	// 例:      strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CSampleMDIDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CSampleMDIDoc の診断

#ifdef _DEBUG
void CSampleMDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSampleMDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSampleMDIDoc コマンド


BOOL CSampleMDIDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO: ここに特定な作成コードを追加してください。

	// 画像読み込み
	mImage.Load(lpszPathName);

	return TRUE;
}
