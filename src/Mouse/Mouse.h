#pragma once
#include "../Common.h"

//�C���v�b�g�N���X
class CMouse
{
private:

public:
	//���͐��䏉����
	static void InitMouse();

	//���͐���X�e�b�v
	//����Step��葁���Ă�
	static void StepMouse();

	//�������ꂽ
	static bool IsMousePush(int Mouse_code);

	//�����Ɖ�����Ă���
	static bool IsMouseKeep(int Mouse_code);

	//�L�[�𗣂���
	static bool IsMouseRelease(int Mouse_code);

	//�P���ɉ�����Ă��邩
	static bool IsMouseDown(int Mouse_code);

	//�}�E�X���W����p�x�v�Z
	static float MouseToRot();
};
