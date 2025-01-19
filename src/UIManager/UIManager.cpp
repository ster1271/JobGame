#include "UIManager.h"

//インスタンスの初期化
CUIManager* CUIManager::cInstance = nullptr;


//コンストラクタ
CUIManager::CUIManager(){}

//デストラクタ
CUIManager::~CUIManager(){}


//インスタンスの生成
void CUIManager::Create()
{
	//インスタンスにが生成されていなかったら
	if (cInstance == nullptr)
	{
		//新しくnewする
		cInstance = new CUIManager();
	}
}


//インスタンスの削除
void CUIManager::Destroy()
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
CUIManager* CUIManager::GetInstance()
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


//描画
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
