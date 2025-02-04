#include "UIManager.h"

//�R���X�g���N�^
CUIManager::CUIManager(){}

//�f�X�g���N�^
CUIManager::~CUIManager(){}

//������
void CUIManager::Init()
{
	cPlayerUI.Init();
	cWaveUI.Init();
	cEnemyUI.Init();
}


//�ǂݍ���
void CUIManager::Load()
{
	cPlayerUI.Load();
	cWaveUI.Load();
	cEnemyUI.Load();
}

//�`��
void CUIManager::Draw()
{
	cPlayerUI.Draw();
	cWaveUI.Draw();
	cEnemyUI.Draw();
}

//���t���[���s������
void CUIManager::Step(CEnemyManager& cEnemyManager)
{
	cPlayerUI.Step();
	cEnemyUI.Step(cEnemyManager);
}
