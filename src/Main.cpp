#include "DxLib.h"
#include "Common.h"
#include "DrawFPS/fps.h"
#include "Input/Input.h"
#include "Scene/SceneManager.h"


// Win32アプリケーションは WinMain関数 から始まる
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウの状態を設定する
	ChangeWindowMode(true);

	//DXライブラリの初期化
	if (DxLib_Init() == -1) {
		return -1;
	}

	// 画面サイズを変更
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//描画するスクリーンを設定する
	SetDrawScreen(DX_SCREEN_BACK);
	
	//-----------------------------------------
	//一番最初に１回だけやる処理をここに書く
	
	//インプット初期化
	CInput::InitInput();

	//シーンマネージャー
	SceneManager cSceneManager;

	//FPS
	CFps cFps;

	//初期化
	cFps.Init();

	

	//-----------------------------------------

	//ゲームメインループ
	while (ProcessMessage() != -1)
	{
		Sleep(1);	//システム処理を返す

		//現在の時間を取得
		cFps.frameRateInfo.currentTime = GetNowCount();

		//最初のループなら
		//現在の時間を、FPSの計算をした時間に設定
		if (cFps.frameRateInfo.calcFpsTime == 0.0f)
		{
			cFps.frameRateInfo.calcFpsTime = cFps.frameRateInfo.currentTime;
			cFps.frameRateInfo.fps = (float)FRAME_RATE;
		}

		//現在の時間が、前回のフレーム時より
		//1000/60ミリ秒（1/60）以上経過したいたら処理を実行する
		if (cFps.frameRateInfo.currentTime - cFps.frameRateInfo.LastFrameTime >= FRAME_TIME)
		{
			//フレーム実行時の時間を更新
			cFps.frameRateInfo.LastFrameTime = cFps.frameRateInfo.currentTime;

			//フレーム数をカウント
			cFps.frameRateInfo.g_count++;

			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			{
				//エスケープキーが押されたら終了
				break;
			}

			//画面に表示されたものを初期化
			ClearDrawScreen();

			CInput::StepInput();

			//-----------------------------------------
			//ここからゲームの本体を書くことになる
			//-----------------------------------------

			//計算処理
			cSceneManager.Loop();


			//描画処理
			cSceneManager.Draw();

			//FPS計算
			cFps.CalcFPS();

			//FPS表示
			cFps.DrawFPS();

			//-----------------------------------------
			//ループの終わりに
			//フリップ関数
			ScreenFlip();

		}
	}

	//-----------------------------------------
	//最後に１回だけやる処理をここに書く

	//-----------------------------------------
	//DXライブラリの後処理
	DxLib_End();

	return 0;
}

