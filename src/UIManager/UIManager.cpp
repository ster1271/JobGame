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
	cButtonUI.Init();
}


//�ǂݍ���
void CUIManager::Load()
{
	cPlayerUI.Load();
	cWaveUI.Load();
	cEnemyUI.Load();
	cButtonUI.Load();
}

//�`��
void CUIManager::Draw()
{
	cPlayerUI.Draw();
	cWaveUI.Draw();
	cEnemyUI.Draw();
	cButtonUI.Draw();
}

//���t���[���s������
void CUIManager::Step(CEnemyManager& cEnemyManager, const int Cnt)
{
	cPlayerUI.Step();
	cEnemyUI.Step(cEnemyManager);
	cButtonUI.Step(Cnt);
}
