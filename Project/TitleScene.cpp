#include "DxLib.h"
#include "TitleScene.h"
#include "Info.h"

TitleScene::TitleScene() {
	SetBackgroundColor(100, 100, 100);	// 背景を灰色にします
	wait = 30;
}
bool TitleScene::Update() {
	// スペースキーを押したら、trueを返却
	if (wait-- < 0 && GetKey(KEY_INPUT_SPACE)) { return true; }
	return false;
}

void TitleScene::Draw() {
	DrawFormatString(200, 200, GetColor(255, 255, 255), "タイトルです.");
	DrawFormatString(200, 400, GetColor(255, 255, 255), "スペースキーを押してください.");
}