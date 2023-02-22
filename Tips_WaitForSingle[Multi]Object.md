### �Q�l
+ https://learn.microsoft.com/ja-jp/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject
+ https://learn.microsoft.com/ja-jp/windows/win32/api/synchapi/nf-synchapi-waitforsingleobjectex
+ https://learn.microsoft.com/ja-jp/windows/win32/api/synchapi/nf-synchapi-waitformultipleobjects
+ https://learn.microsoft.com/ja-jp/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject


### WaitForSingle[Multi]Object[s][Ex]�̊T�v 
| �֐� | �p�r |
| :-- | :-- |
| DWORD WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds) | �P�̃I�u�W�F�N�g��ҋ@ |
| DWORD WaitForSingleObjectEx(HANDLE hHandle, DWORD dwMilliseconds, BOOL bAlertable) | �A���[�g�\�ȑҋ@��Ԃ�񋟂��� |
| DWORD WaitForMultipleObjects(DWORD nCount, const HANDLE *lpHandles, BOOL bWaitAll, DWORD dwMilliseconds) | �����I�u�W�F�N�g�̑ҋ@ |
| DWORD WaitForMultipleObjects(DWORD nCount, const HANDLE *lpHandles, BOOL bWaitAll, DWORD dwMilliseconds, BOOL bAlertable) | �A���[�g�\�ȕ����I�u�W�F�N�g�ɑ΂���ҋ@��Ԃ�� |

### �ҋ@�ł���I�u�W�F�N�g�ꗗ
| �I�u�W�F�N�g | ���e |
| :-- | :-- |
| �ύX�ʒm | - |
| �R���\�[������ | - |
| Event | - |
| ������ ���\�[�X�ʒm | - |
| Mutex | - |
| Process | - |
| Semaphore | - |
| Thread | - |
| �ҋ@�\�^�C�}�[ | - |

### �ҋ@�I������
| �֐� | �ҋ@�I������ |
| :-- | :-- |
| WaitForSingleObject | �w��I�u�W�F�N�g���V�O�i����ԂɂȂ� or �^�C���A�E�g���Ԃ��o�߂��� |
| WaitForSingleObjectEx | �w��I�u�W�F�N�g��, , �V�O�i����ԂɂȂ� or I/O�������[�`���܂��̓��[�U�[���[�h�񓯊��v���V�[�W���Ăяo��(APC)���X���b�h�̃L���[�ɓo�^����� or �^�C���A�E�g���Ԃ��o�߂��� |
| WaitForMultiObjects | �w��I�u�W�F�N�g��1�ȏオ, �V�O�i����ԂɂȂ�܂őҋ@���邩 or �^�C���A�E�g�Ԋu���o�߂��� |
| WaitForMultiObjectsEx |  �w��I�u�W�F�N�g��1�ȏオ,  �V�O�i����ԂɂȂ� or I/O�������[�`���܂��̓��[�U�[���[�h�񓯊��v���V�[�W���Ăяo��(APC)���X���b�h�̃L���[�ɓo�^����� or �^�C���A�E�g���Ԃ��o�߂��� |


### ���[�U�[���[�h�񓯊��v���V�[�W��(User-mode APC)
+ ��ʓI��Windows�A�v���P�[�V�����ō쐬����E�B���h�E�Y�v���V�[�W�����ۂ��H(�s���m. �v����)
+ https://learn.microsoft.com/ja-jp/windows/win32/sync/asynchronous-procedure-calls


### WaitForSingleObject�̖߂�l
| �߂�l | ���e |
| :-- | :-- |
| WAIT_ABANDONED(0x00000080L) | ���ɏ������I�����Ă��� |
| WAIT_OBJECT_0(0x00000000L) | �������I������ |
| WAIT_TIMEOUT(0x00000102L) | �^�C���A�E�g���Ԃ��o�߂���(�X���b�h�̏�Ԃ킩��Ȃ�) |
| WAIT_FAILED (DWORD)0xFFFFFFFF | �����s���ȃG���[. ::GetLastError()�֐��ŃV�X�e���̏ڍ׃G���[���m�F���邱�� |

### WaitForSingleObjectEx�̖߂�l
| �߂�l | ���e |
| :-- | :-- |
| WAIT_ABANDONED(0x00000080L) | ���ɏ������I�����Ă��� |
| WAIT_IO_COMPLETION(0x000000C0L) | �X���b�h��(�Ȃ�́H)�L���[��1�ȏ�̔񓯊��v���V�[�W���֐�(APC)��o�^����, ���̌�X���b�h���I������ |
| WAIT_OBJECT_0(0x00000000L) | �������I������ |
| WAIT_TIMEOUT(0x00000102L) | �^�C���A�E�g���Ԃ��o�߂���(�X���b�h�̏�Ԃ킩��Ȃ�) |
| WAIT_FAILED (DWORD)0xFFFFFFFF | �����s���ȃG���[. ::GetLastError()�֐��ŃV�X�e���̏ڍ׃G���[���m�F���邱�� |



### �g�p�̍ۂ̒��ӓ_
���ڂ܂��͊ԐړI�ɃE�B���h�E���쐬����ҋ@�֐��ƃR�[�h���Ăяo���ꍇ�͒��ӂ��K�v.  
�X���b�h���E�B���h�E���쐬����ꍇ��, ���b�Z�[�W����������K�v������. (���b�Z�[�W���[�v�̍쐬) 
OS�̃��b�Z�[�W�u���[�h�L���X�g��, �V�X�e�����̂��ׂẴE�B���h�E�ɑ��M�����̂�, �K�؂Ƀ��b�Z�[�W���[�v���\�z���Ȃ��ƃf�b�h���b�N����.
�X���b�h�쐬����Ƀ��b�Z�[�W���[�v���\�z�����܂őҋ@�ł���@�\���Ȃ���, �V�X�e�����f�b�h���b�N����.
+ �f�b�h���b�N��, �e�X���b�h�����̃X���b�h���������s���̂�҂��Ă���Ƃ��ɔ�������.

���L, ���b�Z�[�W���[�v�\�z���l�������v���O�����̈��  
```
// ���[�J�[�X���b�h�֐�
unsigned int WINAPI WorkerThreadFunc(void *arg)
{
    HANDLE hThreadInitEvent = (HANDLE)arg;

    MSG uMsg;

    // �X���b�h�L���[�̍쐬
    PeekMessage(&uMsg, NULL, 0, 0, PM_NOREMOVE);

    // �C�x���g(False -> True)
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


// ���C���X���b�h��
int main()
{
    HANDLE hThreadInitEvent = ::CreateEvent(NULL, // SECURITY_ATTRIBUTE�\����
                                            TRUE, // ���Z�b�g�̃^�C�v(True:����, False:�蓮)
                                            FALSE, // �������(True:�V�O�i�����, False:��V�O�i�����)
                                            NULL);
    
     // ���[�J�[�X���b�h�쐬
    DWORD nThreadId = 0;
    HANDLE hThread = (HANDLE)::_beginthreadex(NULL, // SECURITY_ATTRIBUTE�\����
                                              0, // �X�^�b�N�T�C�Y(0�͌Ăяo�����Ɠ����T�C�Y)
                                              &WorkerThreadFunc, // ���[�J�X���b�g�֐��|�C���^
                                              (void*)hThreadInitEvent, // �X���b�h�֐��̈���
                                              0, // �쐬�I�v�V���� (0: CREATE_SUSPENDED)
                                              &nThreadId // �X���b�hID (DWORD)
                                              );

    // �X���b�h�L���[�̍쐬�҂�
    ::WaitForSingleObject(hThreadInitEvent, INFINIT);
    // �X���b�h�������C�x���g�̔j��
    ::CloseEvent(hThreadInitEvent);

    // ���[�J�[�X���b�h�ւ̃��b�Z�[�W�̑��M
    PostThreadMessage(nThreadId, ~);

    // ~~~~

    // �X���b�h�I���҂�
    ::WaitForSingleObject(hThread, INFINIT);
    // �X���b�h�C�x���g�̔j��
    ::CloseEvent(hThread);

    // ���[�J�[�X���b�h�̏I����Ԃ��擾
    DWORD dwExitCode;
    ::GetExitCodeThread(hThread, &dwExitCode);
}
```

�������͉��L�̃C�x���g�t���̐�p�ҋ@�֐����g�p����.  
| �֐� | �p�r |
| :-- | :-- |
| DWORD MsgWaitForMultipleObjects(DWORD nCount, const HANDLE *pHandles, BOOL fWaitAll, DWORD dwMilliseconds, DWORD dwWakeMask) | - |
| DWORD MsgWaitForMultipleObjectsEx((DWORD nCount, const HANDLE *pHandles, BOOL fWaitAll, DWORD dwMilliseconds, DWORD dwWakeMask, DWORD dwFlags) | ��L�̃A���[�g�t���ҋ@ |
