### �Q�l
+ https://learn.microsoft.com/ja-jp/cpp/mfc/reference/cscrollview-class?view=msvc-170

### ��{�p��
+ �f�o�C�X�P�� : ���j�^�[����pixel.
+ �_���P�� : 0.001mm�Ȃǃ��[�g���\�L.
+ �r���[�|�[�g�T�C�Y : �E�B���h�E(�f�o�C�X)�ŖڂɌ�����͈�. �܂�, �r���[�̐e�E�B���h�E�̃N���C�A���g�̈�.
+ �r���[�T�C�Y : �r���[�ŕ\���\�Ȕ͈�. �_���P�ʂƃf�o�C�X�P��2����. �K��ViewPortSize<=ViewSize�����藧��.


### CScrollView�̎g����
���N���XCView�ɑ΂��ĉ��L�̋@�\���ǉ�����Ă���.
+ �����E�����X�N���[���o�[�̒�(�X�N���[���o�[���b�Z�[�W�ɉ������Ď����I�ɃX�N���[��)
+ CScrollView�N���X��OnVScroll()��OnHScroll()�n���h�����I�[�o�[���C�h���邱�ƂŃX�N���[���@�\���L���ɂȂ�
+ �E�B���h�E�ƃr���[�|�[�g�̃T�C�Y�ƃ}�b�s���O ���[�h���Ǘ�
+ �L�[�{�[�h, �X�N���[�����Ȃ��}�E�X�A�܂��� IntelliMouse �z�C�[������̃��b�Z�[�W�ɉ������āA�����I�ɃX�N���[��
+ OnMouseWheel()���I�[�o�[���C�h�̃I�[�o�[���C�h�Ń}�E�X�z�C�[���ɂ����X�N���[���̒�

| ���\�b�h | ���e |
| :-- | :-- |
| CScrollView(); | �R���X�g���N�^. @warning �X�N���[���r���[���g�p����O��, SetScrollSizes() or SetScaleToFitSize()���Ăяo���K�v������ |
| void CheckScrollBars(BOOL& bHasHorzBar, BOOL& bHasVertBar) const | �����E�����X�N���[���o�[�̑��݃`�F�b�N |
| void FillOutsideRect(CDC* pDC, CBrush* pBrush); | �X�N���[���̈�̊O���ɕ\�������r���[�̈�̓h��Ԃ�. |
| - | @note �X�N���[���r���[��OnEraseBkgnd()�n���h���[������FillOutsideRect()���g�p���ĉߏ�ȕ`���}������ |
| CPoint GetDeviceScrollPosition() const; | �X�N���[���o�[���̌��݂̃X�N���[���{�b�N�X�̈ʒu(h,v)���擾((�f�o�C�X�P��: �s�N�Z��) |
| - | @note �r���[�̍�����̃I�t�Z�b�g�ʂɑ�������. �}�E�X�|�C���^�̈ʒu���X�N���[���ʍ��Ŏw�肷��ꍇ�ɗL��. |
| void GetDeviceScrollSizes(int& nMapMode, SIZE& sizeTotal, SIZE& sizePage, SIZE& sizeLine) const; | - |
| - | �X�N���[���\�r���[�̌��݂̃}�b�s���O���[�h�ƃX�N���[���ŕ\�����������S�̂̃T�C�Y(x,y)(�f�o�C�X�P��), �y�[�W�T�C�Y, �s�T�C�Y���擾 |
| CPoint GetScrollPosition() const; | �_���P�ʂŃX�N���[���o�[���̃X�N���[���{�b�N�X�̈ʒu(h,v)���擾. |
| CSize GetTotalSize() const; | �_���P�ʂŐ����E�����X�N���[���o�[�̒�������̒������擾. |
| void ResizeParentToFit(BOOL bShrinkOnly = TRUE); | �e�t���[�����r���[�T�C�Y�Ō��߂�ݒ�. |
| - | @note True: �r���[���k��������ꍇ�����e�t���[���T�C�Y��ς���. False(�񐄏�): ��Ƀr���[�Ɛe�t���[���̃T�C�Y�𓯂��ɂ���. |
| - | @note MDI�t���[�����[�N�̎q�E�B���h�E�Ή��̃r���[�݂̂ɐ���. OnInitUpdate()���Ŏg�p����.|
| - | @warning ResizeParentToFit()��, �r���[�E�B���h�E�̃T�C�Y���ݒ肳��Ă��邱�Ƃ�O��Ƃ��Ă���. |
| - | @warning ResizeParentToFit()�Ăяo�����Ƀr���[�T�C�Y���ݒ肳��Ă��Ȃ��ꍇ, �A�T�[�V�������o��. |
| - | @warning ���ꂪ�������Ȃ��悤�ɂ���ɂ�, ResizeParentToFit()�Ăяo���O��`GetParentFrame()->RecalcLayout();`���Ăяo��. |
| void ScrollToPosition(POINT pt); | �_���P�ʂŃr���[���̓���|�C���g�܂ŃX�N���[���o�[�������X�N���[��������. |
| - | @warning pt.x > 0, @waring MM_TEXT���[�h�̏ꍇ, �������͕��̒l�Ŏw�肷��. |
| - | @note �w��|�C���g���r���[�̍�����ɗ���悤�Ɉړ�����. |
| void SetScaleToFitSize(SIZE sizeTotal); | �r���[�T�C�Y���r���[�|�[�g�T�C�Y�ɍ��킹��(�g��E�k��). |
| - | @warning �X�N���[���o�[���Ӗ����Ȃ��Ȃ��̂ŏ�������. �r���[�|�[�g�̃T�C�Y���ς��ƃr���[���Ǐ]���ăr���[����������f�[�^�������X�P�[�����O����ĕ`�悳���. |
| - | @note �ʏ�, OnInitUpdate()���ŌĂяo��. �g��k�����K�v�Ȃ��ꍇ, SetScrollSize()���g�p����. |
| - | @note �X�N���[���@�\���ď��������邽�߂ɂ�, SetScrollSizes()�̌Ăяo�����K�v. |
| - | @warning �r���[�T�C�Y���ݒ肳��Ă��邱�Ƃ�O��Ƃ��Ă���. �T�C�Y�ݒ肪�Ȃ��ꍇ, �A�T�[�V�������o��. |
| - | �A�T�[�V�����𔭐������Ȃ��悤�ɂ���ɂ�, `GetParentFrame()->RecalcLayout();`�����O�ɌĂяo��. |
| void SetScrollSizes(int nMapMode, SIZE sizeTotal, const SIZE& sizePage = sizeDefault, const SIZE& sizeLine = sizeDefault); |
| - | �r���[�T�C�Y��ݒ肷��. |




### ResizeParentToFit()�̎g�p���@
 
ResizeParentToFit()�Ăяo�����Ƀr���[�T�C�Y���ݒ肳��Ă��Ȃ��ꍇ, �A�T�[�V�������o��.  
���ꂪ�������Ȃ��悤�ɂ���ɂ�, ResizeParentToFit()�Ăяo���O�ɉ��L�̊֐����Ăяo��.  
```
GetParentFrame()->RecalcLayout();
```

### �}�b�s���O���[�h
| ���O | ���l | �J�e�S�� | y���̐��̌��� |
| :-- | :-- | :-- | :-- |
| MM_TEXT | 1�s�N�Z�� | �f�o�C�X�P�� | ������ |
| MM_HIMETRIC | 0.01mm | �_���P�� | ����� |
| MM_TWIPS | 1/1440inch | �_���P�� | ����� |
| MM_HIENGLISH | 0.001inch | �_���P�� | ����� |
| MM_LOMETRIC | 0.1mm | �_���P�� | ����� |
| MM_LOENGLISH | 0.01inch | �_���P�� | ����� |

### OnEraseBkgnd()�n���h����FillOutsideRect()�̎g����
```
BOOL CMyScrollView::OnEraseBkgnd(CDC* pDC)
{
   CBrush br(GetSysColor(COLOR_WINDOW));
   FillOutsideRect(pDC, &br);
   return TRUE;                   // Erased
}
```


+ SetScrollSizes(int �r���[�}�b�v���[�h, CSize �X�N���[���r���[�S�̂̃T�C�Y)  


