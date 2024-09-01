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
	cAttacker.Exit();
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
		break;

	case MainID_SUPPORT:
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
	cAttacker.Draw();
}