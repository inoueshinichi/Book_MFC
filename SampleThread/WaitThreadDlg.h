#pragma once
#include "BaseMFCDialog.h"


class WaitThreadDlg : public BaseMFCDialog
{
	DECLARE_DYNAMIC(WaitThreadDlg)

public:
	WaitThreadDlg(CWnd* pOwner);
	virtual ~WaitThreadDlg();

	
	// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WaitThreadDlg
	};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート

public:
	CString mFileName;
	bool mRunningThread;
	int mCount;

	CProgressCtrl mProgressCtrl;
	CButton mButtonStart;
	CButton mButtonStop;
	BOOL mPeekThread;
	UINT mTimerID;
	CWinThread* mThread;

private:
	/*スレッド有り無し*/
	void NoThreadPattern(); 
	void ThreadPattern_NoWait();
	void ThreadPattern_Wait();
	void ThreadPattern_Peek();

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedButtonWaitthreaddlgFile();
	afx_msg void OnBnClickedButtonWaitthreaddlgStop();
	afx_msg void OnBnClickedButtonWaitthreaddlgStart();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

