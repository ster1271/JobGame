#include "EffectManager.h"

//コンストラクタ
CEffectManager::CEffectManager() {}

//デストラクタ
CEffectManager::~CEffectManager() {}

//インスタンスの初期化
CEffectManager* CEffectManager::cInstance = nullptr;

int CEffectManager::m_iHndl[EFFECTID_NUM];


//インスタンスの生成
void CEffectManager::Create()
{
	//インスタンスにが生成されていなかったら
	if (cInstance == nullptr)
	{
		//新しくnewする
		cInstance = new CEffectManager();
	}
}


//インスタンスの削除
void CEffectManager::Destroy()
{
	//インスタンスが生成されていたら
	if (cInstance != nullptr)
	{
		//deleteしてnullptrを入れる
		delete cInstance;
		cInstance = nullptr;
	}
}


//インスタンスの取得
CEffectManager* CEffectManager::GetInstance()
{
	if (cInstance == nullptr)
	{
		//インスタンスが生成されていなかったら生成する
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


	//エフェクトの初期化
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
		//1つでもロード失敗があればフラグをオフに
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