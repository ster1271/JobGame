#include "GamePad.h"

//�p�b�h�̓��͕ϐ�
DINPUT_JOYSTATE PadInput;

unsigned char GAME_PAD_A = 0;
unsigned char GAME_PAD_B = 0;
unsigned char GAME_PAD_X = 0;
unsigned char GAME_PAD_Y = 0;


//���݂̃p�b�h���͏����擾
//GetJoypadDirectInputState(DX_INPUT_PAD1, &PadInput);

void CGamePad::InitGamePad()
{
	//�p�b�h���͏��ϐ�������
	memset(&PadInput, 0, sizeof(DINPUT_JOYSTATE));


}


