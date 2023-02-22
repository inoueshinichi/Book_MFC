// BaseDialog.cpp : 実装ファイル
//

#include "pch.h"
#include "SampleMFC.h"
#include "BaseMFCDialog.h"
#include "afxdialogex.h"

#include "MainFrm.h"

#include <exception>


// BaseMFCDialog ダイアログ

IMPLEMENT_DYNAMIC(BaseMFCDialog, CDialogEx)

BaseMFCDialog::BaseMFCDialog(int idd, CWnd* pOwner /*=nullptr*/)
	: CDialogEx(idd, nullptr)
	, mDeleteThisOnNcDestroy(true)
	, mValidOwner(false)
	, mOwner(pOwner)
{
	if (dynamic_cast<CMainFrame*>(mOwner))
	{
		mValidOwner = true;
		CMainFrame* owner = dynamic_cast<CMainFrame*>(mOwner);
		CWnd::SetOwner(owner);
		owner->AddDialog(this);
	}
	else if (dynamic_cast<BaseMFCDialog*>(mOwner))
	{
		mValidOwner = true;
		BaseMFCDialog* owner = dynamic_cast<BaseMFCDialog*>(mOwner);
		CWnd::SetOwner(owner);
		owner->AddDialog(this);
	}
	else
	{
		throw std::exception("Not match parent type. Please valid type.");
	}
}

BaseMFCDialog::~BaseMFCDialog()
{
	// 先に雇用側を削除
	for (auto ptr : mEmployeeDlgs)
	{
		// PostNcDestroy()関数で自分自身を消去するオブジェクトは解放しない
		if (!ptr->IsDeleteThisOnNcDestroy())
		{
			delete ptr;
			ptr = nullptr;
		}
		else
		{
			ptr->SetValidOwner(false);
		}
	}
	mEmployeeDlgs.clear();

	// 自身を所有者から登録解除
	if (mValidOwner)
	{
		if (dynamic_cast<CMainFrame*>(mOwner))
		{
			CMainFrame* owner = dynamic_cast<CMainFrame*>(mOwner);
			owner->RemoveDialog(this);
		}
		else if (dynamic_cast<BaseMFCDialog*>(mOwner))
		{
			BaseMFCDialog* owner = dynamic_cast<BaseMFCDialog*>(mOwner);
			owner->RemoveDialog(this);
		}
		
	}
}

void BaseMFCDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

/*自作関数*/
void BaseMFCDialog::AddDialog(class BaseMFCDialog* dlg)
{
	_tprintf(_T("Add BaseMFCDialog Before mEmployeeDlgs size: %d\n"), mEmployeeDlgs.size());
	mEmployeeDlgs.push_back(dlg);
	_tprintf(_T("Add BaseMFCDialog After mEmployeeDlgs size: %d\n"), mEmployeeDlgs.size());

}

void BaseMFCDialog::RemoveDialog(class BaseMFCDialog* dlg)
{
	_tprintf(_T("Remove BaseMFCDialog Before mEmployeeDlgs size: %d\n"), mEmployeeDlgs.size());
	auto iter = std::find(mEmployeeDlgs.begin(), mEmployeeDlgs.end(), dlg);
	if (iter != mEmployeeDlgs.end())
	{
		std::iter_swap(iter, mEmployeeDlgs.end() - 1);
		mEmployeeDlgs.pop_back();
	}
	_tprintf(_T("Remove BaseMFCDialog After mEmployeeDlgs size: %d\n"), mEmployeeDlgs.size());
}


BEGIN_MESSAGE_MAP(BaseMFCDialog, CDialogEx)
END_MESSAGE_MAP()


// BaseDialog メッセージ ハンドラー


void BaseMFCDialog::PostNcDestroy()
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。
	if (mDeleteThisOnNcDestroy)
	{
		delete this;
	}

	CDialogEx::PostNcDestroy();
}


BOOL BaseMFCDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: ここに初期化を追加してください

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 例外 : OCX プロパティ ページは必ず FALSE を返します。
}


void BaseMFCDialog::OnOK()
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。

	Default();
	//CDialogEx::OnOK();
}


void BaseMFCDialog::OnCancel()
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。

	DestroyWindow();
	//CDialogEx::OnCancel();
}
