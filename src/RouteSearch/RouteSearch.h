#pragma once
#include "../Common.h"
#include "../MyLibrary/MyLibrary.h"
#include "../CollisionManager/CollisionManager.h"

//状態遷移
enum NODE_STATE
{
	NONE = 0,	//未定
	OPEN,		//判定中
	CLOSE,		//判定終了
};

enum DIR
{
	DIR_UP = 0,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT,
	DIR_NUM,
};

class CRoute_Search
{
private:
	NODE_STATE State;

	struct Info
	{
		float Renge_form_Start;	//移動コスト(スタート地点から離れた距離)
		float Renge_To_Goal;	//推定コスト(ゴールまでの距離)
		float Total_Cost;		//合計コスト
		VECTOR Pos;				//仮の移動先座標
		int Source_Num;			//親番号
		bool IsFast;			//最短距離かどうか
	};

	vector<Info> List;		//格納用


	VECTOR m_StartPos;	//保存用
	VECTOR m_GoalPos;	//保存用


public:
	//ボットの経路探索
	void Bot_Route_Search(VECTOR StartPos, VECTOR GoalPos, int MapHndl);

	//評価計算
	int KEISANN(Info info, int Info_Index ,int MapHndl);

	//経路探索時のマップとの当たり判定
	bool BoxToMap(VECTOR BoxCenter, int MapHndl);
};


