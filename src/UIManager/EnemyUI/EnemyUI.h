#pragma once
#include "../UIBase/BaseUI.h"
#include "../../Enemy/EnemyManager.h"


class CEnemyUI :public CUIBase
{
private:
	int LifeHndl;
	int MaxLifeHndl;
	int Alpha;			//透明度
	int Count;

	float preLife[ENEMY_MAXNUM];
	float CurrentLife[ENEMY_MAXNUM];

	CEnemy_Normal cEnemy[ENEMY_MAXNUM];

public:
	//コンストラクタ・デストラクタ
	CEnemyUI();
	~CEnemyUI();

	//初期化
	void Init();

	//読み込み
	void Load();

	//毎フレーム行う処理
	void Step(CEnemyManager &cEnemyManager);

	//描画
	void Draw();

	//後処理
	void Exit();

};

