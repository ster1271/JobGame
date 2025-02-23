#pragma once
#include "EnemyBase.h"
#include "../Wave/Wave.h"

const int ENEMY_MAX_LIFE = 20;		//最大体力

//敵のサイズ
const VECTOR ENEMY_NORMAL_SIZE = VGet(0.0f, 0.0f, 0.0f);

class CEnemy_Normal:public CEnemyBase
{
private:
	VECTOR Respown_Pos;
	int ReSeachTime;

public:
	//コンストラクタ・デストラクタ
	CEnemy_Normal();
	~CEnemy_Normal();
	
	//初期化
	void Init();

	//データロード
	void Load(int Hndl);

	//描画
	void Draw();

	//毎フレーム行う処理
	void Step(VECTOR vPos, CMapManager& cMapManager);

	//後処理
	void Exit();

	//リクエスト
	bool RequestEnemy(VECTOR vPos, VECTOR vSpeed);

};
