#pragma once

#include "Player.h"
#include "Enemy.h"
#include "Shot.h"
#include <vector>

// ステージシーンクラス
class MainScene {
private:
	Player *player;
	Enemy *enemy;

	int enemy_span;					// 弾の発射間隔
	double enemy_shot_base;			// 発射角度
	std::vector<Shot> enemy_shot;	// 敵機のショット配列

public:
	MainScene();
	int Update();	// 更新
	void Draw();	// 描画

	void StageInitialize();			// パラメータの初期化
	void StageUpdate();				// 敵機のショットの発射を実装する
};

