#include "RouteSearch.h"

const float MAX_COST = 999.9f;
const float RADIUS = 5.0f;


//ボットの経路探索
void CRoute_Search::Bot_Route_Search(VECTOR StartPos, VECTOR GoalPos, int MapHndl)
{
	List.clear();	//念のため

	m_StartPos = StartPos;
	m_GoalPos = GoalPos;

	Info tmp;
	tmp.Pos = m_StartPos;
	tmp.Renge_form_Start = 0.0f;


	bool IsFinish = false;		//探索終了フラグ


	int SaveCnt = 0;							// 前回のループで増えた配列の個数
	int CurrentCnt = KEISANN(tmp, -1, MapHndl);	// 今回のループで増えた配列の個数	(スタート地点の親番号を-1とする)
	

	//フラグがfalseなら計算を行う
	while (!IsFinish)
	{
		float TotalMinCost = MAX_COST;		//最少評価コスト
		float NextTotalMinCost = MAX_COST;
		int vectorSize = List.size();


		SaveCnt = CurrentCnt;
		CurrentCnt = 0;

		//評価値が一番低いものを求める
		for (int i = vectorSize - 1; i > vectorSize - 1 - SaveCnt; i--)
		{
			if (List[i].Total_Cost < TotalMinCost)
			{
				TotalMinCost = List[i].Total_Cost;
			}
		}

		//評価値が一番低いもので計算する
		for (int i = vectorSize - 1; i > vectorSize - 1 - SaveCnt; i--)
		{
			if (List[i].Total_Cost == TotalMinCost)
			{
				CurrentCnt += KEISANN(tmp, i, MapHndl); 
			}
		}

		/*
		//もしカウントが増加しない時に
		if (CurrentCnt == 0)
		{
			//二番目の評価値を算出する
			for (int i = 0; i < List.size() - 1; i++)
			{
				
			}
		}
		*/
		
		//ゴール判定するよ
		for (int i = List.size() - 1; i > List.size() - 1 - CurrentCnt; i--)
		{
			if (List[i].Renge_To_Goal == 0.0f)
			{
				//ループを抜ける
				IsFinish = true;
				break;
			}
		}
	}

	//ゴールからスタートまでの軌跡をたどる
	for (int i = List.size() - 1; i > 0; i--)
	{
		//まずゴールと同座標を見つける
		if (List[i].Renge_To_Goal == 0.0f)
		{
			List[i].IsFast = true;
		}

		//最初に見つけた配列の親番号をたどっていく
		if (List[i].IsFast == true)
		{
			List[List[i].Source_Num].IsFast = true;

			//親番号が-1(スタート番号)になったらこの処理をやめる
			if (List[List[i].Source_Num].Source_Num == -1)
			{
				break;
			}
		}
	}

	//フラグがfalseの配列番号を削除する
	for (int i = List.size() - 1; i > 0; i--)
	{
		if (List[i].IsFast == false)
		{
			List.erase(List.begin() + i);
		}
	}


}


//評価計算
int CRoute_Search::KEISANN(Info info, int Info_Index, int MapHndl)
{
	//のちにpush_backするやつがinfoになる
	Info tmp[DIR_NUM];

	//pushbackした回数保存
	int cnt = 0;
	
	for (int i = 0; i < DIR_NUM; i++)
	{
		tmp[i].Renge_form_Start = info.Renge_form_Start + 10.0f;
		tmp[i].Pos = info.Pos;

		//配列の親番号を格納する
		tmp[i].Source_Num = Info_Index;
	}
	
	
	//上下左右に計算する
	tmp[DIR_UP].Pos.z += 10.0f;
	tmp[DIR_DOWN].Pos.z -= 10.0f;
	tmp[DIR_LEFT].Pos.x += 10.0f;
	tmp[DIR_RIGHT].Pos.x -= 10.0f;

	//距離を求める
	for (int i = 0; i < DIR_NUM; i++)
	{
		//スタート地点の座標が同じなら計算しない
		if (tmp[i].Pos.x == m_StartPos.x &&
			tmp[i].Pos.y == m_StartPos.y &&
			tmp[i].Pos.z == m_StartPos.z)
		{
			continue;
		}

		//Listに保存された座標と同じなら計算しない
		for (int i = 0; i < List.size(); i++)
		{
			if (tmp[i].Pos.x == List[i].Pos.x &&
				tmp[i].Pos.y == List[i].Pos.y &&
				tmp[i].Pos.z == List[i].Pos.z)
			{
				continue;
			}
		}


		//各辺10のBOXとマップの当たり判定をとる
		if (BoxToMap(tmp[i].Pos, MapHndl))
			continue;

		float _X = fabs(m_GoalPos.x - tmp[i].Pos.x);
		float _Z = fabs(m_GoalPos.z - tmp[i].Pos.z);
		tmp[i].Renge_To_Goal = _X + _Z;

		//合計コストを求める
		tmp[i].Total_Cost = tmp[i].Renge_form_Start + tmp[i].Renge_To_Goal;

		List.push_back(tmp[i]);

		cnt++;
	}

	return cnt;
}


//経路探索時のマップとの当たり判定
bool CRoute_Search ::BoxToMap(VECTOR BoxCenter, int MapHndl)
{
	//当たり判定
	MV1_COLL_RESULT_POLY_DIM result;
	result = MV1CollCheck_Sphere(MapHndl, -1, BoxCenter, RADIUS);

	//当たったらtrueを返す
	if (result.Dim->HitFlag == true)
	{
		return true;
	}

	return false;
}
