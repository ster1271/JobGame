#include "EnemyManager.h"

//定義
static const char ENEMY_MODEL_PATH[] = { "data/enemy/enemy.pmx" };
static const int WAIT_TIME = 10;		//敵が再登場するまでの時間

//コンストラクタ
CEnemyManager::CEnemyManager()
{
	Org_Hndl = -1;
}

//デストラクタ
CEnemyManager::~CEnemyManager()
{

}

//初期化
void CEnemyManager::Init()
{
	for (int Enemy_Index = 0; Enemy_Index < Enemy_List.size(); Enemy_Index++)
	{
		Enemy_List[Enemy_Index]->Init();
	}
}

//データロード
void CEnemyManager::Load()
{
	//オリジナルデータ読み込み
	if (Org_Hndl == -1)
	{
		Org_Hndl = MV1LoadModel(ENEMY_MODEL_PATH);
	}

}

//終了処理
void CEnemyManager::Exit()
{

	for (int Enemy_Index = 0; Enemy_Index < Enemy_List.size(); Enemy_Index++)
	{
		Enemy_List[Enemy_Index]->Exit();
	}

	if (Org_Hndl != -1)
	{
		MV1DeleteModel(Org_Hndl);
		Org_Hndl = -1;
	}
}

//毎フレーム呼ぶ処理
void CEnemyManager::Step()
{
	
	//敵の移動処理
	for (int Enemy_Index = 0; Enemy_Index < Enemy_List.size(); Enemy_Index++)
	{
		Enemy_List[Enemy_Index]->Step();
	}

	//敵の出現
	if (Enemy_List.size() < ENEMY_NUM)
	{
		RequestEnemy();
	}

	//for (int Enemy_Index = 0; Enemy_Index < Enemy_List.size(); Enemy_Index++)
	//{
	//	if (!Enemy_List[Enemy_Index]->GetActive())
	//	{
	//		//再利用のため初期化しておく
	//		Enemy_List[Enemy_Index]->Init();
	//	}	
	//}
}

//描画処理
void CEnemyManager::Draw()
{
	for (int Enemy_Index = 0; Enemy_Index < Enemy_List.size(); Enemy_Index++)
	{
		Enemy_List[Enemy_Index]->Draw();
	}

}


//敵リクエスト
void CEnemyManager::RequestEnemy()
{
	VECTOR vPos = VGet(0.0f, 5.0f , GetRand(200.0f)+ 100.0f);
	VECTOR vSpeed = VGet(0.0f, 0.0f, 1.0f);

	//変数代入用クラス
	CEnemyBase* cEnemyBase = new CEnemy_Normal;
	cEnemyBase->Init();
	cEnemyBase->Load(Org_Hndl);
	cEnemyBase->RequestEnemy(vPos, vSpeed);

	
	
	//リストに追加
	Enemy_List.push_back(cEnemyBase);

}