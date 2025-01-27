#include "EffectManager.h"

//コンストラクタ
CEffectManager::CEffectManager() {}

//デストラクタ
CEffectManager::~CEffectManager() {}

//インスタンスの初期化
CEffectManager* CEffectManager::cInstance = nullptr;


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