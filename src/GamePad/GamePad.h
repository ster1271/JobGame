#pragma once
#include "DxLib.h"

//�R���g���[���[�{�^��
enum PAD_BUTTON
{
	BUTTON_A = 0,	//A
	BUTTON_B,		//B
	BUTTON_X,		//X
	BUTTON_Y,		//Y
	BUTTON_LB,		//LB
	BUTTON_RB,		//RB
	BUTTON_START,	//�X�^�[�g�{�^��
	BUTTON_LSTICK,	//���X�e�B�b�N��������
	BUTTON_RSTICK,	//�E�X�e�B�b�N��������

	BUTTON_NUM,		//�{�^���̑��ԍ�
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

	//���X�e�B�b�N
	static bool LStick();

	//�E�X�e�B�b�N
	static bool RStick();
};
