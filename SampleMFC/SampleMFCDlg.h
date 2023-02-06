#pragma once


// SampleMFCDlg ダイアログ

class SampleMFCDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SampleMFCDlg)

public:
	SampleMFCDlg(CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~SampleMFCDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SampleMFCDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual void PostNcDestroy();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonPaint();
	afx_msg void OnBnClickedButtonApply();
	CString mEditString;
	BOOL mCheckVB;
	BOOL mCheckCSharp;
	BOOL mCheckCpp;
	bool mValidParent;
	class CMainFrame* mMainFrame;
	
};
