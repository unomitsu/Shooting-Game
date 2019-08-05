#include "DxLib.h"
#include "Info.h"
#include "TitleScene.h"
#include "MainScene.h"
#include "ResultScene.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	// �c�w���C�u���������������A�G���[���N�����璼���ɏI��
	if (DxLib_Init() == -1) { return -1; }

	// �E�B���h�E���[�h�ŋN���A�g�債�ĕ\������
	ChangeWindowMode(TRUE);
	SetWindowSizeExtendRate(1.5);

	// �A�j���[�V�����̂�������������߂ɁA�`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	// Scene �̏�����
	TitleScene ts = TitleScene();
	MainScene ms = MainScene();
	ResultScene rs = ResultScene();
	
	// ProcessMessage()		Windows�A�v���̃v���O�����́A���b�Z�[�W(�C�x���g)���������Ă����B������0�A���s��-1�B
	// ScreenFlip()			����ʂ̓��e��\��ʂɔ��f����B������0�A�G���[��-1�B
	// ClearDrawScreen()	�`���̉�ʂɏ����ꂽ���̂���������B������0�A�G���[��-1�B
	while (ProcessMessage() == 0 && ScreenFlip() == 0 && ClearDrawScreen() == 0) {
		KeyUpdate();	// �L�[�̓��͍X�V
		if (GetKey(KEY_INPUT_ESCAPE)) { break; }	// �Q�[���I��

		int t = 0;
		switch (GetGameScene()) {
		case 0:
			if (ts.Update()) {
				ms = MainScene();
				SetGameScene(1);
				break;
			}
			ts.Draw();
			break;
		case 1:
			if((t = ms.Update()) != 0) { SetGameScene(t); }
			ms.Draw();
			break;
		default:
			if (rs.Update()) {
				ts = TitleScene();
				SetGameScene(0);
				break;
			}
			rs.Draw();
			break;
		}
	}
	
	DxLib_End();		// �c�w���C�u�����g�p�̏I������
	return 0;			// �\�t�g�̏I�� 
}

