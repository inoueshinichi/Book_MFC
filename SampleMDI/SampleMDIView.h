
// SampleMDIView.h : CSampleMDIView クラスのインターフェイス
//

#pragma once


class CSampleMDIView : public CView
{
protected: // シリアル化からのみ作成します。
	CSampleMDIView() noexcept;
	DECLARE_DYNCREATE(CSampleMDIView)

// 属性
public:
	CSampleMDIDoc* GetDocument() const;

// 操作
public:

// オーバーライド
public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画するためにオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 実装
public:
	virtual ~CSampleMDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // SampleMDIView.cpp のデバッグ バージョン
inline CSampleMDIDoc* CSampleMDIView::GetDocument() const
   { return reinterpret_cast<CSampleMDIDoc*>(m_pDocument); }
#endif

