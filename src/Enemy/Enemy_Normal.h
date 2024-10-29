#pragma once
#include "EnemyBase.h"
#include "../Map/Map.h"
#include "../RouteSearch/RouteSearch.h"
#include "../Bot/Bot.h"

class CEnemy_Normal: public CEnemyBase
{
private:
	CRoute_Search cRoute_Search;
	VECTOR Respown_Pos;

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
	void Step(CBot& cBot, CMap& cMap);

	//後処理
	void Exit();

	//リクエスト
	virtual bool RequestEnemy(const VECTOR& vPos, const VECTOR& vSpeed);
};
