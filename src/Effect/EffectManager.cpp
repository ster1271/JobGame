#include "EffectManager.h"

//�R���X�g���N�^
CEffectManager::CEffectManager() {}

//�f�X�g���N�^
CEffectManager::~CEffectManager() {}

//�C���X�^���X�̏�����
CEffectManager* CEffectManager::cInstance = nullptr;


//�C���X�^���X�̐���
void CEffectManager::Create()
{
	//�C���X�^���X�ɂ���������Ă��Ȃ�������
	if (cInstance == nullptr)
	{
		//�V����new����
		cInstance = new CEffectManager();
	}
}


//�C���X�^���X�̍폜
void CEffectManager::Destroy()
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
CEffectManager* CEffectManager::GetInstance()
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