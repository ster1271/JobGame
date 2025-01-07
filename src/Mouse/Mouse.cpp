#include "Mouse.h"

const int MOUSE_BUF = 4;

int MouseX;		//�}�E�XX���W
int MouseY;		//�}�E�XY���W

char currentMouseBuf[MOUSE_BUF] = { 0 };	//���݃t���[���̃}�E�X���i�[
char preMouseBuf[MOUSE_BUF] = { 0 };		//�ߋ��t���[���̃}�E�X���i�[

//���͐��䏉����
void CMouse::InitMouse()
{
	MouseX = MouseY = 0;

	for (int MouseIndex = 0; MouseIndex < MOUSE_BUF; MouseIndex++)
	{
		currentMouseBuf[MouseIndex] = '\0';
		preMouseBuf[MouseIndex] = '\0';
	}
}

//���͐���X�e�b�v
//����Step��葁���Ă�
void CMouse::StepMouse()
{
	//�}�E�X�|�C���^���W�X�V
	GetMousePoint(&MouseX, &MouseY);

	for (int MouseIndex = 0; MouseIndex < MOUSE_BUF; MouseIndex++)
	{
		//�ߋ��t���[���ɏ���n��
		preMouseBuf[MouseIndex] = currentMouseBuf[MouseIndex];
		//���݃t���[�������������Ă���
		currentMouseBuf[MouseIndex] = '\0';
	}

	//���{�^��
	if (GetMouseInput() && MOUSE_INPUT_LEFT != 0)
	{
		currentMouseBuf[0] = 1;
	}
	//�E�{�^��
	if (GetMouseInput() && MOUSE_INPUT_RIGHT != 0)
	{
		currentMouseBuf[1] = 1;
	}
	//�����{�^��
	if (GetMouseInput() && MOUSE_INPUT_MIDDLE != 0)
	{
		currentMouseBuf[3] = 1;
	}
	
}

//�������ꂽ
bool CMouse::IsMousePush(int Mouse_code)
{
	//�O�t���ŉ�����Ă��Ȃ� ���� ���t���ŉ�����Ă���
	if (preMouseBuf[Mouse_code] == 0 && currentMouseBuf[Mouse_code] == 1)
		return true;

	//������Ă��Ȃ��̂� false
	return false;
}

//�����Ɖ�����Ă���
bool CMouse::IsMouseKeep(int Mouse_code)
{
	//�O�t���ŉ�����Ă��� ���� ���t���ŉ�����Ă���
	if (preMouseBuf[Mouse_code] == 1 && currentMouseBuf[Mouse_code] == 1)
		return true;

	//������Ă��Ȃ��̂� false
	return false;
}

//�L�[�𗣂���
bool CMouse::IsMouseRelease(int Mouse_code)
{
	//�O�t���ŉ�����Ă��� ���� ���t���ŉ�����Ă��Ȃ�
	if (preMouseBuf[Mouse_code] == 1 && currentMouseBuf[Mouse_code] == 0)
		return true;

	//������Ă��Ȃ��̂� false
	return false;
}

//�P���ɉ�����Ă��邩
bool CMouse::IsMouseDown(int Mouse_code)
{
	//���t���ŉ�����Ă���i�O�t���̏�Ԃ͊֌W�Ȃ��j
	if (currentMouseBuf[Mouse_code] == 1)
		return true;

	//������Ă��Ȃ��̂� false
	return false;
}

//�}�E�X���W����p�x�v�Z
float CMouse::MouseToRot()
{
	int X = MouseX - (SCREEN_SIZE_X / 2);
	int Y = MouseY - (SCREEN_SIZE_Y / 2);

	return (float)atan2((int)X, (int)Y);
}
