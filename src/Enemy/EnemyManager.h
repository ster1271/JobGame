#pragma once
#include "../Common.h"
#include "EnemyBase.h"
#include "Enemy_Normal.h"
#include "EnemyBoss.h"
#include "../RouteSearch/RouteSearch.h"
#include "../Bot/Bot.h"
#include "../Map/Map.h"


using namespace std;

#define ENEMY_NUM	(3)

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
	CEnemy_Normal cEnemy_Normal[ENEMY_NUM];
	CEnemyBoss cEnemyBoss[ENEMY_NUM];

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
	void Step(CBot& cBot, CRoute_Search& cRoute_Search, CMap& cMap);

	//描画処理
	void Draw();

private:
	//敵リクエスト
	void RequestEnemy();
};
