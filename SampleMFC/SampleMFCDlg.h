#pragma once
#include "BaseMFCDialog.h"

// SampleMFCDlg ダイアログ

class SampleMFCDlg : public BaseMFCDialog
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
	HICON mhIcon;
	CString mEditString;
	BOOL mCheckVB;
	BOOL mCheckCSharp;
	BOOL mCheckCpp;
	int mRadioGender;
	CComboBox mComboBoxCtrl;
	CListBox mListBoxCtrl;
	CSpinButtonCtrl mSpinButtonCtrl;
	CSliderCtrl mSliderCtrl;

	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonPaint();
	afx_msg void OnBnClickedButtonApply();
	
	afx_msg void OnBnClickedButtonFile();
	afx_msg void OnBnClickedButtonDatetime();
	afx_msg void OnBnClickedButtonImage();
	
	
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnEnUpdateEditSpin();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	
};
