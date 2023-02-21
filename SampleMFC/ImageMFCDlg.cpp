// ImageMFCDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "SampleMFC.h"
#include "ImageMFCDlg.h"
#include "afxdialogex.h"

#include "SampleMFCDlg.h"

// ImageMFCDlg ダイアログ

IMPLEMENT_DYNAMIC(ImageMFCDlg, CDialogEx)

ImageMFCDlg::ImageMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ImageMFCDlg, pParent)
	, mValidParent(false)
	, mSampleDlg(nullptr)
	, mDeleteThisOnNcDestroy(true)
	, mDynamicLayout(nullptr)
{
	if (dynamic_cast<SampleMFCDlg*>(pParent))
	{
		mValidParent = true;
		mSampleDlg = dynamic_cast<SampleMFCDlg*>(pParent);
		mSampleDlg->AddDialog(this);
	}
	else
	{
		mValidParent = false;
		mSampleDlg = nullptr;
	}

	// 動的レイアウトの設定
	// https://learn.microsoft.com/ja-jp/cpp/mfc/dynamic-layout?view=msvc-170

	// ダイアログ内部のコントロールの移動設定
	mDynamicLayout = this->GetDynamicLayout();

	// ImageMFCDlg自身を動的レイアウトにする
	this->EnableDynamicLayout(true);
}

ImageMFCDlg::~ImageMFCDlg()
{
	if (mValidParent && !mDeleteThisOnNcDestroy)
	{
		mSampleDlg->RemoveDialog(this);
	}

	if (mDynamicLayout)
	{
		delete mDynamicLayout;
	}
}

void ImageMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ImageMFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_CREATE()
END_MESSAGE_MAP()


// ImageMFCDlg メッセージ ハンドラー


void ImageMFCDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: ここにメッセージ ハンドラー コードを追加します。
					   // 描画メッセージで CDialogEx::OnPaint() を呼び出さないでください。

	CRect rect;
	GetClientRect(&rect);
	dc.SetStretchBltMode(COLORONCOLOR); // HALFTONE);// BLACKONWHITE);// 
	mImage.StretchBlt(dc, rect);
}


void ImageMFCDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: ここにメッセージ ハンドラー コードを追加します。


	CWnd::Invalidate();
	CWnd::UpdateWindow(); // notify OnPaint()
}


BOOL ImageMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: ここに初期化を追加してください


	/*ファイルダイアログ*/
	CString imgFilter = _T("BMP(*.bmp)|*.bmp|JPEG(*.jpg)|*jgp|GIF(*gif)|*gif||");
	CFileDialog imgLoadDlg(true, NULL, NULL, NULL, imgFilter);
	if (imgLoadDlg.DoModal() == IDOK)
	{
		mImage.Load(imgLoadDlg.GetPathName());
	}

	/*ダイアログコントロールの動的レイアウト*/

	// MoveHorizontal, MoveVertical, MoveHorizontalAndVertical, MoveNone
	// 100にするとダイアログの移動と同じ成分だけ内部コントロールが移動する
	CMFCDynamicLayout::MoveSettings moveSettings = CMFCDynamicLayout::MoveHorizontalAndVertical(100, 100);

	// ダイアログ内部のコントロールのサイズの設定
	// SizeVertical, SizeHorizontal, SizeHorizontalAndVertical, SizeNone
	CMFCDynamicLayout::SizeSettings sizeSettings = CMFCDynamicLayout::SizeNone();

	// DynamicMoveボタンだけを動的レイアウトの対象にしてみる
	CButton* button = (CButton*)this->GetDlgItem(IDC_BUTTON_DYNAMIC_MOVE);
	//CButton* button = (CButton*)::GetDlgItem(this->GetSafeHwnd(), IDC_BUTTON_DYNAMIC_MOVE);

	button->SetWindowText(_T("Move?"));

	//if (button)
	//{
	//	mDynamicLayout->AddItem(/*コントロールのhWnd*/button->GetSafeHwnd(), moveSettings, sizeSettings);
	//}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 例外 : OCX プロパティ ページは必ず FALSE を返します。
}


void ImageMFCDlg::PostNcDestroy()
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。

	// UI消滅時に所属するオブジェクト(自身)を消す.
	if (mValidParent && mDeleteThisOnNcDestroy)
	{
		mSampleDlg->RemoveDialog(this);
		delete this;
	}
	

	CDialogEx::PostNcDestroy();
}


void ImageMFCDlg::OnOK()
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。

	Default(); // なにもしない
	//CDialogEx::OnOK();
}


void ImageMFCDlg::OnCancel()
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。

	DestroyWindow(); // 自身のウィンドウを破棄
	//CDialogEx::OnCancel();
}


int ImageMFCDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: ここに特定な作成コードを追加してください。

	return 0;
}


BOOL ImageMFCDlg::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。

	return CDialogEx::PreCreateWindow(cs);
}
