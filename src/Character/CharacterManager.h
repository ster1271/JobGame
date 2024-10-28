#pragma once

#include "../Character/Attacker.h"
#include "../Character/Tank.h"
#include "../Character/Support.h"

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

	CAttacker cAttacker;			//�A�^�b�J�[�N���X
	CTank cTank;					//�^���N�N���X
	CSupport cSupport;				//�T�|�[�g�N���X



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
	void Step(CShotManager& cShotManager,  CTurretManager& cTurretManager);

	//�`�揈��
	void Draw();

	//���C���L����ID�ݒ�(���ύX)
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
			return cTank.GetPos();
		else if (MainID == MainID_SUPPORT)
			return cSupport.GetPos();
	}

	//����L�����̊p�x�擾
	VECTOR GetRotate()
	{
		if (MainID == MainID_ATTACKER)
			return cAttacker.GetRotate();
		else if (MainID == MainID_TANK)
			return cTank.GetRotate();
		else if (MainID == MainID_SUPPORT)
			return cSupport.GetRotate();
	}

};
