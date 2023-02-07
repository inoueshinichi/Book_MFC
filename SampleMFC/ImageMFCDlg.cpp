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
}

ImageMFCDlg::~ImageMFCDlg()
{
	if (mValidParent)
	{
		mSampleDlg->RemoveDialog(this);
	}
}

void ImageMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ImageMFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// ImageMFCDlg メッセージ ハンドラー


void ImageMFCDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: ここにメッセージ ハンドラー コードを追加します。
					   // 描画メッセージで CDialogEx::OnPaint() を呼び出さないでください。

	CRect rect;
	GetClientRect(&rect);
	dc.SetStretchBltMode(HALFTONE);// BLACKONWHITE);// COLORONCOLOR);
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
	CDialogEx::OnInitDialog();

	// TODO: ここに初期化を追加してください

	CString imgFilter = _T("BMP(*.bmp)|*.bmp|JPEG(*.jpg)|*jgp|GIF(*gif)|*gif||");
	CFileDialog imgLoadDlg(true, NULL, NULL, NULL, imgFilter);
	if (imgLoadDlg.DoModal() == IDOK)
	{
		mImage.Load(imgLoadDlg.GetPathName());
	}


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 例外 : OCX プロパティ ページは必ず FALSE を返します。
}


void ImageMFCDlg::PostNcDestroy()
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。

	// UI消滅時に所属するオブジェクト(自身)を消す.
	delete this;

	CDialogEx::PostNcDestroy();
}
