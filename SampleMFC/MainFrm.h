
// MainFrm.h : CMainFrame クラスのインターフェイス
//

#pragma once

#include "Win32Console.h"

#include <vector>

class CMainFrame : public CFrameWnd
{
	
protected: // シリアル化からのみ作成します。
	CMainFrame() noexcept;
	DECLARE_DYNCREATE(CMainFrame)

// 属性
public:
	std::vector<class CDialogEx*> mMFCDlgs;
	is::common::win32::Win32Console mConsole;

// 操作
public:
	void AddDialog(class CDialogEx* dlg);
	void RemoveDialog(class CDialogEx* dlg);

// オーバーライド
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = nullptr, CCreateContext* pContext = nullptr);

// 実装
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // コントロール バー用メンバー
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// 生成された、メッセージ割り当て関数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnFileClose();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};


