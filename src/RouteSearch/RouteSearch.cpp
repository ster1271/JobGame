#include "RouteSearch.h"

const int MAX_COST = 999;
const int MOVE_BLOKE = 1;
const float RADIUS = 5.0f;


//描画
void CRoute_Search::Draw()
{
	for (int a = 0; a < List.size(); a++)
	{
		CDraw3D::DrawBox3D(List[a].Pos, VGet(25.0f, 80.0f, 25.0f), GetColor(0, 255, 0));
	}
}


//ボットの経路探索
bool CRoute_Search::Route_Search(VECTOR StartPos, VECTOR GoalPos, CMap& cMap)
{
	
	List.clear();	//念のため

	m_StartPos = StartPos;
	m_GoalPos = GoalPos;

	Info tmp;
	memset(&tmp, -1, sizeof(Info));
	tmp.Pos = m_StartPos;
	tmp.Renge_form_Start = 0;


	bool IsFinish = false;		//探索終了フラグ


	int SaveCnt = 0;					//前回のループで増えた配列の個数
	int CurrentCnt = Evaluat_Calc(tmp, -1, cMap);	//今回のループで増えた配列の個数(スタート地点の親番号を-1とする)
	
	int LoopCount = 0;

	//フラグがfalseなら計算を行う
	while (!IsFinish)
	{
		int TotalMinCost = MAX_COST;	//最少評価コスト
		int vectorSize = List.size();	//リスト格納サイズ

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
				CurrentCnt += Evaluat_Calc(List[i], i, cMap);
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
		
		//ゴール判定する
		for (int i = List.size() - 1; i > List.size() - 1 - CurrentCnt; i--)
		{
			if (List[i].Renge_To_Goal == 0)
			{
				//ループを抜ける
				IsFinish = true;
				break;
			}
		}

		LoopCount++;
	}

	//ゴールからスタートまでの軌跡をたどる
	for (int i = List.size() - 1; i >= 0; i--)
	{

		//まずゴールと同座標を見つける
		if (List[i].Renge_To_Goal == 0)
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
	for (int i = List.size() - 1; i >= 0; i--)
	{
		if (List[i].IsFast == false)
		{
			List.erase(List.begin() + i);
		}
	}

	//座標のみ格納する
	for (int i = 0; i < List.size(); i++)
	{
		Pos_List.push_back(List[i].Pos);
	}

	return true;
}


//評価計算
int CRoute_Search::Evaluat_Calc(Info info, int Info_Index, CMap& cMap)
{
	//のちにpush_backするやつがinfoになる
	Info tmp[DIR_NUM];

	//pushbackした回数保存
	int cnt = 0;
	
	for (int i = 0; i < DIR_NUM; i++)
	{
		tmp[i].Renge_form_Start = info.Renge_form_Start + 1;
		tmp[i].Pos = info.Pos;

		//配列の親番号を格納する
		tmp[i].Source_Num = Info_Index;
	}
	
	
	//上下左右に計算する
	tmp[DIR_UP].Pos.z += 50.0f;
	tmp[DIR_DOWN].Pos.z -= 50.0f;
	tmp[DIR_LEFT].Pos.x += 50.0f;
	tmp[DIR_RIGHT].Pos.x -= 50.0f;

	
	for (int Index = 0; Index < DIR_NUM; Index++)
	{
		//スタート地点の座標が同じなら計算しない
		if (tmp[Index].Pos.x == m_StartPos.x &&
			//tmp[Index].Pos.y == m_StartPos.y &&
			tmp[Index].Pos.z == m_StartPos.z)
		{
			continue;
		}

		bool IsMatch = false;
		//Listに保存された座標と同じなら計算しない
		for (int i = 0; i < List.size(); i++)
		{
			if (tmp[Index].Pos.x == List[i].Pos.x &&
				//tmp[Index].Pos.y == List[i].Pos.y &&
				tmp[Index].Pos.z == List[i].Pos.z)
			{
				IsMatch = true;
				break;
			}
		}
		if (IsMatch)
			continue;

		//オブジェクトと当たっているか判定する
		bool IsHit = false;
		for (int i = 0; i < cMap.GetMapInfo().size(); i++)
		{
			if (tmp[Index].Pos.x == cMap.GetMapInfo()[i].vPos.x &&
				//tmp[Index].Pos.y == cMap.GetMapInfo()[i].vPos.y &&
				tmp[Index].Pos.z == cMap.GetMapInfo()[i].vPos.z)
			{
				if (cMap.GetMapInfo()[i].IsMap == true)
				{
					IsHit = true;
					break;
				}
			}
		}
		if (IsHit)
			continue;

		//移動コストを求める
		int _X = (int)fabs((m_GoalPos.x / 50.0f) - (tmp[Index].Pos.x / 50.0f));
		int _Z = (int)fabs((m_GoalPos.z / 50.0f) - (tmp[Index].Pos.z / 50.0f));
		tmp[Index].Renge_To_Goal = _X + _Z;

		//合計コストを求める(実コスト + 移動コスト)
		tmp[Index].Total_Cost = tmp[Index].Renge_form_Start + tmp[Index].Renge_To_Goal;

		//フラグをfalseにする
		tmp[Index].IsFast = false;

		List.push_back(tmp[Index]);

		cnt++;
	}

	return cnt;
}

