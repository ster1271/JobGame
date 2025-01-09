#pragma once
#include "DxLib.h"
#include "math.h"

//�R���g���[���[�{�^��
enum PAD_BUTTON
{
	BUTTON_A = 0,	//A
	BUTTON_B,		//B
	BUTTON_X,		//X
	BUTTON_Y,		//Y
	BUTTON_LB,		//LB
	BUTTON_RB,		//RB
	BUTTON_BACK,	//�X�^�[�g�{�^��
	BUTTON_LSTICK,	//���X�e�B�b�N��������
	BUTTON_RSTICK,	//�E�X�e�B�b�N��������

	BUTTON_NUM,		//�{�^���̑��ԍ�
};

//�X�e�B�b�N�̏ڍ�
enum STICK
{
	STICK_LEFT,
	STICK_RIGHT,
	STICK_LX_POS,	//���X�e�B�b�NX��(��)
	STICK_LX_NEG,	//���X�e�B�b�NX��(��)
	STICK_LY_POS,	//���X�e�B�b�NY��(��)
	STICK_LY_NEG,	//���X�e�B�b�NY��(��)
	STICK_RX_POS,	//�E�X�e�B�b�NX��(��)
	STICK_RX_NEG,	//�E�X�e�B�b�NX��(��)
	STICK_RY_POS,	//�E�X�e�B�b�NY��(��)
	STICK_RY_NEG,	//�E�X�e�B�b�NY��(��)
};

//�\���{�^����LT�ART�̔���p
enum CHECK
{
	UP,		//��
	UP_R,	//�E��
	RIGHT,	//�E
	DOWN_R,	//�E��
	DOWN,	//��
	DOWN_L,	//����
	LEFT,	//��
	UP_L,	//����
};


class CGamePad
{
private:

public:
	//���͐��䏉����
	static void InitGamePad();

	//���͐���X�e�b�v
	static void StepGamePad();
	
	//�ڑ��䐔�擾
	static int GetPadNumState();

	//�������ꂽ
	static bool IsPadPush(int InputType, int Key_code);

	//�����Ɖ�����Ă���
	static bool IsPadKeep(int InputType, int Key_code);

	//�L�[�𗣂���
	static bool IsPadRelease(int InputType, int Key_code);

	//�P���ɉ�����Ă��邩
	static bool IsPadDown(int InputType, int Key_code);

	//LT��RT�̐���
	static bool IsPush_LR(CHECK check);

	//LT��RT�̐���
	static bool IsKeep_LR(CHECK check);

	//�\���L�[�̐���
	static bool IsPush_Cross(CHECK check);

	//�\���L�[�̐���
	static bool IsKeep_Cross(CHECK check);

	//�X�e�B�b�N����
	static bool Stick(STICK stick);

	//�X�e�B�b�N�p�x�v�Z
	static float StickRot(STICK stick);

};
