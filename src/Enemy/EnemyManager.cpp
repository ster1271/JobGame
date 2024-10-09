#include "EnemyManager.h"

//定義
static const char ENEMY_MODEL_PATH01[] = { "data/enemy/enemy01.x" };
static const char Enemy_MODEL_PATH02[] = { "data/enemy/enemy02.x" };
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
	/*for (int Enemy_Index = 0; Enemy_Index < Enemy_List.size(); Enemy_Index++)
	{
		Enemy_List[Enemy_Index]->Init();
	}*/

	for (int Enemy_Index = 0; Enemy_Index < ENEMY_NUM; Enemy_Index++)
	{
		cEnemy_Normal[Enemy_Index].Init();
		cEnemyBoss[Enemy_Index].Init();
	}
}

//データロード
void CEnemyManager::Load()
{
	//オリジナルデータ読み込み
	if (Org_Hndl == -1)
	{
		Org_Hndl = MV1LoadModel(ENEMY_MODEL_PATH01);
	}

	for (int Enemy_Index = 0; Enemy_Index < ENEMY_NUM; Enemy_Index++)
	{
		cEnemy_Normal[Enemy_Index].Load(Org_Hndl);
	}

	Org_Hndl = MV1LoadModel(Enemy_MODEL_PATH02);
	for (int Enemy_Index = 0; Enemy_Index < ENEMY_NUM; Enemy_Index++)
	{
		cEnemyBoss[Enemy_Index].Load(Org_Hndl);
	}

}

//終了処理
void CEnemyManager::Exit()
{

	/*for (int Enemy_Index = 0; Enemy_Index < Enemy_List.size(); Enemy_Index++)
	{
		Enemy_List[Enemy_Index]->Exit();
	}*/

	for (int Enemy_Index = 0; Enemy_Index < ENEMY_NUM; Enemy_Index++)
	{
		cEnemy_Normal[Enemy_Index].Exit();
		cEnemyBoss[Enemy_Index].Exit();
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
	
	////敵の移動処理
	//for (int Enemy_Index = 0; Enemy_Index < Enemy_List.size(); Enemy_Index++)
	//{
	//	Enemy_List[Enemy_Index]->Step();
	//}

	////敵の出現
	//if (Enemy_List.size() < ENEMY_NUM)
	//{
	//	RequestEnemy();
	//}

	//for (int Enemy_Index = 0; Enemy_Index < Enemy_List.size(); Enemy_Index++)
	//{
	//	if (!Enemy_List[Enemy_Index]->GetActive())
	//	{
	//		//再利用のため初期化しておく
	//		Enemy_List[Enemy_Index]->Init();
	//	}	
	//}
	VECTOR vPos = VGet(0.0f, 0.0f, 0.0f);
	VECTOR vSpeed = VGet(0.0f, 0.0f, 0.0f);

	for (int Enemy_Index = 0; Enemy_Index < ENEMY_NUM; Enemy_Index++)
	{
		vPos = VGet(GetRand(200.0f) - 100.0f, 5.0f, GetRand(200.0f) + 100.0f);
		vSpeed = VGet(0.0f, 0.0f, 0.5f);
		cEnemy_Normal[Enemy_Index].Step();
		cEnemy_Normal[Enemy_Index].RequestEnemy(vPos, vSpeed);
	}

	for (int Enemy_Index = 0; Enemy_Index < ENEMY_NUM; Enemy_Index++)
	{
		vPos = VGet(GetRand(300.0f) - 100.0f, 5.0f, GetRand(200.0f) + 100.0f);
		vSpeed = VGet(0.0f, 0.0f, 0.3f);
		cEnemyBoss[Enemy_Index].Step();
		cEnemyBoss[Enemy_Index].RequestEnemy(vPos, vSpeed);
	}
}

//描画処理
void CEnemyManager::Draw()
{
	/*for (int Enemy_Index = 0; Enemy_Index < Enemy_List.size(); Enemy_Index++)
	{
		Enemy_List[Enemy_Index]->Draw();
	}*/
	for (int Enemy_Index = 0; Enemy_Index < ENEMY_NUM; Enemy_Index++)
	{
		cEnemy_Normal[Enemy_Index].Draw();
		cEnemyBoss[Enemy_Index].Draw();
	}
}


//敵リクエスト
void CEnemyManager::RequestEnemy()
{
	//VECTOR vPos = VGet(0.0f, 5.0f , GetRand(200.0f)+ 100.0f);
	//VECTOR vSpeed = VGet(0.0f, 0.0f, 1.0f);

	////変数代入用クラス
	//CEnemyBase* cEnemyBase = new CEnemy_Normal;
	//cEnemyBase->Init();
	//cEnemyBase->Load(Org_Hndl);
	//cEnemyBase->RequestEnemy(vPos, vSpeed);

	//
	//
	////リストに追加
	//Enemy_List.push_back(cEnemyBase);

}