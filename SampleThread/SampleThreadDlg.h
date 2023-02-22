
// SampleThreadDlg.h : ヘッダー ファイル
//

#pragma once

#include "BaseMFCDialog.h"


// CSampleThreadDlg ダイアログ
class CSampleThreadDlg : public /*CDialogEx*/BaseMFCDialog
{
// コンストラクション
public:
	CSampleThreadDlg(CWnd* /*pParent*/pOwner = nullptr);	// 標準コンストラクター
	~CSampleThreadDlg();

	// コンソール(g)
	is::common::win32::Win32Console mConsole;

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SAMPLETHREAD_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート

// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonWaitThread();
	afx_msg void OnBnClickedButtonPeekThread();
	afx_msg void OnBnClickedButtonSemaphore();
	afx_msg void OnBnClickedButtonMutex();
	afx_msg void OnBnClickedButtonCriticalSection();
	afx_msg void OnBnClickedButtonEvent();
};
