#include "CharacterManager.h"

//�R���X�g���N�^
CCharacterManager::CCharacterManager()
{
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