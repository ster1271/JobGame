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
	cAttacker.Step();
	cAttacker.Update();
}

//�`�揈��
void CCharacterManager::Draw()
{
	cAttacker.Draw();
}