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

BaseMFCDialog::BaseMFCDialog(int idd, CWnd* pParent /*=nullptr*/)
	: CDialogEx(idd, pParent)
	, mDeleteThisOnNcDestroy(true)
	, mValidParent(false)
	, mParent(pParent)
{
	if (dynamic_cast<CMainFrame*>(mParent))
	{
		mValidParent = true;
		CMainFrame* parent = dynamic_cast<CMainFrame*>(mParent);
		parent->AddDialog(this);
	}
	else if (dynamic_cast<BaseMFCDialog*>(mParent))
	{
		mValidParent = true;
		BaseMFCDialog* parent = dynamic_cast<BaseMFCDialog*>(mParent);
		parent->AddDialog(this);
	}
	else
	{
		throw std::exception("Not match parent type. Please valid type.");
	}
}

BaseMFCDialog::~BaseMFCDialog()
{
	// 先に子を削除
	for (auto ptr : mChildDlgs)
	{
		// PostNcDestroy()関数で自分自身を消去するオブジェクトは解放しない
		if (!ptr->IsDeleteThisOnNcDestroy())
		{
			delete ptr;
			ptr = nullptr;
		}
		else
		{
			ptr->SetValidParent(false);
		}
	}
	mChildDlgs.clear();

	// 自身を親から登録解除
	if (mValidParent)
	{
		if (dynamic_cast<CMainFrame*>(mParent))
		{
			CMainFrame* parent = dynamic_cast<CMainFrame*>(mParent);
			parent->RemoveDialog(this);
		}
		else if (dynamic_cast<BaseMFCDialog*>(mParent))
		{
			BaseMFCDialog* parent = dynamic_cast<BaseMFCDialog*>(mParent);
			parent->RemoveDialog(this);
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
	_tprintf(_T("Add BaseMFCDialog Before mChildDlgs size: %d\n"), mChildDlgs.size());
	mChildDlgs.push_back(dlg);
	_tprintf(_T("Add BaseMFCDialog After mChildDlgs size: %d\n"), mChildDlgs.size());

}

void BaseMFCDialog::RemoveDialog(class BaseMFCDialog* dlg)
{
	_tprintf(_T("Remove BaseMFCDialog Before mChildDlgs size: %d\n"), mChildDlgs.size());
	auto iter = std::find(mChildDlgs.begin(), mChildDlgs.end(), dlg);
	if (iter != mChildDlgs.end())
	{
		std::iter_swap(iter, mChildDlgs.end() - 1);
		mChildDlgs.pop_back();
	}
	_tprintf(_T("Remove BaseMFCDialog After mChildDlgs size: %d\n"), mChildDlgs.size());
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
