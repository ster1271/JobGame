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
	cAttacker.Init();
	//���C��ID��������
	MainID = ID_NUM;
}

//�f�[�^���[�h
void CCharacterManager::Load()
{
	cAttacker.Load();
}

//�I������
void CCharacterManager::Exit()
{
	//���C���L�����㏈��
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
}

//���t���[���Ăԏ���
void CCharacterManager::Step()
{
	//���C���L��������
	switch (MainID)
	{
	case MainID_ATTACKER:
		cAttacker.Step();
		cAttacker.Update();
		break;

	case MainID_TANK:
		cTank.Step();
		cTank.Update();
		break;

	case MainID_SUPPORT:
		cSupport.Step();
		cSupport.Update();
		break;

	case ID_NUM:
		break;

	default:
		break;
	}	
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
}