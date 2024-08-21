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

	//���C���L����ID�ݒ�
	void SetMainID(MainPlayerID Id)
	{
		MainID = Id;
	}


	//����L�����̍��W�擾
	VECTOR GetPosition()
	{
		if (MainID == MainID_ATTACKER)
			return cAttacker.GetPos();
		else if (MainID == MainID_TANK)
			return /*cAttacker.GetPos()*/ VGet(100.0f, 100.0f, 100.0f);
		else if (MainID == MainID_SUPPORT)
			return/*cAttacker.GetPos()*/VGet(200.0f, 200.0f, 200.0f);
	}

};
