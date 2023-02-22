
// SampleThread.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CSampleThreadApp:
// このクラスの実装については、SampleThread.cpp を参照してください
//

class CSampleThreadApp : public CWinApp
{
public:
	CSampleThreadApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CSampleThreadApp theApp;
