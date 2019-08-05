#pragma once

// オブジェクトクラス player, enemy, shot
class Object {
protected:
	int size;		// 画像サイズ

public:
	double x, y;	// x座標、y座標
	int hit_size;	// あたり判定のサイズ
	bool flag;		// 有効フラグ

	virtual void Update() {}	// 更新
	virtual void Draw() {}		// 描画
	virtual void CollisionResult() {}	// 当たり判定後の処理
};

