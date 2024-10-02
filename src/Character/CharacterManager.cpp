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
	cTank.Init();
	cSupport.Init();

	//���C��ID��������
	MainID = MainID_ATTACKER;
}

//�f�[�^���[�h
void CCharacterManager::Load()
{
	cAttacker.Load();
	cTank.Load();
	cSupport.Load();
}

//�I������
void CCharacterManager::Exit()
{
	//���C���L�����㏈��
	cAttacker.Exit();
	cTank.Exit();
	cSupport.Exit();

}

//���t���[���Ăԏ���
void CCharacterManager::Step(CShotManager& cShotManager, CTurretManager& cTurretManager)
{
	//���C���L��������
	switch (MainID)
	{
	case MainID_ATTACKER:
		cAttacker.Step(cShotManager, cTurretManager);
		cAttacker.Update();
		break;

	case MainID_TANK:
		cTank.Step(cShotManager, cTurretManager);
		cTank.Update();
		break;

	case MainID_SUPPORT:
		cSupport.Step(cShotManager, cTurretManager);
		cSupport.Update();
		break;

	case ID_NUM:
		break;

	default:
		break;
	}

}

void CCharacterManager::DebugStep(CObjectManager& cObjectManager)
{
	//if (CInput::IsKeyPush(KEY_INPUT_SPACE))
	//{
	//	cObjectManager.Set_Point();
	//}
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