#include "RouteSearch.h"

const float MAX_COST = 999.9f;


//ボットの経路探索
void CRoute_Search::Bot_Route_Search(VECTOR StartPos, VECTOR GoalPos)
{
	m_StartPos = StartPos;
	m_GoalPos = GoalPos;


}


//評価計算
void CRoute_Search::KEISANN(Info info)
{
	//のちにpush_backするやつがinfoになる
	Info tmp[DIR_NUM];
	
	for (int i = 0; i < DIR_NUM; i++)
	{
		tmp[i].Renge_form_Start = info.Renge_form_Start + 10.0f;
		tmp[i].Pos = info.Pos;
	}
	
	
	//上下左右に計算する
	tmp[DIR_UP].Pos.z += 10.0f;
	tmp[DIR_DOWN].Pos.z -= 10.0f;
	tmp[DIR_LEFT].Pos.x += 10.0f;
	tmp[DIR_RIGHT].Pos.x -= 10.0f;

	//距離を求める
	for (int i = 0; i < DIR_NUM; i++)
	{
		//前の座標と同じのがいたら計算しない
		if (tmp[i].Pos.x == info.Pos.x &&
			tmp[i].Pos.y == info.Pos.y &&
			tmp[i].Pos.z == info.Pos.z)
		{
			continue;
		}
		
		//各辺10のBOXとマップの当たり判定をとる
	/*	if ()
			continue;*/

		float _X = fabs(m_GoalPos.x - tmp[i].Pos.x);
		float _Z = fabs(m_GoalPos.z - tmp[i].Pos.z);
		tmp[i].Renge_To_Goal = _X + _Z;

		//合計コストを求める
		float Total_Min_Cost = MAX_COST;
		tmp[i].Total_Cost = tmp[i].Renge_form_Start + tmp[i].Renge_To_Goal;
		
		//合計コストの最少を格納する
		if (tmp[i].Total_Cost <= Total_Min_Cost)
		{
			Total_Min_Cost = tmp[i].Total_Cost;
		}


		List.push_back(tmp[i]);
	}

}