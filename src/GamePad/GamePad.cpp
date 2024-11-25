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
bool CGamePad::Stick(STICK stick)
{
	switch (stick)
	{
	case STICK_LX_POS:
		if (PadcurrentBuf.X > 0 && PadcurrentBuf.X <= 1000)
		{
			return true;
		}
		break;

	case STICK_LX_NEG:
		if (PadcurrentBuf.X < 0 && PadcurrentBuf.X >= -1000)
		{
			return true;
		}
		break;

	case STICK_LY_POS:
		if (PadcurrentBuf.Y > 0 && PadcurrentBuf.Y <= 1000)
		{
			return true;
		}
		break;

	case STICK_LY_NEG:
		if (PadcurrentBuf.Y < 0 && PadcurrentBuf.Y >= -1000)
		{
			return true;
		}
		break;

	case STICK_RX_POS:
		if (PadcurrentBuf.Rx > 0 && PadcurrentBuf.Rx <= 1000)
		{
			return true;
		}
		break;

	case STICK_RX_NEG:
		if (PadcurrentBuf.Rx < 0 && PadcurrentBuf.Rx >= -1000)
		{
			return true;
		}
		break;

	case STICK_RY_POS:
		if (PadcurrentBuf.Ry > 0 && PadcurrentBuf.Ry <= 1000)
		{
			return true;
		}
		break;


	case STICK_RY_NEG:
		if (PadcurrentBuf.Ry < 0 && PadcurrentBuf.Ry >= -1000)
		{
			return true;
		}
		break;

	default:
		break;
	}

	return false;
}

//�X�e�B�b�N�p�x�v�Z
float CGamePad::StickRot(STICK stick)
{
	if (stick == STICK_LEFT)
	{
		return (float)atan2(PadcurrentBuf.X, PadcurrentBuf.Y * -1);
	}
	else if (stick == STICK_RIGHT)
	{
		return (float)atan2(PadcurrentBuf.Rx, PadcurrentBuf.Ry * -1);
	}
}

