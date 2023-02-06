
// SampleMFCView.h : CSampleMFCView クラスのインターフェイス
//

#pragma once


class CSampleMFCView : public CView
{
protected: // シリアル化からのみ作成します。
	CSampleMFCView() noexcept;
	DECLARE_DYNCREATE(CSampleMFCView)

// 属性
public:
	CSampleMFCDoc* GetDocument() const;

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
	virtual ~CSampleMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // SampleMFCView.cpp のデバッグ バージョン
inline CSampleMFCDoc* CSampleMFCView::GetDocument() const
   { return reinterpret_cast<CSampleMFCDoc*>(m_pDocument); }
#endif

