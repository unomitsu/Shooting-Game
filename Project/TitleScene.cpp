#include "DxLib.h"
#include "TitleScene.h"
#include "Info.h"

TitleScene::TitleScene() {
	SetBackgroundColor(100, 100, 100);	// �w�i���D�F�ɂ��܂�
	wait = 30;
}
bool TitleScene::Update() {
	// �X�y�[�X�L�[����������Atrue��ԋp
	if (wait-- < 0 && GetKey(KEY_INPUT_SPACE)) { return true; }
	return false;
}

void TitleScene::Draw() {
	DrawFormatString(200, 200, GetColor(255, 255, 255), "�^�C�g���ł�.");
	DrawFormatString(200, 400, GetColor(255, 255, 255), "�X�y�[�X�L�[�������Ă�������.");
}