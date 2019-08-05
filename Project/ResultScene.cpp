#include "DxLib.h"
#include "ResultScene.h"
#include "Info.h"

bool ResultScene::Update() {
	if (GetKey(KEY_INPUT_SPACE)) { return true; }	// ���C���V�[���֑J��
	return false;
}

void ResultScene::Draw() {
	// �Q�[���N���A��
	if (GetGameScene() == 2) {
		SetBackgroundColor(255, 255, 255);	// �w�i�𔒐F�ɂ��܂�
		DrawFormatString(300, 200, GetColor(0, 0, 0), "�Q�[���N���A !!");
	}
	// �Q�[���I�[�o�[��
	else {
		SetBackgroundColor(255, 100, 100);	// �w�i��ԐF�ɂ��܂�
		DrawFormatString(300, 200, GetColor(0, 0, 0), "�Q�[���I�[�o�[...");
	}
	DrawFormatString(300, 360, GetColor(0, 0, 0), "�X�y�[�X�L�[��������");
	DrawFormatString(300, 380, GetColor(0, 0, 0), "�^�C�g���ɖ߂�܂�.");
	DrawFormatString(300, 420, GetColor(0, 0, 0), "�I���ɂ́AESC�L�[.");
}