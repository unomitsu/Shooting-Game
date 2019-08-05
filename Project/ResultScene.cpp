#include "DxLib.h"
#include "ResultScene.h"
#include "Info.h"

bool ResultScene::Update() {
	if (GetKey(KEY_INPUT_SPACE)) { return true; }	// メインシーンへ遷移
	return false;
}

void ResultScene::Draw() {
	// ゲームクリア時
	if (GetGameScene() == 2) {
		SetBackgroundColor(255, 255, 255);	// 背景を白色にします
		DrawFormatString(300, 200, GetColor(0, 0, 0), "ゲームクリア !!");
	}
	// ゲームオーバー時
	else {
		SetBackgroundColor(255, 100, 100);	// 背景を赤色にします
		DrawFormatString(300, 200, GetColor(0, 0, 0), "ゲームオーバー...");
	}
	DrawFormatString(300, 360, GetColor(0, 0, 0), "スペースキーを押すと");
	DrawFormatString(300, 380, GetColor(0, 0, 0), "タイトルに戻ります.");
	DrawFormatString(300, 420, GetColor(0, 0, 0), "終了には、ESCキー.");
}