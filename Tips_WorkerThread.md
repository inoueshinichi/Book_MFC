### 参考


### ワーカースレッドの作成
AfxBeginThread関数
```
CWinThread* AfxBeginThread(
               AFX_THREADPROC, // ワーカースレッド制御関数
               LPVOID, // ワーカースレッド制御関数に渡す引数
               int = THREAD_PRIORITY_NORMAL, // 優先度
               UINT = 0, // スタックサイズ(0は親プロセスと同じ)
               DWORD = 0, // スレッドの制御追加フラグ
               LPSECURITY_ATTRIBUTES = NULL // セキュリティ属性
            )
```
ワーカースレッドの制御関数(static関数)
```
static UINT 関数名(LPVOID 引数)
```

### 優先度
| 設定値 | 内容 |
| :-- | :-- |
| THREAD_PRIORITY_ABOVE_NORMAL | スレッド標準の相対優先順位値より+1高い優先度 |
| THREAD_PRIORITY_BELOW_NORMAL | スレッド標準の相対優先順位置より-1低い優先度 |
| THREAD_PRIORITY_HIGHEST | スレッド標準の相対優先順位値より+2高い優先度 |
| THREAD_PRIORITY_LOWEST | スレッド標準の相対優先順位値より-2低い優先度 |
| THREAD_PRIORITY_NORMAL | スレッド標準の相対優先順位値 |

### スレッドの制御追加フラグ
| 設定値 | 内容 |
| :-- | :-- |
| CREATE_SUSPENDED | スレッド生成時は停止状態 |
| 0 | スレッド生成時は起動状態 |
+ CREATE_SUSPENDEDを指定した場合`CWinThread::ResumeThread()`を呼び出すと起動状態になる


### セキュリティ属性
+ 何も指定しない場合プロセスと同じ属性となる

### 待機関数WaitForSingleObject
```
DWORD WaitForSingleObject(HANDLE, DWORD);
```
+ 戻り値(DWORD) : 待ち状態から戻った原因
+ 引数(HANDLE)  : オブジェクトハンドル
+ 引数(DWORD)   : タイムアウト時間

タイムアウト時間  
+ ミリ秒単位で指定. 
+ 0でオブジェクトの状態を取得して即座に制御を戻す. 
+ INFINITで無限に待つ.

戻り値(待ち状態から戻った原因)
   
| 戻り値 | 内容 |
| :-- | :-- |
| WAIT_ABANDONED | 既に処理が終了している |
| WAIT_OBJECT_0 | 処理が終了した |
| WAIT_TIMEOUT | タイムアウト時間が経過した(スレッドの状態わからない) |

 