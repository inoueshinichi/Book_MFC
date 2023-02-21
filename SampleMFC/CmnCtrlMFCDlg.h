#pragma once


// CmnCtrlMFCDlg ダイアログ

class CmnCtrlMFCDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CmnCtrlMFCDlg)

public:
	CmnCtrlMFCDlg(CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~CmnCtrlMFCDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CmnCtrlMFCDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	bool mValidParent;
	class CMainFrame* mMainFrame;

	CMonthCalCtrl mMonthCalCtrl;
	COleDateTime mTime;
	COleDateTime mDate;
	CProgressCtrl mProgressCtrl;
	CButton mButtonProgressBar;
	int mTimerID;

	CIPAddressCtrl mIPAddressCtrl;
	
	virtual BOOL OnInitDialog();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void PostNcDestroy();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBnClickedButtonShowDatetime();
	afx_msg void OnBnClickedButtonTimer();
	afx_msg void OnBnClickedButtonSetIp();
	afx_msg void OnPaint();
	
	
};
