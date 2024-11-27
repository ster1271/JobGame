#pragma once
#include "Enemy_Normal.h"
#include "EnemyBoss.h"
#include "../Bot/Bot.h"
#include "../Map/MapManager.h"
#include "../RouteSearch/RouteSearch.h"
#include "../Wave/Wave.h"

#define ENEMY_MAXNUM	(2)

//敵の種類
enum TYPE_ENEMY
{
	TYPE_ENEMY01 = 0,

	TYPE_BOSS,
	TYPE_NUM,
};

class CEnemyManager
{
private:
	//モデルのコピー元
	int Org_Hndl;
	TYPE_ENEMY type_id;
	CEnemy_Normal cEnemy_Normal[ENEMY_MAXNUM];
	CEnemyBoss cEnemyBoss[ENEMY_MAXNUM];

public:
	//コンストラクタ・デストラクタ
	CEnemyManager();
	~CEnemyManager();

	//初期化
	void Init();

	//データロード
	void Load();

	//終了処理
	void Exit();

	//毎フレーム呼ぶ処理
	void Step(CBot& cBot, CMapManager cMapManager);

	//描画処理
	void Draw();

	//敵の情報取得
	CEnemy_Normal& GetEnemy(int id) { return cEnemy_Normal[id]; }

private:
	//敵リクエスト
	void RequestEnemy(int Index);
};
