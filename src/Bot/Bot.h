#pragma once 
#include "DxLib.h"
#include <math.h>
#include "../MyLibrary/MyLibrary.h"
#include "../Input/Input.h"
#include "../Object/Object.h"
#include "../Object/ObjectManager.h"
#include "../Check_Point/Check_Point.h"

//ボットクラス
class CBot :public CObject
{
private:
	//ボットの状態遷移
	enum BOT_STATE
	{
		STATE_STOP = 0,	//停止
		STATE_MOVE,		//移動
		STATE_NUM,
	};

	//経路探索に必要な変数情報
	struct Route_Search_Info
	{
		VECTOR Center_Pos;			//探索する中心位置
		float Range_From_Start[8];	//スタートからの距離
		float Renge_To_Goal[8];		//ゴールまでの距離
		float Total_Renge[8];		//合計距離	
		float Min_Total_Renge;		//最小距離
		float Distance;
	};

	BOT_STATE State_Id;
	Route_Search_Info Search_info;
	float tmp_dir;
	float tmp_Range;
	int tmp;

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
	void Step(vector<VECTOR> List);

	//指定の場所に動く処理
	void Move_Bot(vector<VECTOR> List);

	//経路探索
	void Route_Search(VECTOR GoalPos);

};
