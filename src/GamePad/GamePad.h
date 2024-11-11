#pragma once
#include "DxLib.h"

//コントローラーボタン
enum PAD_BUTTON
{
	BUTTON_A = 0,	//A
	BUTTON_B,		//B
	BUTTON_X,		//X
	BUTTON_Y,		//Y
	BUTTON_LB,		//LB
	BUTTON_RB,		//RB
	BUTTON_START,	//スタートボタン
	BUTTON_LSTICK,	//左スティック押し込み
	BUTTON_RSTICK,	//右スティック押し込み

	BUTTON_NUM,		//ボタンの総番号
};

class CGamePad
{
private:

public:
	//入力制御初期化
	static void InitGamePad();

	//入力制御ステップ
	static void StepGamePad();

	//今押された
	static bool IsPadPush(int InputType, int Key_code);

	//ずっと押されている
	static bool IsPadKeep(int InputType, int Key_code);

	//キーを離した
	static bool IsPadRelease(int InputType, int Key_code);

	//単純に押されているか
	static bool IsPadDown(int InputType, int Key_code);

	//

	//左スティック
	static bool LStick();

	//右スティック
	static bool RStick();
};
