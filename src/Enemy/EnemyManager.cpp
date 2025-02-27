#include "EnemyManager.h"

//定義
static const char ENEMY_MODEL_PATH01[] = { "data/enemy/Enemy01.x" };
static const char Enemy_MODEL_PATH02[] = { "data/enemy/Enemy02.x" };
static const int COOL_MAX_TIME = 200;		//敵が再登場するまでの時間
static const int RESPAWN_MAX_NUM = 20;	//通常ウェーブ最大出現数

const VECTOR EnemySpawn[MAP_MAX_NUM][3] =
{
	VGet(50.0f, 5.0f, 700.0f), VGet(800.0f, 5.0f, 50.0f), VGet(500.0f, 5.0f, 900.0f)
};


//コンストラクタ
CEnemyManager::CEnemyManager()
{
	
}

//デストラクタ
CEnemyManager::~CEnemyManager(){}

//初期化
void CEnemyManager::Init()
{
	CoolTime = COOL_MAX_TIME;
	ReqestCount = RESPAWN_MAX_NUM;
	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		cEnemy_Normal[Enemy_Index].Init();
	}
}

//データロード
void CEnemyManager::Load()
{
	int Hndl = MV1LoadModel(ENEMY_MODEL_PATH01);

	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		cEnemy_Normal[Enemy_Index].Load(Hndl);
	}
}

//終了処理
void CEnemyManager::Exit()
{
	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		cEnemy_Normal[Enemy_Index].Exit();
	}
}

//毎フレーム呼ぶ処理
void CEnemyManager::Step(VECTOR vPos, CMapManager cMapManager)
{
	int iEnemyCnt = 0;	//敵の出現数
	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		if (cEnemy_Normal[Enemy_Index].GetActive())
		{
			iEnemyCnt++;
		}
		cEnemy_Normal[Enemy_Index].Step(vPos, cMapManager);
		cEnemy_Normal[Enemy_Index].Update();
	}

	//敵の出現
	//CoolTime--;

	//一定期間出現していないか、生存数が0の時リクエストさせる
	if (CoolTime < 0 || iEnemyCnt == 0)
	{
		//RequestEnemy();
		CoolTime = COOL_MAX_TIME;
	}
}


//描画処理
void CEnemyManager::Draw()
{
	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		cEnemy_Normal[Enemy_Index].Draw();
	}

	CDebugString::GetInstance()->AddFormatString(0, 400, "生成できる数：%d", ReqestCount);
	
	for (int i = 0; i < 3; i++)
	{
		CDraw3D::DrawBox3D(EnemySpawn[0][i], VGet(50.0f, 50.0f, 50.0f));
	}
}


//敵リクエスト
void CEnemyManager::RequestEnemy()
{
	//敵1のスポーン(読み込みで設定する)
	VECTOR vPos = VGet(50.0f, 5.0f, 700.0f);
	VECTOR vSpeed = VGet(0.0f, 0.0f, 0.0f);

	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		if (cEnemy_Normal[Enemy_Index].RequestEnemy(EnemySpawn[0][1], vSpeed))
		{
			ReqestCount--;
			break;
		}
	}
}