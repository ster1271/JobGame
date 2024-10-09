#pragma once
#include "EnemyBase.h"

class CEnemyBoss :public CEnemyBase
{
private:
	VECTOR Respown_Pos;

public:
	//コンストラクタ・デストラクタ
	CEnemyBoss();
	~CEnemyBoss();

	//初期化
	void Init();

	//データロード
	void Load(int Hndl);

	//描画
	void Draw();

	//毎フレーム行う処理
	void Step();

	//後処理
	void Exit();

	//リクエスト
	virtual bool RequestEnemy(const VECTOR& vPos, const VECTOR& vSpeed);
};
