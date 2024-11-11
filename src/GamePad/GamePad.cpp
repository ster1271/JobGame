#include "GamePad.h"

//パッドの入力変数
DINPUT_JOYSTATE PadcurrentBuf;	//パッドの現在フレーム情報格納変数
DINPUT_JOYSTATE PadpreBuf;		//パッドの過去フレーム情報格納変数

//初期化
void CGamePad::InitGamePad()
{
	memset(&PadcurrentBuf, 0, sizeof(DINPUT_JOYSTATE));
	memset(&PadpreBuf, 0, sizeof(DINPUT_JOYSTATE));
}


//入力制御ステップ
void CGamePad::StepGamePad()
{
	//過去の入力情報を格納
	PadpreBuf = PadcurrentBuf;

	//現在のパッド入力情報を取得
	GetJoypadDirectInputState(DX_INPUT_PAD1, &PadcurrentBuf);
}


//今押された
bool CGamePad::IsPadPush(int InputType, int Key_code)
{
	//前フレーム押されていないかつ現在フレームで押されている
	if (PadpreBuf.Buttons[Key_code] == 0 && PadcurrentBuf.Buttons[Key_code] == 128)
		return true;

	//押されていないので false
	return false;
}

//ずっと押されている
bool CGamePad::IsPadKeep(int InputType, int Key_code)
{
	//前フレーム押されているかつ現在フレームで押されている
	if (PadpreBuf.Buttons[Key_code] == 128 && PadcurrentBuf.Buttons[Key_code] == 128)
		return true;

	//押されていないので false
	return false;
}

//キーを離した
bool CGamePad::IsPadRelease(int InputType, int Key_code)
{
	//前フレーム押されていないかつ現在フレームで押されていない
	if (PadpreBuf.Buttons[Key_code] == 128 && PadcurrentBuf.Buttons[Key_code] == 0)
		return true;

	//押されていないので false
	return false;
}

//単純に押されているか
bool CGamePad::IsPadDown(int InputType, int Key_code)
{
	//現在フレームで押されている(前フレームは関係ない)
	if (PadcurrentBuf.Buttons[Key_code] == 128)
		return true;

	//押されていないので false
	return false;
}



