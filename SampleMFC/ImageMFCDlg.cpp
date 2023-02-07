// ImageMFCDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "SampleMFC.h"
#include "ImageMFCDlg.h"
#include "afxdialogex.h"


// ImageMFCDlg ダイアログ

IMPLEMENT_DYNAMIC(ImageMFCDlg, CDialogEx)

ImageMFCDlg::ImageMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ImageMFCDlg, pParent)
{

}

ImageMFCDlg::~ImageMFCDlg()
{
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
}


void ImageMFCDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: ここにメッセージ ハンドラー コードを追加します。
}


BOOL ImageMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: ここに初期化を追加してください

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 例外 : OCX プロパティ ページは必ず FALSE を返します。
}


void ImageMFCDlg::PostNcDestroy()
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。

	CDialogEx::PostNcDestroy();
}
