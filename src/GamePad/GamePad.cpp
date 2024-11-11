#include "GamePad.h"

//�p�b�h�̓��͕ϐ�
DINPUT_JOYSTATE PadcurrentBuf;	//�p�b�h�̌��݃t���[�����i�[�ϐ�
DINPUT_JOYSTATE PadpreBuf;		//�p�b�h�̉ߋ��t���[�����i�[�ϐ�

//������
void CGamePad::InitGamePad()
{
	memset(&PadcurrentBuf, 0, sizeof(DINPUT_JOYSTATE));
	memset(&PadpreBuf, 0, sizeof(DINPUT_JOYSTATE));
}


//���͐���X�e�b�v
void CGamePad::StepGamePad()
{
	//�ߋ��̓��͏����i�[
	PadpreBuf = PadcurrentBuf;

	//���݂̃p�b�h���͏����擾
	GetJoypadDirectInputState(DX_INPUT_PAD1, &PadcurrentBuf);
}


//�������ꂽ
bool CGamePad::IsPadPush(int InputType, int Key_code)
{
	//�O�t���[��������Ă��Ȃ������݃t���[���ŉ�����Ă���
	if (PadpreBuf.Buttons[Key_code] == 0 && PadcurrentBuf.Buttons[Key_code] == 128)
		return true;

	//������Ă��Ȃ��̂� false
	return false;
}

//�����Ɖ�����Ă���
bool CGamePad::IsPadKeep(int InputType, int Key_code)
{
	//�O�t���[��������Ă��邩���݃t���[���ŉ�����Ă���
	if (PadpreBuf.Buttons[Key_code] == 128 && PadcurrentBuf.Buttons[Key_code] == 128)
		return true;

	//������Ă��Ȃ��̂� false
	return false;
}

//�L�[�𗣂���
bool CGamePad::IsPadRelease(int InputType, int Key_code)
{
	//�O�t���[��������Ă��Ȃ������݃t���[���ŉ�����Ă��Ȃ�
	if (PadpreBuf.Buttons[Key_code] == 128 && PadcurrentBuf.Buttons[Key_code] == 0)
		return true;

	//������Ă��Ȃ��̂� false
	return false;
}

//�P���ɉ�����Ă��邩
bool CGamePad::IsPadDown(int InputType, int Key_code)
{
	//���݃t���[���ŉ�����Ă���(�O�t���[���͊֌W�Ȃ�)
	if (PadcurrentBuf.Buttons[Key_code] == 128)
		return true;

	//������Ă��Ȃ��̂� false
	return false;
}



