#include "EnemyManager.h"

//定義
static const char ENEMY_MODEL_PATH01[] = { "data/enemy/Enemy01.x" };
static const char Enemy_MODEL_PATH02[] = { "data/enemy/Enemy02.x" };
static const int WAIT_TIME = 120;		//敵が再登場するまでの時間

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
	Coolcnt = WAIT_TIME;
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

	/*Org_Hndl = MV1LoadModel(Enemy_MODEL_PATH02);
	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		cEnemyBoss[Enemy_Index].Load(Org_Hndl);
	}*/

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

	//ウェーブ中のみ処理を行う
	if (CWave::GetInstance()->GetIsWave() == true)
	{
		int iEnemyCnt = 0;	//敵の出現数
		for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
		{
			if (cEnemy_Normal[Enemy_Index].GetActive())
			{
				iEnemyCnt++;
			}
			cEnemy_Normal[Enemy_Index].Step(cBot, cMapManager);
		}

		//敵の出現
		Coolcnt--;

		//一定期間出現していないか、生存数が0の時リクエストさせる
		if (Coolcnt < 0 || iEnemyCnt == 0)
		{
			RequestEnemy();
			Coolcnt = WAIT_TIME;
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
void CEnemyManager::RequestEnemy()
{
	//敵1のスポーン
	VECTOR vPos = VGet(300.0f, 5.0f, 100.0f);
	VECTOR vSpeed = VGet(0.0f, 0.0f, 0.0f);
	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		if (cEnemy_Normal[Enemy_Index].RequestEnemy(vPos, vSpeed))
		{
			break;
		}

	}
}