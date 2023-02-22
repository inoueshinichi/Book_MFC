#pragma once
#include "pch.h"

#include <vector>



// BaseMFCDialog ダイアログ

class BaseMFCDialog : public CDialogEx
{
	DECLARE_DYNAMIC(BaseMFCDialog)

public:
	BaseMFCDialog(int idd, CWnd* pOwner = nullptr);   // 標準コンストラクター
	virtual ~BaseMFCDialog();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BaseMFCDialog };
#endif

private:
	
protected:
	bool mDeleteThisOnNcDestroy;
	bool mValidOwner;
	CWnd* mOwner;
	std::vector<BaseMFCDialog*> mEmployeeDlgs;

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

	void SetValidOwner(bool flag)
	{
		mValidOwner = flag;
	}

	virtual BOOL OnInitDialog();
	virtual void OnOK() override final;
	virtual void OnCancel() override final;
};
