#pragma once

#include <vector>

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
	bool mValidParent;
	class CMainFrame* mMainFrame;
	std::vector<class CDialogEx*> mMFCDlgs;

	void AddDialog(class CDialogEx* dlg);
	void RemoveDialog(class CDialogEx* dlg);

	HICON mhIcon;
	CString mEditString;
	BOOL mCheckVB;
	BOOL mCheckCSharp;
	BOOL mCheckCpp;
	//BOOL mRadioMan;
	//BOOL mRadioWoman;
	int mRadioGender;
	CComboBox mComboBoxCtrl;
	CListBox mListBoxCtrl;
	CSpinButtonCtrl mSpinButtonCtrl;
	CSliderCtrl mSliderCtrl;

	virtual BOOL OnInitDialog();
	virtual void PostNcDestroy();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonPaint();
	afx_msg void OnBnClickedButtonApply();
	/*afx_msg void OnBnClickedRadioMan();
	afx_msg void OnBnClickedRadioWoman();*/
	afx_msg void OnBnClickedButtonFile();
	afx_msg void OnBnClickedButtonDatetime();
	afx_msg void OnBnClickedButtonImage();
	
	
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnEnUpdateEditSpin();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	
};
