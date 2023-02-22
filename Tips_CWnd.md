### �Q�l
+ https://learn.microsoft.com/ja-jp/cpp/mfc/reference/cwnd-class?view=msvc-170

### MFC��{�p��
+ �X�N���[�����W: ���j�^�[�̍��W
+ �E�B���h�E�̈�: �X�N���[�����W�n���̃E�B���h�E����߂�̈�
+ �N���C�A���g�̈�: �E�B���h�E�̈���̊O�g(�z��)�̓����̈�
+ �N���b�v�{�[�h: �e�L�X�g��摜���R�s�[(�������͐؂���)�����,�ꎞ�I�ɕۑ������ꏊ
+ �e(Parent): �E�B���h�E�\���ɂ�����, ���g�����݂���N���C�A���g�̈�̏��L�҃E�B���h�E. @note �e�q�֌W�ɂ�����q�͐e�̃N���C�A���g�̈������ł����z�u�ł��Ȃ�. @warning �I�u�W�F�N�g�w���ɂ�����e�N���X�Ƃ͈قȂ�.
+ ���L��(Owner): �E�B���h�E�\��������, �ٗp��ƌٗp���̊֌W. ���L����Ă��鑤�E�B���h�E�̓f�X�N�g�b�v�̔C�ӂ̈ʒu�ɔz�u�ł���. @warning ���̃t���[�����[�N�Őe(Parent)�Ƃ������ꍇ, ���������w�����Ƃ�����(Qt�Ƃ�)
+ ���L�҂̒���, ���g���E�B���h�E���ŊǗ�������̂��e�ƂȂ�. 


### CWnd�̊T�v
+ MFC�Ǘ����̂��ׂẴE�B���h�E�̊��N���X.  
+ CWnd�𒼐ڑ��삷��@��͏��Ȃ�, �قƂ�ǂ̏ꍇ, �h���N���X����CWnd�̊֐����Ăяo�������Ŏg�p����.


## ���\�b�h(��������̂ňꕔ����)
+ �t���[�����[�N����Ă΂����̂ƃ��[�U�[�쐬�̔h���N���X����ĂԂ��̂�����.

### �g�p�p�x���̃��\�b�h
| ���\�b�h�� | ���J�X�R�[�v | ���e |
| :-- | :-- | :-- |
| DestroyWindow | public | �֘A�t�����Ă��邷�ׂĂ�(�q)�E�B���h�E���폜���� |
| EnableDynamicLayout | public | �E�B���h�E�̃T�C�Y��ύX�����Ƃ���, �q�E�B���h�E�̈ʒu�ƃT�C�Y�𓮓I�ɒ��������. |
| EnableWindow | public | �}�E�X����&�L�[�{�[�h���̗͂L���܂��͖��� |
| FindWindow | static public | �֘A����E�B���h�E�n���h��(HWND)�̌��� |
| FindWindowEX | static public | ��L, �g���� |
| FromHandle | static public | HWND����CWnd�|�C���^���擾����. HWND��CWnd�I�u�W�F�N�g���A�^�b�`����Ă��Ȃ��ꍇ, �ꎞCWnd�I�u�W�F�N�g���쐬����. |
| FromHandlePermanent | static public | HWND����CWnd�|�C���^���擾����. (�m����CWnd��HWND���A�^�b�`����Ă���ꍇ) |
| GetActiveWindow | static public | �A�N�e�B�u�ȃE�B���h�E���擾. |
| GetCapture | static public | �}�E�X�L���v�`���̂���E�B���h�E���擾. |
| GetClientRect | public | �N���C�A���g�̈�̐��@���擾. |
| GetDC | public | �N���C�A���g�̈�̃f�o�C�X�R���e�L�X�g���擾����. |
| GEtDCEx | public | ��L�̊g����. |
| GetDescendantWindow | public | ID�w��Ŏq���E�B���h�E��CWnd�|�C���^���擾����. |
| GetDesktopWindow | static public | �f�X�N�g�b�v�E�B���h�E���擾����. |
| GetDlgItem | public | �_�C�A���O�{�b�N�Xor���̃E�B���h�E�̎w�肵���R���g���[��or�q�E�B���h�E��CWnd�|�C���^orHWND���擾����. |
| GetFocus | static public | ���݂̓��̓t�H�[�J�X�����E�B���h�E��CWnd�|�C���^���擾����. |
| GetFont | public | ���݂̃t�H���g���擾���� |
| GetForegroundWindow | �t�H�A�O���E���h�E�B���h�E (���[�U�[�����ݍ�Ƃ��Ă���E�B���h�E)�ւ�CWnd�|�C���^���擾����. |
| GetMenu | public | �E�B���h�E���j���[�ւ�CMenu�|�C���^���擾����. |
| GetOwner | public | ���L�҂ւ�CWnd�|�C���^��Ԃ�. @warning ���L�҂����Ȃ��ꍇ, �e�E�B���h�E�̃|�C���^��Ԃ�.| 
| - | - | @note ���L�҂͂��Ȃ��Ă�, Root�E�B���h�E�ȊO�͕K���e�E�B���h�E�����݂���. |
| - | - | @warning �g���ׂ��ł͂Ȃ�. ��q��`GetSafeOwner()`���g�p���ׂ�. |
| GetParent | public | �q�E�B���h�E�̐e�E�B���h�E�ւ̃|�C���^���擾����. |
| GetParentFrame | public | �e�t���[���E�B���h�E�ւ̃|�C���^��Ԃ�. |
| GetParentOwner | public | �q�E�B���h�E�ł͂Ȃ��ł����ړI�Ȑe�E�B���h�E�܂��͏��L�҃E�B���h�E�ւ̃|�C���^���擾����. |
| - | - | @note ���݂̏��L�҂�`SetOwner()`�Ŏw��ł���. �f�t�H���g�ł�, �e�E�B���h�E�͏��L�҈���. ���L�҂̕����T�O�����L��. |
| GetSafeHwnd | public | HWND��CWnd�ɃA�^�b�`����Ă���ꍇ, HWND, �f�^�b�`����Ă���ꍇ, NULL��Ԃ�. |
| GetSafeOnwer | public | ���L�҃|�C���^��Ԃ�. ���L�҂����Ȃ��ꍇ, NULL��Ԃ�. `GetOwner()`�Ɠ��삪�Ⴄ. |


### �g�p�p�x���̃��\�b�h
| ���\�b�h�� | ���J�X�R�[�v | ���e |
| :-- | :-- | :-- |
| ClientToScreen | public | �N���C�A���g�̈�̍��W���X�N���[�����W�ɕϊ� |
| CloseWindow | public | �E�B���h�E���ŏ������� |
| DragAcceptFiles | public | �h���b�O�A���h�h���b�v�œn�����t�@�C���̎󂯎��̉� |
| CalcWindowRect | public | �N���C�A���g�̈悩��E�B���h�E�̈���v�Z���� |
| CenterWindow | public | �Ώۂ̃E�B���h�E��e�E�B���h�E�̒����ɔz�u���� |
| EnableD2DSupport | public | D2D�̃T�|�[�g��L���܂��͖��� |
| DragDetect | public | �}�E�X���L���v�`����, ���[�U�[�����{�^���𗣂��EEsc�L�[�������E�w�肵���_�𒆐S�ɂ����h���b�O�l�p�`�̊O�Ƀ}�E�X���ړ��܂ňړ���ǐՂ���. |
| GetAncestor | public | �w��E�B���h�E�̑c��E�B���h�E�I�u�W�F�N�g���擾. |
| GetDynamicLayout | ���I���C�A�E�g�}�l�[�W���ւ̃|�C���^���擾����. |
| GetIcon | public | �E�B���h�E�A�C�R���̃n���h��(HICON)���擾����. |
| GetClipboardOwner | static public | �N���b�v�{�[�h�̌��݂̏��L�҂��擾����. |
| GetOpenClipboardWindow | static public | �N���b�v�{�[�h���J���Ă���E�B���h�E�ւ�CWnd�|�C���^���擾����. |




### �g�p�p�x��̃��\�b�h
| ���\�b�h�� | ���J�X�R�[�v | ���e |
| :-- | :-- | :-- |
| AnimateWindow | public | �֘A�t����ꂽ�E�B���h�E�I�u�W�F�N�g���A�j���[�V���������� |
| Attach | public | HWND��CWnd�Ɋ֘A�Â��� |
| Detach | public | CWnd����HWND��؂藣�� |

