#include "GamePad.h"

//パッドの入力変数
DINPUT_JOYSTATE PadInput;

unsigned char GAME_PAD_A = 0;
unsigned char GAME_PAD_B = 0;
unsigned char GAME_PAD_X = 0;
unsigned char GAME_PAD_Y = 0;


//現在のパッド入力情報を取得
//GetJoypadDirectInputState(DX_INPUT_PAD1, &PadInput);

void CGamePad::InitGamePad()
{
	//パッド入力情報変数初期化
	memset(&PadInput, 0, sizeof(DINPUT_JOYSTATE));


}


