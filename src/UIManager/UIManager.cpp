#include "UIManager.h"

//�R���X�g���N�^
CUIManager::CUIManager(){}

//�f�X�g���N�^
CUIManager::~CUIManager(){}

//������
void CUIManager::Init()
{
	cWaveUI.Init();
}


//�ǂݍ���
void CUIManager::Load()
{
	cWaveUI.Load();
}

//�`��
void CUIManager::Draw()
{
	cWaveUI.Draw();
}
