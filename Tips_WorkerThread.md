### �Q�l


### ���[�J�[�X���b�h�̍쐬
AfxBeginThread�֐�
```
CWinThread* AfxBeginThread(
               AFX_THREADPROC, // ���[�J�[�X���b�h����֐�
               LPVOID, // ���[�J�[�X���b�h����֐��ɓn������
               int = THREAD_PRIORITY_NORMAL, // �D��x
               UINT = 0, // �X�^�b�N�T�C�Y(0�͐e�v���Z�X�Ɠ���)
               DWORD = 0, // �X���b�h�̐���ǉ��t���O
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

### �ҋ@�֐�WaitForSingleObject
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

�߂�l(�҂���Ԃ���߂�������)
   
| �߂�l | ���e |
| :-- | :-- |
| WAIT_ABANDONED | ���ɏ������I�����Ă��� |
| WAIT_OBJECT_0 | �������I������ |
| WAIT_TIMEOUT | �^�C���A�E�g���Ԃ��o�߂���(�X���b�h�̏�Ԃ킩��Ȃ�) |

 