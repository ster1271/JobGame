#pragma once
#include "../Character/Attacker.h"

//���������삵�Ă���L����ID
enum MainPlayerID
{
	MainID_ATTACKER,
	MainID_TANK,
	MainID_SUPPORT,

	ID_NUM
};

class CCharacterManager
{
private:
	MainPlayerID MainID;
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


	//����L�����̍��W�擾
	VECTOR GetPosition(MainPlayerID id)
	{
		if (id == MainID_ATTACKER)
			return cAttacker.GetPos();
		else if (id == MainID_TANK)
			return cAttacker.GetPos();
		else if (id == MainID_SUPPORT)
			return cAttacker.GetPos();
	}

};
