#pragma once

#include "Object.h"
#include "Player.h"
#include "Enemy.h"

void InfoInitialize();			// 各データの初期化
void InfoUpdate();				// 各データの更新

int GetWidth();					// ウィンドウの横幅を得る
int GetHeight();				// ウィンドウの縦幅を得る
int GetStageTime();				// ステージが開始されてからの経過時間を得る

void KeyUpdate();				// 全キーの状態を更新する
bool GetKey(int key_input);		// 指定したキーの状態を取得する

void Collision(Object *obj1, Object *obj2);		// 2オブジェクトのあたり判定

int GetGameScene();			// ゲームシーンの取得
void SetGameScene(int val);		// ゲームシーンの設定
