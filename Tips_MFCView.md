### 参考
+ https://learn.microsoft.com/ja-jp/cpp/mfc/reference/cview-class?view=msvc-170
+ https://learn.microsoft.com/ja-jp/cpp/mfc/hierarchy-chart?view=msvc-170
+ https://learn.microsoft.com/ja-jp/cpp/mfc/reference/clistview-class?view=msvc-170
+ https://learn.microsoft.com/ja-jp/cpp/mfc/reference/ctreeview-class?view=msvc-170


### ドキュメント/ビュー アーキテクチャ
+ 表示とデータを分離したアーキテクチャ
+ ビューはアタッチしているドキュメントにアクセスできる
+ ドキュメントとビューは1対多の関係
+ ビューは親ウィンドウの子ウィンドウとなる
+ 親ウィンドウとビューは1対1の関係

### MFC Viewクラス一覧
| View基本クラス | 内容 |
| :-- | :-- |
| CView | ビューの抽象インターフェースクラス. プロジェクト作成時のデフォルトビューはこのクラスの派生. |
| CCtrlView | コントロールを持つビューの基底クラス |
| CEditView | 簡単なマルチラインテキストエディタを提供するビュー |
| CListView | CListCtrlを持つビュー |
| CRichEditView | CEditViewの拡張版 |
| CTreeView | CTreeCtrlを持つビュー |
| CScrollView | スクロール機能を自動的に提供するビュー |
| CFormView | ダイアログボックスを持つスクロール可能なビュー |
| CDaoRecordView | データベースレコードを表示するビュー(Dao版) |
| CRecordView | データベースレコードを表示するビュー |
| CTabView | CMFCTabCtrl + ドキュメント/アーキテクチャ |
| COleDBRecordView | - |
| CHtmlView | ウェブブラウザの機能を提供するビュー |
| CHtmlEditView | - |
| CPreviewView | 印刷プレビューを表示するビュー |
| CPreviewViewEx | 印刷プレビューを表示するビュー(拡張版) |
| CWinFormsView | Windows Form 画面をホストするビュー |
+ afxwin.hが必要

### CViewのメソッド
| メソッド | 内容 |
| :-- | :-- |
| CView(); | コンストラクタ |
| BOOL DoPreparePrinting(CPrintInfo* pInfo); | [印刷]ダイアログボックスを表示して, プリンターデバイスコンテキストを作成する. |
| - | @warning  OnPreparePrinting()ハンドラ内で呼び出す. |
| CDocument* GetDocument() const; | アタッチしているドキュメントのポインタを取得する. |
| virtual BOOL IsSelected(const CObject* pDocItem) const; | 選択したドキュメントアイテムが選択されているかチェックする機能を提供する. @note フレームワークが呼び出すもの. |
| virtual void OnActivateFrame(UINT nState, CFrameWnd* pFrameWnd); | ビューを含むウィンドウがアクティブ/非アクティブ化したときにフレームワークから呼び出される. |
| - | @note ビューがアタッチしているウィンドウがアクティブ/非アクティブされたときに特別な処理をしたい場合, この関数をオーバーライドする. |
| virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView); | ビューがアクティブ/非アクティブ化されたときに呼ばれる. |
| - | @note 他のビューのアクティブ/非アクティブ化を知るためのもの. |
| - | @note ビューの親ウィンドウがアクティブになりアクティブなビューに変更がない場合, pActiveViewトpDeactiveViewは同じポインタ. |
| virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo); | OnPreparePrinting()が呼び出されたあと, 印刷または印刷プレビュー ジョブの開始時にフレームワークによって呼び出される. |
| virtual DROPEFFECT OnDragEnter(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point); | ドロップターゲットのスクロールしないウィンドウ領域にマウスドラッグ中のマウスポインタが入ったタイミングでフレームワークから呼ばれる. |
| virtual void OnDragLeave(); | ドラッグ中のマウスポインタがドロップターゲットウィンドウから離れた際に呼ばれる. |
| virtual DROPEFFECT OnDragOver(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point); | ドロップターゲットの上をマウスポインタが移動しているときに呼ばれる. |
| virtual DROPEFFECT OnDragScroll(DWORD dwKeyState, CPoint point); | ドラッグマウスポインタがスクロールバーの上にある時に呼ばれる. |
| virtual void OnDraw(CDC* pDC) = 0; | ドキュメントをレンダリングするために呼ばれる. @warning 純粋仮想関数なので, CViewクラス自体はインスタンス化できない. |
| - | @note 描画を最適化するにはCDCのRectVisible()を呼び出して指定された四角形が描画されるか確認する. |
| - | @note 画面表示と印刷表示を区別するにはIsPrinting()を呼び出す. |
| virtual BOOL OnDrop(COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point); | ドロップ時に呼ばれる. |
| virtual DROPEFFECT OnDropEx(COleDataObject* pDataObject, DROPEFFECT dropDefault, DROPEFFECT dropList, CPoint point); | 拡張版 |
| virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo); | ドキュメントが印刷またはプレビューされた後に呼ばれる. |
| virtual void OnEndPrintPreview(CDC* pDC, CPrintInfo* pInfo, POINT point, CPreviewView* pView); | 印刷プレビューモードを終了したときに呼ばれる. |
| - | @warning デフォルトではOnEndPrinting()を呼び出して, 印刷モード前の状態に復元する. |
| virtual void OnInitialUpdate(); | 最初にビューがドキュメントにアタッチされた後, 最初に表示される前に呼ばれる. ビューの初期化に使う. |
| virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL); | OnDraw()と印刷または印刷プレビュー中に各ページに対してOnPrint()が呼ばれる前にフレームワークによって呼ばれる. |
| virtual BOOL OnPreparePrinting(CPrintInfo* pInfo); | ドキュメントの印刷またはプレビュー前に呼ばれる. |
| virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo); | ドキュメントのページを印刷またはプレビューするために呼ばれる. |
| virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE); | ビューがスクロール可能か判断するために呼ばれる. |
| virtual BOOL OnScrollBy(CSize sizeScroll, BOOL bDoScroll = TRUE); | OLE項目をビューの現在の罫線に対してドラッグするか垂直・水平スクロールバーを操作することによって, ドキュメントの現在のビューを超える領域を表示するときに呼ばれる. |
| virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint); | ドキュメントが変更されたことをビューに通知するために呼ばれる. CDocument::UpdateAllViews()ではOnUpdate()を通じてドキュメントに関連する全ビューに通知する. |


