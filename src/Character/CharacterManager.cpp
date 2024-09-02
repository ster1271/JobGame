#include "CharacterManager.h"

//�R���X�g���N�^
CCharacterManager::CCharacterManager()
{
	//���C��ID��������
	MainID = ID_NUM;
}

//�f�X�g���N�^
CCharacterManager::~CCharacterManager()
{
}


//������
void CCharacterManager::Init()
{
	//�V���b�g�}�l�[�W���[������
	cShotManager.Init();

	cAttacker.Init();
	cTank.Init();
	cSupport.Init();

	//���C��ID��������
	MainID = ID_NUM;
}

//�f�[�^���[�h
void CCharacterManager::Load()
{
	//�V���b�g�}�l�[�W���[������
	cShotManager.Load();

	cAttacker.Load();
	cTank.Load();
	cSupport.Load();
}

//�I������
void CCharacterManager::Exit()
{
	//���C���L�����㏈��
	/*
	switch (MainID)
	{
	case MainID_ATTACKER:
		cAttacker.Exit();
		break;

	case MainID_TANK:
		cTank.Exit();
		break;

	case MainID_SUPPORT:
		cSupport.Exit();
		break;

	case ID_NUM:
		break;

	default:
		break;
	}
	*/
	cAttacker.Exit();
	cTank.Exit();
	cSupport.Exit();

	//�V���b�g�}�l�[�W���[�㏈��
	cShotManager.Exit();
}

//���t���[���Ăԏ���
void CCharacterManager::Step()
{
	//���C���L��������
	switch (MainID)
	{
	case MainID_ATTACKER:
		cAttacker.Step(cShotManager);
		cAttacker.Update();
		break;

	case MainID_TANK:
		cTank.Step(cShotManager);
		cTank.Update();
		break;

	case MainID_SUPPORT:
		cSupport.Step(cShotManager);
		cSupport.Update();
		break;

	case ID_NUM:
		break;

	default:
		break;
	}

	
	cShotManager.Step(cAttacker.GetPos());
}

//�`�揈��
void CCharacterManager::Draw()
{
	//���C���L�����`��
	switch (MainID)
	{
	case MainID_ATTACKER:
		cAttacker.Draw();
		break;

	case MainID_TANK:
		cTank.Draw();
		break;

	case MainID_SUPPORT:
		cSupport.Draw();
		break;

	case ID_NUM:
		break;

	default:
		break;
	}

	cShotManager.Draw();
}