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
	fNear = 5.0f;
	fFar = 10000.0f;
	fPars = 60.0f * DX_PI_F / 180.0f;


	//�G�t�F�N�g�̏�����
	CEffekseerCtrl::Init(10, 2000);
	CEffekseerCtrl::SetProjectionMtx(fPars, SCREEN_SIZE_X / SCREEN_SIZE_Y, fNear, fFar);
}

void CEffectManager::UpData(VECTOR vForcus, VECTOR fRot, VECTOR vUp)
{
	CEffekseerCtrl::UpdateAutoCamera();
	/*CEffekseerCtrl::SetCameraRotMtx(vForcus, fRot, vUp);
	CEffekseerCtrl::Update();*/
}

bool CEffectManager::Load()
{
	bool isRet = true;
	const char pFileName[EFFECTID_NUM][128] =
	{
		"data/effect/00_Basic/Simple_SpawnMethod1.efkefc"
	};

	for (int i = 0; i < EFFECTID_NUM; i++)
	{
		m_iHndl[i] = CEffekseerCtrl::LoadData(pFileName[i]);
		//1�ł����[�h���s������΃t���O���I�t��
		if (m_iHndl[i] == -1)
		{
			isRet = false;
		}
	}

	return isRet;
}

void CEffectManager::Reqest(int ID, VECTOR EffectPos, bool IsLoop)
{
	CEffekseerCtrl::Request(ID, EffectPos, IsLoop);
}


void CEffectManager::Draw()
{
	CEffekseerCtrl::Draw();
}