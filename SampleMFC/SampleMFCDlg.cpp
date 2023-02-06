// SampleMFCDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "SampleMFC.h"
#include "SampleMFCDlg.h"
#include "afxdialogex.h"

#include "MainFrm.h"


// SampleMFCDlg ダイアログ

IMPLEMENT_DYNAMIC(SampleMFCDlg, CDialogEx)

SampleMFCDlg::SampleMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SampleMFCDlg, pParent)
	, mEditString(_T(""))
	, mCheckVB(FALSE)
	, mCheckCSharp(FALSE)
	, mCheckCpp(FALSE)
	, mValidParent(false)
	, mMainFrame(nullptr)
{
	if (dynamic_cast<CMainFrame*>(pParent))
	{
		mValidParent = true;
		mMainFrame = dynamic_cast<CMainFrame*>(pParent);
		mMainFrame->AddDialog(this);
	}
	else
	{
		mValidParent = false;
		mMainFrame = nullptr;
	}
}

SampleMFCDlg::~SampleMFCDlg()
{
	if (mValidParent)
	{
		mMainFrame->RemoveDialog(this);
	}
}

void SampleMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mEditString);
	DDX_Check(pDX, IDC_CHECK_VB, mCheckVB);
	DDX_Check(pDX, IDC_CHECK_CSHARP, mCheckCSharp);
	DDX_Check(pDX, IDC_CHECK_CPP, mCheckCpp);
}


BEGIN_MESSAGE_MAP(SampleMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &SampleMFCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_PAINT, &SampleMFCDlg::OnBnClickedButtonPaint)
	ON_BN_CLICKED(IDC_BUTTON_APPLY, &SampleMFCDlg::OnBnClickedButtonApply)
END_MESSAGE_MAP()


// SampleMFCDlg メッセージ ハンドラー


BOOL SampleMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: ここに初期化を追加してください

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 例外 : OCX プロパティ ページは必ず FALSE を返します。
}


void SampleMFCDlg::PostNcDestroy()
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。

	// UI消滅時に所属するオブジェクト(自身)を消す.
	delete this;

	CDialogEx::PostNcDestroy();
}


void SampleMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	CDialogEx::OnSysCommand(nID, lParam);
}


void SampleMFCDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: ここにメッセージ ハンドラー コードを追加します。
					   // 描画メッセージで CDialogEx::OnPaint() を呼び出さないでください。
}


HCURSOR SampleMFCDlg::OnQueryDragIcon()
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	return CDialogEx::OnQueryDragIcon();
}


void SampleMFCDlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}


void SampleMFCDlg::OnBnClickedButtonPaint()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}


void SampleMFCDlg::OnBnClickedButtonApply()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}
