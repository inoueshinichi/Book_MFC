
// SampleMFC.h : SampleMFC アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CSampleMFCApp:
// このクラスの実装については、SampleMFC.cpp を参照してください
//

class CSampleMFCApp : public CWinApp
{
public:
	CSampleMFCApp() noexcept;

protected:
	CMultiDocTemplate* m_pDocTemplate;
public:

// オーバーライド
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 実装
	afx_msg void OnAppAbout();
	afx_msg void OnFileNewFrame();
	afx_msg void OnFileNew();
	DECLARE_MESSAGE_MAP()
};

extern CSampleMFCApp theApp;
