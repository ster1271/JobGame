#include "EnemyUI.h"
#include "../../Enemy/Enemy_Normal.h"

const char ENEMY_LIFE_PATH[] = { "data/UI/enemy/EnemyLife.png" };
const char ENEMY_MAXLIFE_PATH[] = { "data/UI/enemy/EnemyMaxLife.png" };


//コンストラクタ・デストラクタ
CEnemyUI::CEnemyUI(){}
CEnemyUI::~CEnemyUI(){}

//初期化
void CEnemyUI::Init()
{
	MaxLifeHndl = -1;
	LifeHndl = -1;
}

//読み込み
void CEnemyUI::Load()
{
	MaxLifeHndl = LoadGraph(ENEMY_MAXLIFE_PATH);
	LifeHndl = LoadGraph(ENEMY_LIFE_PATH);
}

//毎フレーム行う処理
void CEnemyUI::Step(CEnemyManager& cEnemyManager)
{
	for (int EnemyIndex = 0; EnemyIndex < ENEMY_MAXNUM; EnemyIndex++)
	{
		cEnemy[EnemyIndex] = cEnemyManager.GetEnemy(EnemyIndex);
	}
}

//描画
void CEnemyUI::Draw()
{
	for (int EnemyIndex = 0; EnemyIndex < ENEMY_MAXNUM; EnemyIndex++)
	{
		if (!cEnemy[EnemyIndex].GetActive())
			continue;

		DrawRectGraph(cEnemy[EnemyIndex].GetPosition().x / 2, cEnemy[EnemyIndex].GetPosition().z,
			0, 0, ENEMY_MAX_LIFE, 30, MaxLifeHndl, true, false);
		DrawRectGraph(cEnemy[EnemyIndex].GetPosition().x / 2, cEnemy[EnemyIndex].GetPosition().z,
			0, 0, cEnemy[EnemyIndex].GetLife(), 30, LifeHndl, true, false);

	}

}

//後処理
void CEnemyUI::Exit()
{
	MaxLifeHndl = -1;
	LifeHndl = -1;
}