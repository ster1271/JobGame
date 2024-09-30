#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "EnemyBase.h"
#include "../Enemy/Enemy_Normal.h"

using namespace std;

#define ENEMY_NUM	(10)

class CEnemyManager
{
private:
	//モデルのコピー元
	int Org_Hndl;

	//CEnemyBase型のList配列
	vector<CEnemyBase*> Enemy_List;

	CEnemyBase cEnemyBace;

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
	void Step();

	//描画処理
	void Draw();

	//敵情報取得
	//inline CEnemyBase& GetEnemy(int iID) { return cEnemyBace; }

private:
	//敵リクエスト
	void RequestEnemy();
};
