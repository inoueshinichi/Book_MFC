### �Q�l
+ https://learn.microsoft.com/ja-jp/cpp/mfc/reference/cview-class?view=msvc-170
+ https://learn.microsoft.com/ja-jp/cpp/mfc/hierarchy-chart?view=msvc-170
+ https://learn.microsoft.com/ja-jp/cpp/mfc/reference/clistview-class?view=msvc-170
+ https://learn.microsoft.com/ja-jp/cpp/mfc/reference/ctreeview-class?view=msvc-170


### �h�L�������g/�r���[ �A�[�L�e�N�`��
+ �\���ƃf�[�^�𕪗������A�[�L�e�N�`��
+ �r���[�̓A�^�b�`���Ă���h�L�������g�ɃA�N�Z�X�ł���
+ �h�L�������g�ƃr���[��1�Α��̊֌W
+ �r���[�͐e�E�B���h�E�̎q�E�B���h�E�ƂȂ�
+ �e�E�B���h�E�ƃr���[��1��1�̊֌W

### MFC View�N���X�ꗗ
| View��{�N���X | ���e |
| :-- | :-- |
| CView | �r���[�̒��ۃC���^�[�t�F�[�X�N���X. �v���W�F�N�g�쐬���̃f�t�H���g�r���[�͂��̃N���X�̔h��. |
| CCtrlView | �R���g���[�������r���[�̊��N���X |
| CEditView | �ȒP�ȃ}���`���C���e�L�X�g�G�f�B�^��񋟂���r���[ |
| CListView | CListCtrl�����r���[ |
| CRichEditView | CEditView�̊g���� |
| CTreeView | CTreeCtrl�����r���[ |
| CScrollView | �X�N���[���@�\�������I�ɒ񋟂���r���[ |
| CFormView | �_�C�A���O�{�b�N�X�����X�N���[���\�ȃr���[ |
| CDaoRecordView | �f�[�^�x�[�X���R�[�h��\������r���[(Dao��) |
| CRecordView | �f�[�^�x�[�X���R�[�h��\������r���[ |
| CTabView | CMFCTabCtrl + �h�L�������g/�A�[�L�e�N�`�� |
| COleDBRecordView | - |
| CHtmlView | �E�F�u�u���E�U�̋@�\��񋟂���r���[ |
| CHtmlEditView | - |
| CPreviewView | ����v���r���[��\������r���[ |
| CPreviewViewEx | ����v���r���[��\������r���[(�g����) |
| CWinFormsView | Windows Form ��ʂ��z�X�g����r���[ |
+ afxwin.h���K�v

### CView�̃��\�b�h
| ���\�b�h | ���e |
| :-- | :-- |
| CView(); | �R���X�g���N�^ |
| BOOL DoPreparePrinting(CPrintInfo* pInfo); | [���]�_�C�A���O�{�b�N�X��\������, �v�����^�[�f�o�C�X�R���e�L�X�g���쐬����. |
| - | @warning  OnPreparePrinting()�n���h�����ŌĂяo��. |
| CDocument* GetDocument() const; | �A�^�b�`���Ă���h�L�������g�̃|�C���^���擾����. |
| virtual BOOL IsSelected(const CObject* pDocItem) const; | �I�������h�L�������g�A�C�e�����I������Ă��邩�`�F�b�N����@�\��񋟂���. @note �t���[�����[�N���Ăяo������. |
| virtual void OnActivateFrame(UINT nState, CFrameWnd* pFrameWnd); | �r���[���܂ރE�B���h�E���A�N�e�B�u/��A�N�e�B�u�������Ƃ��Ƀt���[�����[�N����Ăяo�����. |
| - | @note �r���[���A�^�b�`���Ă���E�B���h�E���A�N�e�B�u/��A�N�e�B�u���ꂽ�Ƃ��ɓ��ʂȏ������������ꍇ, ���̊֐����I�[�o�[���C�h����. |
| virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView); | �r���[���A�N�e�B�u/��A�N�e�B�u�����ꂽ�Ƃ��ɌĂ΂��. |
| - | @note ���̃r���[�̃A�N�e�B�u/��A�N�e�B�u����m�邽�߂̂���. |
| - | @note �r���[�̐e�E�B���h�E���A�N�e�B�u�ɂȂ�A�N�e�B�u�ȃr���[�ɕύX���Ȃ��ꍇ, pActiveView�gpDeactiveView�͓����|�C���^. |
| virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo); | OnPreparePrinting()���Ăяo���ꂽ����, ����܂��͈���v���r���[ �W���u�̊J�n���Ƀt���[�����[�N�ɂ���ČĂяo�����. |
| virtual DROPEFFECT OnDragEnter(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point); | �h���b�v�^�[�Q�b�g�̃X�N���[�����Ȃ��E�B���h�E�̈�Ƀ}�E�X�h���b�O���̃}�E�X�|�C���^���������^�C�~���O�Ńt���[�����[�N����Ă΂��. |
| virtual void OnDragLeave(); | �h���b�O���̃}�E�X�|�C���^���h���b�v�^�[�Q�b�g�E�B���h�E���痣�ꂽ�ۂɌĂ΂��. |
| virtual DROPEFFECT OnDragOver(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point); | �h���b�v�^�[�Q�b�g�̏���}�E�X�|�C���^���ړ����Ă���Ƃ��ɌĂ΂��. |
| virtual DROPEFFECT OnDragScroll(DWORD dwKeyState, CPoint point); | �h���b�O�}�E�X�|�C���^���X�N���[���o�[�̏�ɂ��鎞�ɌĂ΂��. |
| virtual void OnDraw(CDC* pDC) = 0; | �h�L�������g�������_�����O���邽�߂ɌĂ΂��. @warning �������z�֐��Ȃ̂�, CView�N���X���̂̓C���X�^���X���ł��Ȃ�. |
| - | @note �`����œK������ɂ�CDC��RectVisible()���Ăяo���Ďw�肳�ꂽ�l�p�`���`�悳��邩�m�F����. |
| - | @note ��ʕ\���ƈ���\������ʂ���ɂ�IsPrinting()���Ăяo��. |
| virtual BOOL OnDrop(COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point); | �h���b�v���ɌĂ΂��. |
| virtual DROPEFFECT OnDropEx(COleDataObject* pDataObject, DROPEFFECT dropDefault, DROPEFFECT dropList, CPoint point); | �g���� |
| virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo); | �h�L�������g������܂��̓v���r���[���ꂽ��ɌĂ΂��. |
| virtual void OnEndPrintPreview(CDC* pDC, CPrintInfo* pInfo, POINT point, CPreviewView* pView); | ����v���r���[���[�h���I�������Ƃ��ɌĂ΂��. |
| - | @warning �f�t�H���g�ł�OnEndPrinting()���Ăяo����, ������[�h�O�̏�Ԃɕ�������. |
| virtual void OnInitialUpdate(); | �ŏ��Ƀr���[���h�L�������g�ɃA�^�b�`���ꂽ��, �ŏ��ɕ\�������O�ɌĂ΂��. �r���[�̏������Ɏg��. |
| virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL); | OnDraw()�ƈ���܂��͈���v���r���[���Ɋe�y�[�W�ɑ΂���OnPrint()���Ă΂��O�Ƀt���[�����[�N�ɂ���ČĂ΂��. |
| virtual BOOL OnPreparePrinting(CPrintInfo* pInfo); | �h�L�������g�̈���܂��̓v���r���[�O�ɌĂ΂��. |
| virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo); | �h�L�������g�̃y�[�W������܂��̓v���r���[���邽�߂ɌĂ΂��. |
| virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE); | �r���[���X�N���[���\�����f���邽�߂ɌĂ΂��. |
| virtual BOOL OnScrollBy(CSize sizeScroll, BOOL bDoScroll = TRUE); | OLE���ڂ��r���[�̌��݂̌r���ɑ΂��ăh���b�O���邩�����E�����X�N���[���o�[�𑀍삷�邱�Ƃɂ����, �h�L�������g�̌��݂̃r���[�𒴂���̈��\������Ƃ��ɌĂ΂��. |
| virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint); | �h�L�������g���ύX���ꂽ���Ƃ��r���[�ɒʒm���邽�߂ɌĂ΂��. CDocument::UpdateAllViews()�ł�OnUpdate()��ʂ��ăh�L�������g�Ɋ֘A����S�r���[�ɒʒm����. |


