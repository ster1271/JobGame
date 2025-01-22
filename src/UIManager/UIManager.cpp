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
}


//�ǂݍ���
void CUIManager::Load()
{
	cPlayerUI.Load();
	cWaveUI.Load();
}

//�`��
void CUIManager::Draw()
{
	cPlayerUI.Draw();
	cWaveUI.Draw();
}
