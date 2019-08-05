#include "DxLib.h"
#include "MainScene.h"
#include "Info.h"

#define _USE_MATH_DEFINES
#include <math.h>

MainScene::MainScene() {
	SetBackgroundColor(100, 100, 100);	// 背景を灰色にします
	InfoInitialize();		// ウィンドウサイズなどの初期化
	player = new Player();		// プレイヤーの初期化
	enemy = new Enemy();		// エネミーの初期化
	StageInitialize();
}

int MainScene::Update() {
	InfoUpdate();			// 各データの更新
	player->Update();		// プレイヤーの操作
	enemy->Update();		// エネミーの更新

	// ショットの更新
	for (auto itr = enemy_shot.begin(); itr != enemy_shot.end();) {
		// 無効な要素を削除
		if (!(*itr).flag) {
			itr = enemy_shot.erase(itr);
		}
		// 有効な要素の更新
		else {
			(*itr).Update();
			itr++;
		}
	}

	StageUpdate();	// ステージの更新

	// あたり判定
	// プレイヤーショットとエネミー
	for (int i = 0; i < player->shot_max; i++) {
		Collision(static_cast<Object*>(&player->shot[i]), static_cast<Object*>(enemy));
	}
	// プレイヤーとエネミーショット
	for (auto itr = enemy_shot.begin(); itr != enemy_shot.end(); itr++) {
		Collision(static_cast<Object*>(player), static_cast<Object*>(&(*itr)));
	}

	// 終了判定
	if (player->hp_now <= 0) { return 3; }
	if (enemy->hp_now <= 0) { return 2; }
	return 0;
}

void MainScene::Draw() {
	player->Draw();		// プレイヤーの描画
	enemy->Draw();		// エネミーの描画

	// ショットの更新
	for (auto itr = enemy_shot.begin(); itr != enemy_shot.end(); ++itr) {
		(*itr).Draw();
	}

	DrawFormatString(GetWidth()/2 - 40, 0, GetColor(255, 255, 255), "Time : %d", GetStageTime());	// 経過時間の描画
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Player : %d", player->hp_now);					// プレイヤーHP
	DrawFormatString(GetWidth() - 120, 0, GetColor(255, 255, 255), "Enemy : %d", enemy->hp_now);	// エネミーHP
	DrawFormatString(200, 200, GetColor(255, 255, 255), "shotnum : %d", enemy_shot.size());	// エネミーHP
}

// 
void MainScene::StageInitialize() {
	enemy_span = 0;
	enemy_shot_base = 0;
}

void MainScene::StageUpdate() {
	// 体力が半分以上の時
	if (enemy->hp_now > enemy->hp_max / 2) {
		if (enemy_span++ >= 50) {
			double shot_v = 2.0;
			int shot_num = 36;

			for (int i = 0; i < shot_num; i++) {
				double angle = enemy_shot_base + M_PI / 18 * i;

				enemy_shot.push_back(Shot());
				enemy_shot.back().Shoot(
					enemy->x, enemy->y, shot_v * cos(angle), shot_v * sin(angle), true
				);
			}
			enemy_shot_base += 0.1;
			enemy_span = 0;
		}
	}
	// 体力が半分以下の時
	else {
		double shot_v = 1.0 + GetRand(40) / 10.0;
		int shot_num = 2;

		for (int i = 0; i < shot_num; i++) {
			double angle = M_PI * (GetRand(3600) / 10.0) / 180;

			enemy_shot.push_back(Shot());
			enemy_shot.back().Shoot(
				enemy->x, enemy->y, shot_v * cos(angle), shot_v * sin(angle), true
			);
		}
	}
}
