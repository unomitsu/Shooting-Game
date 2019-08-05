#include "DxLib.h"
#include "Player.h"
#include "Info.h"
#include <math.h>

int Player::image;

Player::Player() {
	x = y = 200.0;			// 座標の初期化
	v = 4;					// 速度の初期化
	flag = true;			// 有効フラグを立てる
	hp_now = hp_max = 300000;	// 体力の初期化
	this->SetImage();		// 画像関連の設定
	this->SetShot();		// プレイヤーショット関連の設定
}

void Player::Update() {
	Move();			// 移動の更新
	this->ShotFire();		// プレイヤーショットの発射

	for (int i = 0; i < shot_max; i++) {
		shot[i].Update();
	}
}

// 描画
void Player::Draw() {
	DrawGraph((int)(x - size / 2), (int)(y - size / 2), image, TRUE);		// プレイヤーの画像
	DrawCircle((int)x, (int)y, 8, GetColor(200, 100, 100), TRUE, 4);		// あたり判定の大きさ

	for (int i = 0; i < shot_max; i++) {
		shot[i].Draw();
	}
}

// 当たり判定後の処理
void Player::CollisionResult() {
	if (hp_now-- < 0) {
		flag = false;
	}
}

// 画像関連の設定
void Player::SetImage() {
	size = 64;
	hit_size = 8;
	image = LoadGraph("./images/player.png");
}
// ショット関連の設定
void Player::SetShot() {
	shot_num = 0;
	shot_span = 0;
	for (int i = 0; i < shot_max; i++) {
		shot[i] = Shot();
	}
}

// プレイヤー操作
void Player::Move() {
	double nxv = 0, nyv = 0;	// 移動量保持用

	// x方向の移動量の確認
	if (GetKey(KEY_INPUT_LEFT)) { nxv -= v; }
	if (GetKey(KEY_INPUT_RIGHT)) { nxv += v; }

	// y方向の移動量の確認
	if (GetKey(KEY_INPUT_UP)) { nyv -= v; }
	if (GetKey(KEY_INPUT_DOWN)) { nyv += v; }

	// 左シフトを押しているとき半減速
	if (GetKey(KEY_INPUT_LSHIFT)) {
		nxv /= 2; nyv /= 2;
	}
	// 斜め方向の調整
	if (nxv != 0 && nyv != 0) {
		nxv /= sqrt(2); nyv /= sqrt(2);
	}
	// 移動量の加算
	x += nxv;
	y += nyv;

	// 移動範囲の制限、範囲外に出た時は範囲内に戻す
	if (y < 0) { y = 0; }
	if (GetHeight() < y) { y = GetHeight(); }
	if (GetWidth() < x) { x = GetWidth(); }
	if (x < 0) { x = 0; }
}

// ショット発射
void Player::ShotFire() {
	if (GetKey(KEY_INPUT_Z)) {
		// 発射間隔shot_span が 4以上になった時
		if (shot_span++ >= 4) {
			// プレイヤーの位置から弾を発射する
			shot[shot_num++].Shoot(x, y, 0, -8, false);

			// 現在の配列の添字shot_num が要素数shot_max 以上になった時 0 にする
			if (shot_num >= shot_max) { shot_num = 0; }

			// 発射間隔shot_span のリセット
			shot_span = 0;
		}
	}
}