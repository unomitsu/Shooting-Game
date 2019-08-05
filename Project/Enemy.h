#pragma once
#include "Object.h"

// エネミークラス
class Enemy : public Object {
private:
	// int size;		// 画像サイズ
	static int image;	// 画像ハンドル

	void SetImage();	// 画像関連の設定

public:
	// double x, y;		// x座標、y座標
	// int hit_size;	// あたり判定のサイズ
	// bool flag;		// 有効フラグ
	double xv, yv;		// x方向の増加量、y方向の増加量
	int hp_now, hp_max;	// 体力(現在値、最大値)

	Enemy();
	void Update();	// 更新
	void Draw();	// 描画
	void CollisionResult();		// 当たり判定後の処理
};