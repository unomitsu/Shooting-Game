#pragma once
#include "Object.h"
#include "Shot.h"

// プレイヤークラス
class Player : public Object {
private:
	// int size;			// 画像サイズ
	static int image;		// 画像ハンドル

	int shot_num;			// ショット 現在の配列の添字
	int shot_span;			// ショット 発射間隔

	void SetImage();	// 画像関連の設定
	void SetShot();		// ショット関連の設定
	void Move();		// プレイヤー操作
	void ShotFire();	// プレイヤーショット発射

public:
	// double x, y;
	// int hit_size;		// あたり判定のサイズ
	// bool flag;			// 有効フラグ
	double v;			// 移動速度
	int hp_now, hp_max;	// 体力(現在値、最大値)

	static const int shot_max = 20;	// ショット配列の要素数
	Shot shot[shot_max];	// ショット配列

	Player();
	void Update();		// 更新
	void Draw();		// 描画
	void CollisionResult();		// 当たり判定後の処理
};
