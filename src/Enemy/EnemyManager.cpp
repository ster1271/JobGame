#include "EnemyManager.h"

//定義
static const char ENEMY_MODEL_PATH01[] = { "data/enemy/Enemy01.x" };
static const char Enemy_MODEL_PATH02[] = { "data/enemy/Enemy02.x" };
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
	cnt = 0;
	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
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

	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		cEnemy_Normal[Enemy_Index].Load(Org_Hndl);
	}

	Org_Hndl = MV1LoadModel(Enemy_MODEL_PATH02);
	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		cEnemyBoss[Enemy_Index].Load(Org_Hndl);
	}

}

//終了処理
void CEnemyManager::Exit()
{

	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
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
void CEnemyManager::Step(CBot& cBot, CMapManager cMapManager)
{
	VECTOR PastPos = VGet(0.0f, 0.0f, 0.0f);	//過去座標を格納する
	VECTOR CurrentPos = cBot.GetPos();			//現在座標を格納する

	if (CWave::GetInstance()->GetIsWave() == true)
	{

		for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
		{
			cEnemy_Normal[Enemy_Index].Step(cBot, cMapManager);
			cEnemyBoss[Enemy_Index].Step(cBot, cMapManager);
		}

		cnt++;
		for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
		{
			//リクエスト
			RequestEnemy(Enemy_Index);
			cnt = 0;
		}
	}
}

//描画処理
void CEnemyManager::Draw()
{
	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		cEnemy_Normal[Enemy_Index].Draw();
		//cEnemyBoss[Enemy_Index].Draw();
	}
}


//敵リクエスト
void CEnemyManager::RequestEnemy(int Index)
{
	if (cnt > WAIT_TIME)		//クールタイム中なら処理しない
		return;

	//敵1のスポーン
	VECTOR vPos = VGet(300.0f, 5.0f, 100.0f);
	VECTOR vSpeed = VGet(0.0f, 0.0f, 0.0f);
	cEnemy_Normal[Index].RequestEnemy(vPos, vSpeed);

	//敵2のスポーン
	vPos = VGet(300.0f, 5.0f, 100.0f);
	vSpeed = VGet(0.0f, 0.0f, 0.0f);
	cEnemyBoss[Index].RequestEnemy(vPos, vSpeed);
	
	cnt = 0;
}