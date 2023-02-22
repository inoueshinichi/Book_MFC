### �Q�l


### ���[�J�[�X���b�h�̍쐬
AfxBeginThread�֐�
```
CWinThread* AfxBeginThread(
               AFX_THREADPROC, // ���[�J�[�X���b�h����֐�
               LPVOID, // ���[�J�[�X���b�h����֐��ɓn������
               int = THREAD_PRIORITY_NORMAL, // �D��x
               UINT = 0, // �X�^�b�N�T�C�Y(0�͐e�v���Z�X�Ɠ���)
               DWORD = 0, // �X���b�h�̐���ǉ��t���O(0: �N��, CREATE_SUSPEND(1):�ҋ@���)
               LPSECURITY_ATTRIBUTES = NULL // �Z�L�����e�B����
            )
```
���[�J�[�X���b�h�̐���֐�(static�֐�)
```
static UINT �֐���(LPVOID ����)
```

### �D��x
| �ݒ�l | ���e |
| :-- | :-- |
| THREAD_PRIORITY_ABOVE_NORMAL | �X���b�h�W���̑��ΗD�揇�ʒl���+1�����D��x |
| THREAD_PRIORITY_BELOW_NORMAL | �X���b�h�W���̑��ΗD�揇�ʒu���-1�Ⴂ�D��x |
| THREAD_PRIORITY_HIGHEST | �X���b�h�W���̑��ΗD�揇�ʒl���+2�����D��x |
| THREAD_PRIORITY_LOWEST | �X���b�h�W���̑��ΗD�揇�ʒl���-2�Ⴂ�D��x |
| THREAD_PRIORITY_NORMAL | �X���b�h�W���̑��ΗD�揇�ʒl |

### �X���b�h�̐���ǉ��t���O
| �ݒ�l | ���e |
| :-- | :-- |
| CREATE_SUSPENDED | �X���b�h�������͒�~��� |
| 0 | �X���b�h�������͋N����� |
+ CREATE_SUSPENDED���w�肵���ꍇ`CWinThread::ResumeThread()`���Ăяo���ƋN����ԂɂȂ�


### �Z�L�����e�B����
+ �����w�肵�Ȃ��ꍇ�v���Z�X�Ɠ��������ƂȂ�

### �ҋ@(����)�pWaitForSingleObject�֐�
```
DWORD WaitForSingleObject(HANDLE, DWORD);
```
+ �߂�l(DWORD) : �҂���Ԃ���߂�������
+ ����(HANDLE)  : �I�u�W�F�N�g�n���h��
+ ����(DWORD)   : �^�C���A�E�g����

�^�C���A�E�g����  
+ �~���b�P�ʂŎw��. 
+ 0�ŃI�u�W�F�N�g�̏�Ԃ��擾���đ����ɐ����߂�. 
+ INFINIT�Ŗ����ɑ҂�.

### �߂�l(�҂���Ԃ���߂�������)
| �߂�l | ���e |
| :-- | :-- |
| WAIT_ABANDONED | ���ɏ������I�����Ă��� |
| WAIT_OBJECT_0 | �������I������ |
| WAIT_TIMEOUT | �^�C���A�E�g���Ԃ��o�߂���(�X���b�h�̏�Ԃ킩��Ȃ�) |

### AfxBeginThread�֐����g�p����ۂ̒��ӓ_
+ ���������(�߂�l)CWinThread�N���X�̃C���X�^���X��, �X���b�h�I�����Ɏ����I�ɔj�������̂�, ����ɔ���, �X���b�h�n���h��(HANDLE)�������Ă��܂�.
+ �X���b�h��Ԃ����I�ɒ��ׂ�(Peek)��������̍ۂ�, WaitForSingleObject()�Ŗ����n���h�����󂯎���ăA�v�����ُ�I�����Ă��܂�.
+ �n���h���������폜�����Ȃ��悤�ɂ��邽�߂�, �X���b�h��ҋ@���(CREATE_SUSPEND)�ŋN������, `CWinThread�C���X�^���X.m_bAutoDelete = false;`�Ɛݒ肷��._
+ CWinThread�C���X�^���X(�y�уX���b�h�n���h��)�������폜�����Ȃ��ꍇ, �C���X�^���X�̍폜���v���O���}�[���Ŗ��L����.
+ �X���b�h�̃T�X�y���h������������@`DWORD suspendCount = CWinThread�C���X�^���X.ResumeThread();` 
+ CWinThread(�X���b�h)�̓T�X�y���h�J�E���g�Ƃ����J�E���^�[�������Ă���. 0�ŋN��, +1�őҋ@. ResumeThread()��-1����֐�.