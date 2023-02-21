### 参考
+ https://learn.microsoft.com/ja-jp/cpp/mfc/reference/cscrollview-class?view=msvc-170

### 基本用語
+ デバイス単位 : モニターだとpixel.
+ 論理単位 : 0.001mmなどメートル表記.
+ ビューポートサイズ : ウィンドウ(デバイス)で目に見える範囲. つまり, ビューの親ウィンドウのクライアント領域.
+ ビューサイズ : ビューで表示可能な範囲. 論理単位とデバイス単位2つ存在. 必ずViewPortSize<=ViewSizeが成り立つ.


### CScrollViewの使い方
基底クラスCViewに対して下記の機能が追加されている.
+ 水平・垂直スクロールバーの提供(スクロールバーメッセージに応答して自動的にスクロール)
+ CScrollViewクラスはOnVScroll()とOnHScroll()ハンドラをオーバーライドすることでスクロール機能が有効になる
+ ウィンドウとビューポートのサイズとマッピング モードを管理
+ キーボード, スクロールしないマウス、または IntelliMouse ホイールからのメッセージに応答して、自動的にスクロール
+ OnMouseWheel()をオーバーライドのオーバーライドでマウスホイールによる基底スクロールの提供

| メソッド | 内容 |
| :-- | :-- |
| CScrollView(); | コンストラクタ. @warning スクロールビューを使用する前に, SetScrollSizes() or SetScaleToFitSize()を呼び出す必要がある |
| void CheckScrollBars(BOOL& bHasHorzBar, BOOL& bHasVertBar) const | 垂直・水平スクロールバーの存在チェック |
| void FillOutsideRect(CDC* pDC, CBrush* pBrush); | スクロール領域の外側に表示されるビュー領域の塗りつぶし. |
| - | @note スクロールビューのOnEraseBkgnd()ハンドラー内部でFillOutsideRect()を使用して過剰な描画を抑制する |
| CPoint GetDeviceScrollPosition() const; | スクロールバー内の現在のスクロールボックスの位置(h,v)を取得((デバイス単位: ピクセル) |
| - | @note ビューの左上隅のオフセット量に相当する. マウスポインタの位置をスクロール量込で指定する場合に有効. |
| void GetDeviceScrollSizes(int& nMapMode, SIZE& sizeTotal, SIZE& sizePage, SIZE& sizeLine) const; | - |
| - | スクロール可能ビューの現在のマッピングモードとスクロールで表示させたい全体のサイズ(x,y)(デバイス単位), ページサイズ, 行サイズを取得 |
| CPoint GetScrollPosition() const; | 論理単位でスクロールバー内のスクロールボックスの位置(h,v)を取得. |
| CSize GetTotalSize() const; | 論理単位で水平・垂直スクロールバーの長手方向の長さを取得. |
| void ResizeParentToFit(BOOL bShrinkOnly = TRUE); | 親フレームをビューサイズで決める設定. |
| - | @note True: ビューを縮小させる場合だけ親フレームサイズを変える. False(非推奨): 常にビューと親フレームのサイズを同じにする. |
| - | @note MDIフレームワークの子ウィンドウ対応のビューのみに推奨. OnInitUpdate()内で使用する.|
| - | @warning ResizeParentToFit()は, ビューウィンドウのサイズが設定されていることを前提としている. |
| - | @warning ResizeParentToFit()呼び出し時にビューサイズが設定されていない場合, アサーションが出る. |
| - | @warning これが発生しないようにするには, ResizeParentToFit()呼び出し前に`GetParentFrame()->RecalcLayout();`を呼び出す. |
| void ScrollToPosition(POINT pt); | 論理単位でビュー内の特定ポイントまでスクロールバーを自動スクロールさせる. |
| - | @warning pt.x > 0, @waring MM_TEXTモードの場合, 下方向は負の値で指定する. |
| - | @note 指定ポイントがビューの左上隅に来るように移動する. |
| void SetScaleToFitSize(SIZE sizeTotal); | ビューサイズをビューポートサイズに合わせる(拡大・縮小). |
| - | @warning スクロールバーが意味をなさないので消失する. ビューポートのサイズが変わるとビューも追従してビューが所持するデータも自動スケーリングされて描画される. |
| - | @note 通常, OnInitUpdate()内で呼び出す. 拡大縮小が必要ない場合, SetScrollSize()を使用する. |
| - | @note スクロール機能を再初期化するためには, SetScrollSizes()の呼び出しが必要. |
| - | @warning ビューサイズが設定されていることを前提としている. サイズ設定がない場合, アサーションが出る. |
| - | アサーションを発生させないようにするには, `GetParentFrame()->RecalcLayout();`を事前に呼び出す. |
| void SetScrollSizes(int nMapMode, SIZE sizeTotal, const SIZE& sizePage = sizeDefault, const SIZE& sizeLine = sizeDefault); |
| - | ビューサイズを設定する. |




### ResizeParentToFit()の使用方法
 
ResizeParentToFit()呼び出し時にビューサイズが設定されていない場合, アサーションが出る.  
これが発生しないようにするには, ResizeParentToFit()呼び出し前に下記の関数を呼び出す.  
```
GetParentFrame()->RecalcLayout();
```

### マッピングモード
| 名前 | 数値 | カテゴリ | y軸の正の向き |
| :-- | :-- | :-- | :-- |
| MM_TEXT | 1ピクセル | デバイス単位 | 下向き |
| MM_HIMETRIC | 0.01mm | 論理単位 | 上向き |
| MM_TWIPS | 1/1440inch | 論理単位 | 上向き |
| MM_HIENGLISH | 0.001inch | 論理単位 | 上向き |
| MM_LOMETRIC | 0.1mm | 論理単位 | 上向き |
| MM_LOENGLISH | 0.01inch | 論理単位 | 上向き |

### OnEraseBkgnd()ハンドラとFillOutsideRect()の使い方
```
BOOL CMyScrollView::OnEraseBkgnd(CDC* pDC)
{
   CBrush br(GetSysColor(COLOR_WINDOW));
   FillOutsideRect(pDC, &br);
   return TRUE;                   // Erased
}
```


+ SetScrollSizes(int ビューマップモード, CSize スクロールビュー全体のサイズ)  


