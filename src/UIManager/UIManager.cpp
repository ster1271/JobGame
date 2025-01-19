#include "UIManager.h"

//�C���X�^���X�̏�����
CUIManager* CUIManager::cInstance = nullptr;


//�R���X�g���N�^
CUIManager::CUIManager(){}

//�f�X�g���N�^
CUIManager::~CUIManager(){}


//�C���X�^���X�̐���
void CUIManager::Create()
{
	//�C���X�^���X�ɂ���������Ă��Ȃ�������
	if (cInstance == nullptr)
	{
		//�V����new����
		cInstance = new CUIManager();
	}
}


//�C���X�^���X�̍폜
void CUIManager::Destroy()
{
	//�C���X�^���X����������Ă�����
	if (cInstance != nullptr)
	{
		//delete����nullptr������
		delete cInstance;
		cInstance = nullptr;
	}
}


//�C���X�^���X�̎擾
CUIManager* CUIManager::GetInstance()
{
	if (cInstance == nullptr)
	{
		//�C���X�^���X����������Ă��Ȃ������琶������
		Create();
		return cInstance;
	}
	else
	{
		return cInstance;
	}
}


//�`��
void CUIManager::Draw()
{
	switch (CWave::GetInstance()->GetWaveState())
	{
	case STATE_WAVE_PREPAR:
		hnd = LoadGraph("data/");
		break;

	default:
		break;
	}
}
