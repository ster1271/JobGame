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
	PreLife[ENEMY_MAXNUM] = { 0 };
	CurrentLife[ENEMY_MAXNUM] = { 0 };
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
		PreLife[EnemyIndex] = CurrentLife[EnemyIndex];

		CurrentLife[EnemyIndex] = cEnemy[EnemyIndex].GetLife();

		Alpha_Change(EnemyIndex);
	}
}

//描画
void CEnemyUI::Draw()
{
	for (int EnemyIndex = 0; EnemyIndex < ENEMY_MAXNUM; EnemyIndex++)
	{
		if (!cEnemy[EnemyIndex].GetActive())
			continue;

		VECTOR  DrawPos = cEnemy[EnemyIndex].GetPosition();
		DrawPos.x += 10.0f;
		DrawPos.y = 30.0f;

		SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, Alpha[EnemyIndex]);
		DrawModiBillboard3D(DrawPos, 
			0.0f, 5.0f,
			ENEMY_MAX_LIFE, 5.0f,
			ENEMY_MAX_LIFE, 0.0f,
			0.0f, 0.0f,
			MaxLifeHndl, TRUE);
		DrawModiBillboard3D(DrawPos,
			0.0f, 5.0f,
			cEnemy[EnemyIndex].GetLife(), 5.0f,
			cEnemy[EnemyIndex].GetLife(), 0.0f,
			0.0f, 0.0f,
			LifeHndl, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	}


}

//後処理
void CEnemyUI::Exit()
{
	MaxLifeHndl = -1;
	LifeHndl = -1;
}


//透明度変更
void CEnemyUI::Alpha_Change(int Index)
{
	//ライフが同じなら
	if (CurrentLife[Index] == PreLife[Index])
	{
		//カウント増加
		Count[Index]++;
	}
	else
	{
		Alpha[Index] = 200;
		Count[Index] = 0;
	}

	if (Count[Index] > 100)
	{
		//透明度を下げる
		Alpha[Index] -= 2;
		if (Alpha[Index] < 0)
		{
			Alpha[Index] = 0;
			Count[Index] = 0;
		}
	}

}
