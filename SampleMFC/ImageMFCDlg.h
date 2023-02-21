#pragma once
#include "BaseMFCDialog.h"

// ImageMFCDlg ダイアログ

class ImageMFCDlg : public BaseMFCDialog
{
	DECLARE_DYNAMIC(ImageMFCDlg)

public:
	ImageMFCDlg(CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~ImageMFCDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ImageMFCDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	bool mDeleteThisOnNcDestroy;
	bool mValidParent;
	class SampleMFCDlg* mSampleDlg;

	CImage mImage;

	CMFCDynamicLayout* mDynamicLayout;

	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
};
