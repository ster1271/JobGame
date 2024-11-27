#include "GameData.h"

CGameData* CGameData::cInstance = NULL;

//コンストラクタ
CGameData::CGameData()
{
	MaxScore = 0;		//最大スコア
	CurrentScore = 0;	//現在スコア

	//プレイヤーデータ初期化
	memset(&cPlayerData, 0, sizeof(PlayerData));
	//階層データ初期化
	memset(&cFloarData, 0, sizeof(FloarData));


}

//デストラクタ
CGameData::~CGameData(){}


//CGameDataを取得
CGameData* CGameData::GetInstance()
{
	//まだ生成されていないなら
	if (cInstance == NULL)
	{
		cInstance = new CGameData();
	}

	return cInstance;
}

//CGameDataを削除
void CGameData::DeleteInstance()
{
	//インスタンスがNULLでないなら
	if (cInstance != NULL)
	{
		delete cInstance;
		cInstance = NULL;	//削除してNULL代入
	}
}
