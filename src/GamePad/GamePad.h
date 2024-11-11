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

//十字ボタンとLT、RTの判定用
enum CHECK
{
	UP,		//上
	UP_R,	//右上
	RIGHT,	//右
	DOWN_R,	//右下
	DOWN,	//下
	DOWN_L,	//左下
	LEFT,	//左
	UP_L,	//左上
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

	//LTとRTの制御
	static bool IsPush_LR(CHECK check);

	//LTとRTの制御
	static bool IsKeep_LR(CHECK check);

	//十字キーの制御
	static bool IsPush_Cross(CHECK check);

	//十字キーの制御
	static bool IsKeep_Cross(CHECK check);

	//左スティック
	static bool LStick();

	//右スティック
	static bool RStick();
};
