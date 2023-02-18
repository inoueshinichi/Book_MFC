#pragma once

#include "Win32Defs.h"

namespace is
{
    namespace common
    {
        namespace win32
        {
            /**
             * @brief Win32API Error を取得する
             * http://yamatyuu.net/computer/program/sdk/base/errmsg1/index.html
             * @return CString
             */
            inline CString win32_api_error()
            {
                DWORD error_code = ::GetLastError();
                TCHAR tszMsgBuff[1024];
                DWORD dwChars; // Number of chars returns;

                /**
                 * DWORD FormatMessage(
                 *  DWORD dwFlags,      // 入力元と処理方法のオプション
                 *  LPCVOID lpSource,   // メッセージの入力元
                 *  DWORD dwMessageId,  // メッセージ識別子
                 *  DWORD dwLanguageId, // 言語識別子
                 *  LPTSTR lpBuffer,    // メッセージバッファ
                 *  DOWRD nSize,        // メッセージバッファの最大サイズ
                 *  va_list* Arguments  // 複数のメッセージ挿入シーケンスからなる配列
                 * )
                 */
                dwChars = ::FormatMessage(
                            FORMAT_MESSAGE_ALLOCATE_BUFFER | // テキストのメモリ割り当てを要求
                            FORMAT_MESSAGE_FROM_SYSTEM |   // エラーメッセージはWindowsが用意しているものを使用
                            FORMAT_MESSAGE_IGNORE_INSERTS, // 次の引数を無視してエラーコードに対するエラーメッセージを作成する
                            NULL,
                            error_code,
                            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // 言語(日本語)を設定
                            tszMsgBuff,  // メッセージテキストが保存されるバッファへのポインタ
                            1024,
                            NULL);

                if (dwChars == 0)
                {
                    // The error code did not exist in the system errors.
                    // Try Ntdsbmsg.dll for the error code.
                    HINSTANCE hInstance;

                    // Load the library.
                    hInstance = LoadLibrary(_T("Ntdsbmsg.dll"));
                    if (hInstance == NULL)
                    {
                        _tprintf(_T("Can not load Ntdsbmsg.dll\n"));
                        std::abort();
                    }

                    dwChars = ::FormatMessage(
                                    FORMAT_MESSAGE_ALLOCATE_BUFFER |
                                    FORMAT_MESSAGE_FROM_SYSTEM |
                                    FORMAT_MESSAGE_IGNORE_INSERTS,
                                    NULL,
                                    error_code,
                                    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // 言語(日本語)を設定
                                    tszMsgBuff,
                                    1024,
                                    NULL);
                }

                CString win32_msg(tszMsgBuff);
                return win32_msg;
            }
        }
    }
}
