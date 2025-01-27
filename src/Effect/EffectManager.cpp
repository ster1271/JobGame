#include "EffectManager.h"

//�R���X�g���N�^
CEffectManager::CEffectManager() {}

//�f�X�g���N�^
CEffectManager::~CEffectManager() {}

//�C���X�^���X�̏�����
CEffectManager* CEffectManager::cInstance = nullptr;

int CEffectManager::m_iHndl[EFFECTID_NUM];


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

void CEffectManager::Init()
{
	vRot = { 0.0f, 0.0f, 0.0f };
	vEyePos = { 0.0f, 10.0f, -10.0f };
	fNear = 1.0f;
	fFar = 1000.0f;
	fPars = 60.0f * DX_PI_F / 180.0f;


	//�G�t�F�N�g�̏�����
	CEffekseerCtrl::Init(10, 2000);

	CEffekseerCtrl::SetProjectionMtx(fPars, 640.0f / 480.0f, fNear, fFar);
}

void CEffectManager::UpData()
{
	CEffekseerCtrl::SetCameraRotMtx(vEyePos, vRot, VGet(0.0f, 1.0f, 0.0f));
	CEffekseerCtrl::Update();
}

bool CEffectManager::Load()
{
	bool isRet = true;
	const char pFileName[EFFECTID_NUM][128] =
	{
		
	};

	for (int i = 0; i < EFFECTID_NUM; i++)
	{
		m_iHndl[i] = LoadSoundMem(pFileName[i]);
		//1�ł����[�h���s������΃t���O���I�t��
		if (m_iHndl[i] == -1)
		{
			isRet = false;
		}
	}

	return isRet;
}


void CEffectManager::Draw()
{
	CEffekseerCtrl::Draw();
}