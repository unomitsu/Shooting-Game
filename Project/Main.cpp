#include "DxLib.h"
#include "Info.h"
#include "TitleScene.h"
#include "MainScene.h"
#include "ResultScene.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	// ＤＸライブラリ初期化処理、エラーが起きたら直ちに終了
	if (DxLib_Init() == -1) { return -1; }

	// ウィンドウモードで起動、拡大して表示する
	ChangeWindowMode(TRUE);
	SetWindowSizeExtendRate(1.5);

	// アニメーションのちらつきを消すために、描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	// Scene の初期化
	TitleScene ts = TitleScene();
	MainScene ms = MainScene();
	ResultScene rs = ResultScene();
	
	// ProcessMessage()		Windowsアプリのプログラムの、メッセージ(イベント)処理をしてくれる。成功で0、失敗で-1。
	// ScreenFlip()			裏画面の内容を表画面に反映する。成功で0、エラーで-1。
	// ClearDrawScreen()	描画先の画面に書かれたものを消去する。成功で0、エラーで-1。
	while (ProcessMessage() == 0 && ScreenFlip() == 0 && ClearDrawScreen() == 0) {
		KeyUpdate();	// キーの入力更新
		if (GetKey(KEY_INPUT_ESCAPE)) { break; }	// ゲーム終了

		int t = 0;
		switch (GetGameScene()) {
		case 0:
			if (ts.Update()) {
				ms = MainScene();
				SetGameScene(1);
				break;
			}
			ts.Draw();
			break;
		case 1:
			if((t = ms.Update()) != 0) { SetGameScene(t); }
			ms.Draw();
			break;
		default:
			if (rs.Update()) {
				ts = TitleScene();
				SetGameScene(0);
				break;
			}
			rs.Draw();
			break;
		}
	}
	
	DxLib_End();		// ＤＸライブラリ使用の終了処理
	return 0;			// ソフトの終了 
}

