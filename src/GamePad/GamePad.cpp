#include "GamePad.h"

//�p�b�h�̓��͕ϐ�
DINPUT_JOYSTATE PadcurrentBuf;	//�p�b�h�̌��݃t���[�����i�[�ϐ�
DINPUT_JOYSTATE PadpreBuf;		//�p�b�h�̉ߋ��t���[�����i�[�ϐ�

#define NUM		(4500)

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
	if (PadpreBuf.Buttons[Key_code] == 0 && PadcurrentBuf.Buttons[Key_code] != 0)
		return true;

	//������Ă��Ȃ��̂� false
	return false;
}

//�����Ɖ�����Ă���
bool CGamePad::IsPadKeep(int InputType, int Key_code)
{
	//�O�t���[��������Ă��邩���݃t���[���ŉ�����Ă���
	if (PadpreBuf.Buttons[Key_code] != 0 && PadcurrentBuf.Buttons[Key_code] != 0)
		return true;

	//������Ă��Ȃ��̂� false
	return false;
}

//�L�[�𗣂���
bool CGamePad::IsPadRelease(int InputType, int Key_code)
{
	//�O�t���[��������Ă��Ȃ������݃t���[���ŉ�����Ă��Ȃ�
	if (PadpreBuf.Buttons[Key_code] != 0 && PadcurrentBuf.Buttons[Key_code] == 0)
		return true;

	//������Ă��Ȃ��̂� false
	return false;
}

//�P���ɉ�����Ă��邩
bool CGamePad::IsPadDown(int InputType, int Key_code)
{
	//���݃t���[���ŉ�����Ă���(�O�t���[���͊֌W�Ȃ�)
	if (PadcurrentBuf.Buttons[Key_code] != 0)
		return true;

	//������Ă��Ȃ��̂� false
	return false;
}


//LT��RT�̐���
bool CGamePad::IsPush_LR(CHECK check)
{
	//�ߋ��t���[���ŉ�����Ă��Ȃ���
	if (PadpreBuf.Z == 0)
	{
		switch (check)
		{
		case LEFT:
			//�l��0���傫���Ƃ�
			if (PadcurrentBuf.Z != 0 && PadcurrentBuf.Z > 0)
			{
				return true;
			}
			break;

		case RIGHT:
			//�l��0��菬�����Ƃ�
			if (PadcurrentBuf.Z != 0 && PadcurrentBuf.Z < 0)
			{
				return true;
			}
			break;
		default:
			break;
		}	
	}

	//������Ă��Ȃ��̂� false
	return false;
}


//LT��RT�̐���(������)
bool CGamePad::IsKeep_LR(CHECK check)
{
	//�ߋ��t���[���ŉ�����Ă��邩
	if (PadpreBuf.Z != 0)
	{
		switch (check)
		{
		case LEFT:
			//�l��0���傫���Ƃ�
			if (PadcurrentBuf.Z != 0 && PadcurrentBuf.Z > 0)
			{
				return true;
			}
			break;

		case RIGHT:
			//�l��0��菬�����Ƃ�
			if (PadcurrentBuf.Z != 0 && PadcurrentBuf.Z < 0)
			{
				return true;
			}
			break;
		default:
			break;
		}
	}

	//������Ă��Ȃ��̂� false
	return false;
}


//�\���L�[�̐���
bool CGamePad::IsPush_Cross(CHECK check)
{
	int TOTAL = NUM * check;

	//�ߋ��t���[���ŉ�����Ă��Ȃ���
	if(PadpreBuf.POV[0] == -1)
	{
		if (PadcurrentBuf.POV[0] == TOTAL)
		{
			return true;
		}
	}

	return false;
}

//�\���L�[�̐���(������)
bool CGamePad::IsKeep_Cross(CHECK check)
{
	int TOTAL = NUM * check;

	//�ߋ��t���[���ŉ�����Ă��Ȃ���
	if (PadpreBuf.POV[0] != -1)
	{
		if (PadcurrentBuf.POV[0] == TOTAL)
		{
			return true;
		}
	}

	return false;
}


//���X�e�B�b�N
bool CGamePad::LStick()
{
	if (PadcurrentBuf.X != 0 || PadcurrentBuf.Y != 0)
	{

		return true;
	}

	return false;
}

//�E�X�e�B�b�N
bool CGamePad::RStick()
{
	return true;
}
