#pragma once
#include "../Character/Attacker.h"

class CCharacterManager
{
private:
	CAttacker cAttacker;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CCharacterManager();
	~CCharacterManager();

	//������
	void Init();

	//�f�[�^���[�h
	void Load();

	//�I������
	void Exit();

	//���t���[���Ăԏ���
	void Step();

	//�`�揈��
	void Draw();

};
