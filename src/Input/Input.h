#pragma once

//�C���v�b�g�N���X
class CInput
{
public:
	//���͐��䏉����
	static void InitInput();

	//���͐���X�e�b�v
	//����Step��葁���Ă�
	static void StepInput();

	//�������ꂽ
	static bool IsKeyPush(int Key_code);

	//�����Ɖ�����Ă���
	static bool IsKeyKeep(int Key_code);

	//�L�[�𗣂���
	static bool IsKeyRelease(int Key_code);

	//�P���ɉ�����Ă��邩
	static bool IsKeyDown(int Key_code);
};



