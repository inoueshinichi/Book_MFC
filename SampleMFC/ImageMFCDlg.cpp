// ImageMFCDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "SampleMFC.h"
#include "ImageMFCDlg.h"
#include "afxdialogex.h"

#include "SampleMFCDlg.h"

// ImageMFCDlg ダイアログ

IMPLEMENT_DYNAMIC(ImageMFCDlg, BaseMFCDialog)

ImageMFCDlg::ImageMFCDlg(CWnd* pParent /*=nullptr*/)
	: BaseMFCDialog(IDD_ImageMFCDlg, pParent)
	, mSampleDlg(nullptr)
	, mDynamicLayout(nullptr)
{
	// 動的レイアウトの設定
	// https://learn.microsoft.com/ja-jp/cpp/mfc/dynamic-layout?view=msvc-170

	// ダイアログ内部のコントロールの移動設定
	mDynamicLayout = this->GetDynamicLayout();

	// ImageMFCDlg自身を動的レイアウトにする
	this->EnableDynamicLayout(true);
}

ImageMFCDlg::~ImageMFCDlg()
{
	if (mDynamicLayout)
	{
		delete mDynamicLayout;
	}
}

void ImageMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	BaseMFCDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ImageMFCDlg, BaseMFCDialog)
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


	Invalidate();
	UpdateWindow(); // notify OnPaint()
}


BOOL ImageMFCDlg::OnInitDialog()
{
	BaseMFCDialog::OnInitDialog();

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
