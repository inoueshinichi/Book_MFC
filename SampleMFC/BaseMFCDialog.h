#pragma once
#include "pch.h"

#include <vector>



// BaseMFCDialog ダイアログ

class BaseMFCDialog : public CDialogEx
{
	DECLARE_DYNAMIC(BaseMFCDialog)

public:
	BaseMFCDialog(int idd, CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~BaseMFCDialog();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BaseMFCDialog };
#endif

private:
	
protected:
	bool mDeleteThisOnNcDestroy;
	bool mValidParent;
	CWnd* mParent;
	std::vector<BaseMFCDialog*> mChildDlgs;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy() override final;
public:
	void AddDialog(BaseMFCDialog* dlg);
	void RemoveDialog(BaseMFCDialog* dlg);

	bool IsDeleteThisOnNcDestroy() const 
	{
		return mDeleteThisOnNcDestroy;
	}

	void SetValidParent(bool flag)
	{
		mValidParent = flag;
	}

	virtual BOOL OnInitDialog();
	virtual void OnOK() override final;
	virtual void OnCancel() override final;
};
