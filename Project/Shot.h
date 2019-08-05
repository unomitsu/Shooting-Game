#pragma once

#include "Object.h"

class Shot : public Object {
	// int size;		// 画像サイズ
	bool image;			// どちらの画像か、trueが赤、falseが青
	static int image1;	// 画像ハンドル1
	static int image2;	// 画像ハンドル2

	void SetImage();	// 画像関連の設定

public:
	// double x, y;
	// int hit_size;	// あたり判定のサイズ
	// bool flag;		// 有効フラグ
	double xv, yv;		// 増加量

	Shot();
	void Update();					// 更新
	void Draw();					// 描画
	void CollisionResult();			// 当たり判定後の処理

	void Shoot(double nx, double ny, double nxv, double nvy, bool fimg);	// 座標、速度、画像を指定し発射する
};