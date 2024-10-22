#pragma once
#include "../Common.h"
#include "../MyLibrary/MyLibrary.h"
#include "../Map/Map.h"

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
		int Renge_form_Start;	//移動コスト(スタート地点から離れた距離)
		int Renge_To_Goal;		//推定コスト(ゴールまでの距離)
		int Total_Cost;			//合計コスト
		VECTOR Pos;				//仮の移動先座標
		int Source_Num;			//親番号
		bool IsFast;			//最短距離かどうか
	};

	vector<Info> List;			//格納用
	vector<VECTOR> Pos_List;	//座標引き渡し用


	VECTOR m_StartPos;	//保存用
	VECTOR m_GoalPos;	//保存用


public:
	//経路探索の結果のリスト取得
	vector<VECTOR> GetSearch_List() { return Pos_List; }

	//ボットの経路探索
	bool Route_Search(VECTOR StartPos, VECTOR GoalPos, CMap& cMap);

	//評価計算
	int Evaluat_Calc(Info info, int Info_Index, CMap& cMap);

	void Draw();
	
};


