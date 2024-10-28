#pragma once 
#include "../Common.h"
#include "../Object/Object.h"
#include "../Object/ObjectManager.h"
#include "../Check_Point/Check_Point.h"
#include "../RouteSearch/RouteSearch.h"
#include "../CollisionManager/CollisionManager.h"


using namespace std;

//ボットクラス
class CBot :public CObject
{
private:
	//ボットの状態遷移
	enum BOT_STATE
	{
		STATE_STOP = 0,	//停止
		STATE_SEARCH,	//経路探索
		STATE_MOVE,		//移動

		STATE_NUM,
	};


	BOT_STATE State_Id;

	float tmp_dir;
	float tmp_Range;
	int tmp;
	int NUM;
	bool IsCalcu;
	float NextRotY;

public:
	//コンストラクタ・デストラクタ
	CBot();
	~CBot();

	//初期化
	void Init();

	//読み込み
	bool Load();

	//描画
	void Draw();

	//毎フレーム行う処理
	void Step(CRoute_Search& cRoute_Search, CMap& cMap);

	//指定の場所に動く処理
	void Move_Bot(vector<VECTOR> List);

};
