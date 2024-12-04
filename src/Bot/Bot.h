#pragma once 
#include "../Common.h"
#include "../RouteSearch/RouteSearch.h"
#include "../Map/MapManager.h"
#include "../Wave/Wave.h"


//ボットクラス
class CBot
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
	CRoute_Search cRoute;
	BOT_STATE State_Id;

	VECTOR cPos;
	VECTOR cRotate;
	VECTOR cSize;

	int iHndl;

	float tmp_dir;
	float tmp_Range;
	int tmp;
	int NUM;
	bool IsCalcu;
	float NextRotY;

	vector<VECTOR> Route_List;
	bool IsFinish;

public:
	//コンストラクタ・デストラクタ
	CBot();
	~CBot();

	//初期化
	void Init();

	//後処理
	void Exit();

	//読み込み
	bool Load();

	//描画
	void Draw();

	//情報更新
	void Updata();

	//座標取得
	VECTOR GetPos() { return cPos; }

	//サイズ取得
	VECTOR GetSize() { return cSize; }

	//回転地取得
	VECTOR GetRotate() { return cRotate; }

	//フラグ取得
	bool GetFinish() { return IsFinish; }

	//毎フレーム行う処理
	void Step(CMapManager& cMapManager);

	//指定の場所に動く処理
	void Move_Bot(vector<VECTOR> List);

};
