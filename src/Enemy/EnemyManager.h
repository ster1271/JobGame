#pragma once
#include "Enemy_Normal.h"
#include "../Wave/Wave.h"

const int ENEMY_MAXNUM = 20;

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
	CEnemy_Normal cEnemy_Normal[ENEMY_MAXNUM];

	//モデルのコピー元
	int OrgHndl;
	int CoolTime;
	int ReqestCount;		//リクエストした数
	int DeathCount;			//倒された数

	void RequestEnemy();	//敵リクエスト


public:
	void SetCnt(int i = 1) { DeathCount += i; }

	//コンストラクタ・デストラクタ
	CEnemyManager();
	~CEnemyManager();

	//初期化
	void Init();

	//データロード
	void Load();

	//終了処理
	void Exit();

	//毎フレーム行う処理
	void Step(VECTOR vPos, CMapManager cMapManager);

	//描画処理
	void Draw();

	//敵の情報取得
	CEnemy_Normal& GetEnemy(int id) { return cEnemy_Normal[id]; }
};
