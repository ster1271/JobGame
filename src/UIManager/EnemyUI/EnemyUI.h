#pragma once
#include "../UIBase/BaseUI.h"
#include "../../Enemy/EnemyManager.h"


class CEnemyUI :public CUIBase
{
private:
	int LifeHndl;
	int MaxLifeHndl;
	
	int Count[ENEMY_MAXNUM];
	int Alpha[ENEMY_MAXNUM];			//透明度
	float PreLife[ENEMY_MAXNUM];
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

	//透明度変更
	void Alpha_Change(int Index);
};

