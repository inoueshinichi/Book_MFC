### 参考
+ https://learn.microsoft.com/ja-jp/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject
+ https://learn.microsoft.com/ja-jp/windows/win32/api/synchapi/nf-synchapi-waitforsingleobjectex
+ https://learn.microsoft.com/ja-jp/windows/win32/api/synchapi/nf-synchapi-waitformultipleobjects
+ https://learn.microsoft.com/ja-jp/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject


### WaitForSingle[Multi]Object[s][Ex]の概要 
| 関数 | 用途 |
| :-- | :-- |
| DWORD WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds) | １つのオブジェクトを待機 |
| DWORD WaitForSingleObjectEx(HANDLE hHandle, DWORD dwMilliseconds, BOOL bAlertable) | アラート可能な待機状態を提供する |
| DWORD WaitForMultipleObjects(DWORD nCount, const HANDLE *lpHandles, BOOL bWaitAll, DWORD dwMilliseconds) | 複数オブジェクトの待機 |
| DWORD WaitForMultipleObjects(DWORD nCount, const HANDLE *lpHandles, BOOL bWaitAll, DWORD dwMilliseconds, BOOL bAlertable) | アラート可能な複数オブジェクトに対する待機状態を提供 |

### 待機できるオブジェクト一覧
| オブジェクト | 内容 |
| :-- | :-- |
| 変更通知 | - |
| コンソール入力 | - |
| Event | - |
| メモリ リソース通知 | - |
| Mutex | - |
| Process | - |
| Semaphore | - |
| Thread | - |
| 待機可能タイマー | - |

### 待機終了条件
| 関数 | 待機終了条件 |
| :-- | :-- |
| WaitForSingleObject | 指定オブジェクトがシグナル状態になる or タイムアウト時間を経過する |
| WaitForSingleObjectEx | 指定オブジェクトが, , シグナル状態になる or I/O完了ルーチンまたはユーザーモード非同期プロシージャ呼び出し(APC)がスレッドのキューに登録される or タイムアウト時間を経過する |
| WaitForMultiObjects | 指定オブジェクトの1つ以上が, シグナル状態になるまで待機するか or タイムアウト間隔が経過する |
| WaitForMultiObjectsEx |  指定オブジェクトの1つ以上が,  シグナル状態になる or I/O完了ルーチンまたはユーザーモード非同期プロシージャ呼び出し(APC)がスレッドのキューに登録される or タイムアウト時間を経過する |


### ユーザーモード非同期プロシージャ(User-mode APC)
+ 一般的なWindowsアプリケーションで作成するウィンドウズプロシージャっぽい？(不正確. 要調査)
+ https://learn.microsoft.com/ja-jp/windows/win32/sync/asynchronous-procedure-calls


### WaitForSingleObjectの戻り値
| 戻り値 | 内容 |
| :-- | :-- |
| WAIT_ABANDONED(0x00000080L) | 既に処理が終了している |
| WAIT_OBJECT_0(0x00000000L) | 処理が終了した |
| WAIT_TIMEOUT(0x00000102L) | タイムアウト時間が経過した(スレッドの状態わからない) |
| WAIT_FAILED (DWORD)0xFFFFFFFF | 原因不明なエラー. ::GetLastError()関数でシステムの詳細エラーを確認すること |

### WaitForSingleObjectExの戻り値
| 戻り値 | 内容 |
| :-- | :-- |
| WAIT_ABANDONED(0x00000080L) | 既に処理が終了している |
| WAIT_IO_COMPLETION(0x000000C0L) | スレッドの(なんの？)キューに1つ以上の非同期プロシージャ関数(APC)を登録して, その後スレッドが終了した |
| WAIT_OBJECT_0(0x00000000L) | 処理が終了した |
| WAIT_TIMEOUT(0x00000102L) | タイムアウト時間が経過した(スレッドの状態わからない) |
| WAIT_FAILED (DWORD)0xFFFFFFFF | 原因不明なエラー. ::GetLastError()関数でシステムの詳細エラーを確認すること |



### 使用の際の注意点
直接または間接的にウィンドウを作成する待機関数とコードを呼び出す場合は注意が必要.  
スレッドがウィンドウを作成する場合は, メッセージを処理する必要がある. (メッセージループの作成) 
OSのメッセージブロードキャストは, システム内のすべてのウィンドウに送信されるので, 適切にメッセージループを構築しないとデッドロックする.
スレッド作成直後にメッセージループが構築されるまで待機できる機構がないと, システムがデッドロックする.
+ デッドロックは, 各スレッドが他のスレッドが何かを行うのを待っているときに発生する.

下記, メッセージループ構築を考慮したプログラムの一例  
```
// ワーカースレッド関数
unsigned int WINAPI WorkerThreadFunc(void *arg)
{
    HANDLE hThreadInitEvent = (HANDLE)arg;

    MSG uMsg;

    // スレッドキューの作成
    PeekMessage(&uMsg, NULL, 0, 0, PM_NOREMOVE);

    // イベント(False -> True)
    ::SetEvent(hThreadInitEvent);

    while (true)
    {
        if (PeekMessage(&uMsg, NULL, 0, 0, PM_NOREMOVE) > 0)
        {
            if (GetMessage(&uMsg, NULL, 0, 0) > 0)
            {
                ~
             }
             else
             {
                 break; // WM_QUIT
             }
         }
     }

    ::_endthreadex(1234);

    return 0;
}


// メインスレッド側
int main()
{
    HANDLE hThreadInitEvent = ::CreateEvent(NULL, // SECURITY_ATTRIBUTE構造体
                                            TRUE, // リセットのタイプ(True:自動, False:手動)
                                            FALSE, // 初期状態(True:シグナル状態, False:非シグナル状態)
                                            NULL);
    
     // ワーカースレッド作成
    DWORD nThreadId = 0;
    HANDLE hThread = (HANDLE)::_beginthreadex(NULL, // SECURITY_ATTRIBUTE構造体
                                              0, // スタックサイズ(0は呼び出し側と同じサイズ)
                                              &WorkerThreadFunc, // ワーカスレット関数ポインタ
                                              (void*)hThreadInitEvent, // スレッド関数の引数
                                              0, // 作成オプション (0: CREATE_SUSPENDED)
                                              &nThreadId // スレッドID (DWORD)
                                              );

    // スレッドキューの作成待ち
    ::WaitForSingleObject(hThreadInitEvent, INFINIT);
    // スレッド初期化イベントの破棄
    ::CloseEvent(hThreadInitEvent);

    // ワーカースレッドへのメッセージの送信
    PostThreadMessage(nThreadId, ~);

    // ~~~~

    // スレッド終了待ち
    ::WaitForSingleObject(hThread, INFINIT);
    // スレッドイベントの破棄
    ::CloseEvent(hThread);

    // ワーカースレッドの終了状態を取得
    DWORD dwExitCode;
    ::GetExitCodeThread(hThread, &dwExitCode);
}
```

もしくは下記のイベント付属の専用待機関数を使用する.  
| 関数 | 用途 |
| :-- | :-- |
| DWORD MsgWaitForMultipleObjects(DWORD nCount, const HANDLE *pHandles, BOOL fWaitAll, DWORD dwMilliseconds, DWORD dwWakeMask) | - |
| DWORD MsgWaitForMultipleObjectsEx((DWORD nCount, const HANDLE *pHandles, BOOL fWaitAll, DWORD dwMilliseconds, DWORD dwWakeMask, DWORD dwFlags) | 上記のアラート付き待機 |
