#include "DxLib.h"
#include "Enemy.h"
#include "Info.h"

int Enemy::image;

Enemy::Enemy() {
	x = GetWidth() / 2;		// x座標の初期化
	y = 50.0;				// y座標の初期化
	xv = yv = 0.0;			// 増加量
	hp_now = hp_max = 100;	// 体力
	flag = true;			// 有効フラグを立てる
	this->SetImage();		// 画像関連の設定
}

void Enemy::Update() {
	x += xv;
	y += yv;
}

void Enemy::Draw() {
	// エネミーの画像の描画
	DrawGraph((int)(x - size / 2), (int)(y - size / 2), image, TRUE);
}
// 当たり判定後の処理
void Enemy::CollisionResult() {
	if (hp_now-- < 0) {
		flag = false;
	}
}

// 画像関連の設定
void Enemy::SetImage() {
	size = 64;
	hit_size = 32;
	image = LoadGraph("./images/enemy.png");
}