### 参考
+ https://learn.microsoft.com/ja-jp/cpp/mfc/reference/cwnd-class?view=msvc-170

### MFC基本用語
+ スクリーン座標: モニターの座標
+ ウィンドウ領域: スクリーン座標系内のウィンドウが占める領域
+ クライアント領域: ウィンドウ領域内の外枠(額縁)の内部領域
+ クリップボード: テキストや画像をコピー(もしくは切り取り)すると,一時的に保存される場所
+ 親(Parent): ウィンドウ構造における, 自身が存在するクライアント領域の所有者ウィンドウ. @note 親子関係における子は親のクライアント領域内限定でしか配置できない. @warning オブジェクト指向における親クラスとは異なる.
+ 所有者(Owner): ウィンドウ構造おける, 雇用主と雇用側の関係. 所有されている側ウィンドウはデスクトップの任意の位置に配置できる. @warning 他のフレームワークで親(Parent)といった場合, こっちを指すことが多い(Qtとか)
+ 所有者の中で, 自身をウィンドウ内で管理するものが親となる. 


### CWndの概要
+ MFC管理化のすべてのウィンドウの基底クラス.  
+ CWndを直接操作する機会は少なく, ほとんどの場合, 派生クラスからCWndの関数を呼び出す方式で使用する.


## メソッド(多すぎるので一部だけ)
+ フレームワークから呼ばれるものとユーザー作成の派生クラスから呼ぶものがある.

### 使用頻度高のメソッド
| メソッド名 | 公開スコープ | 内容 |
| :-- | :-- | :-- |
| DestroyWindow | public | 関連付けられているすべての(子)ウィンドウを削除する |
| EnableDynamicLayout | public | ウィンドウのサイズを変更したときに, 子ウィンドウの位置とサイズを動的に調整する可否. |
| EnableWindow | public | マウス入力&キーボード入力の有効または無効 |
| FindWindow | static public | 関連するウィンドウハンドル(HWND)の検索 |
| FindWindowEX | static public | 上記, 拡張版 |
| FromHandle | static public | HWNDからCWndポインタを取得する. HWNDにCWndオブジェクトがアタッチされていない場合, 一時CWndオブジェクトを作成する. |
| FromHandlePermanent | static public | HWNDからCWndポインタを取得する. (確実にCWndにHWNDがアタッチされている場合) |
| GetActiveWindow | static public | アクティブなウィンドウを取得. |
| GetCapture | static public | マウスキャプチャのあるウィンドウを取得. |
| GetClientRect | public | クライアント領域の寸法を取得. |
| GetDC | public | クライアント領域のデバイスコンテキストを取得する. |
| GEtDCEx | public | 上記の拡張版. |
| GetDescendantWindow | public | ID指定で子孫ウィンドウのCWndポインタを取得する. |
| GetDesktopWindow | static public | デスクトップウィンドウを取得する. |
| GetDlgItem | public | ダイアログボックスor他のウィンドウの指定したコントロールor子ウィンドウのCWndポインタorHWNDを取得する. |
| GetFocus | static public | 現在の入力フォーカスを持つウィンドウのCWndポインタを取得する. |
| GetFont | public | 現在のフォントを取得する |
| GetForegroundWindow | フォアグラウンドウィンドウ (ユーザーが現在作業しているウィンドウ)へのCWndポインタを取得する. |
| GetMenu | public | ウィンドウメニューへのCMenuポインタを取得する. |
| GetOwner | public | 所有者へのCWndポインタを返す. @warning 所有者がいない場合, 親ウィンドウのポインタを返す.| 
| - | - | @note 所有者はいなくても, Rootウィンドウ以外は必ず親ウィンドウが存在する. |
| - | - | @warning 使うべきではない. 後述の`GetSafeOwner()`を使用すべき. |
| GetParent | public | 子ウィンドウの親ウィンドウへのポインタを取得する. |
| GetParentFrame | public | 親フレームウィンドウへのポインタを返す. |
| GetParentOwner | public | 子ウィンドウではない最も直接的な親ウィンドウまたは所有者ウィンドウへのポインタを取得する. |
| - | - | @note 現在の所有者は`SetOwner()`で指定できる. デフォルトでは, 親ウィンドウは所有者扱い. 所有者の方が概念が幅広い. |
| GetSafeHwnd | public | HWNDがCWndにアタッチされている場合, HWND, デタッチされている場合, NULLを返す. |
| GetSafeOnwer | public | 所有者ポインタを返す. 所有者がいない場合, NULLを返す. `GetOwner()`と動作が違う. |


### 使用頻度中のメソッド
| メソッド名 | 公開スコープ | 内容 |
| :-- | :-- | :-- |
| ClientToScreen | public | クライアント領域の座標をスクリーン座標に変換 |
| CloseWindow | public | ウィンドウを最小化する |
| DragAcceptFiles | public | ドラッグアンドドロップで渡されるファイルの受け取りの可否 |
| CalcWindowRect | public | クライアント領域からウィンドウ領域を計算する |
| CenterWindow | public | 対象のウィンドウを親ウィンドウの中央に配置する |
| EnableD2DSupport | public | D2Dのサポートを有効または無効 |
| DragDetect | public | マウスをキャプチャし, ユーザーが左ボタンを離す・Escキーを押す・指定した点を中心にしたドラッグ四角形の外にマウスを移動まで移動を追跡する. |
| GetAncestor | public | 指定ウィンドウの祖先ウィンドウオブジェクトを取得. |
| GetDynamicLayout | 動的レイアウトマネージャへのポインタを取得する. |
| GetIcon | public | ウィンドウアイコンのハンドラ(HICON)を取得する. |
| GetClipboardOwner | static public | クリップボードの現在の所有者を取得する. |
| GetOpenClipboardWindow | static public | クリップボードが開いているウィンドウへのCWndポインタを取得する. |




### 使用頻度低のメソッド
| メソッド名 | 公開スコープ | 内容 |
| :-- | :-- | :-- |
| AnimateWindow | public | 関連付けられたウィンドウオブジェクトをアニメーション化する |
| Attach | public | HWNDをCWndに関連づける |
| Detach | public | CWndからHWNDを切り離す |

