#include "DxLib.h"
#include "Info.h"
#include <math.h>

// Info
int g_Width, g_Height;	// ウィンドウの横幅と縦幅
int g_StageTime;		// ステージシーンに変わってからの経過時間

// Key
static const int KEY_NUM = 256;		// キー配列の最大値
char g_Buf[KEY_NUM];				// キーの状態を保持する配列

int g_GameScene;					// シーン管理用

// 各データの初期化
void InfoInitialize() {
	GetScreenState(&g_Width, &g_Height, NULL);
	g_StageTime = 0;
	g_GameScene = 0;
}
// 各データの更新
void InfoUpdate() {
	g_StageTime++;
}

// ウィンドウの横幅を返す
int GetWidth() {
	return g_Width;
}
// ウィンドウの縦幅を返す
int GetHeight() {
	return g_Height;
}
// ステージが開始されてからの経過時間を得る
int GetStageTime() {
	return g_StageTime;
}

// 全キーの状態を更新する
void KeyUpdate() {
	GetHitKeyStateAll(g_Buf);
}
// 指定したキーの状態を取得する
bool GetKey(int key_code) {
	if (g_Buf[key_code]) { return true; }
	return false;
}

// 2オブジェクトのあたり判定
void Collision(Object *obj1, Object *obj2) {
	double dx = obj1->x - obj2->x;
	double dy = obj1->y - obj2->y;
	double ds = obj1->hit_size + obj2->hit_size;

	// 有効フラグが立っているかの確認
	if (!obj1->flag || !obj2->flag) {
		return;
	}

	// 三平方の定理を使用
	if (pow(dx, 2) + pow(dy, 2) <= pow(ds, 2)) {
		// あたり判定後の処理
		obj1->CollisionResult();
		obj2->CollisionResult();
	}
}

// ゲームシーンの取得
int GetGameScene() {
	return g_GameScene;
}
// ゲームシーンの設定
void SetGameScene(int val) {
	g_GameScene = val;
}
