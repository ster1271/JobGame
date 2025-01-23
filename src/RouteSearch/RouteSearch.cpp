#include "RouteSearch.h"

const int MAX_COST = 999;
const int CALC_DIS = 50;
const int MOVE_BLOKE = 1;
const float MOVE_SPEED = 0.2f;
const float RADIUS = 5.0f;

//インスタンスの初期化
CRoute_Search* CRoute_Search::cInstance = nullptr;


//コンストラクタ
CRoute_Search::CRoute_Search()
{
	List.clear();
	ListCnt = 0;
	IsFinish = false;
}

//デストラクタ
CRoute_Search::~CRoute_Search(){}



//インスタンスの生成
void CRoute_Search::Create()
{
	//インスタンスにが生成されていなかったら
	if (cInstance == nullptr)
	{
		//新しくnewする
		cInstance = new CRoute_Search();
	}
}


//インスタンスの削除
void CRoute_Search::Destroy()
{
	//インスタンスが生成されていたら
	if (cInstance != nullptr)
	{
		//deleteしてnullptrを入れる
		delete cInstance;
		cInstance = nullptr;
	}
}


//インスタンスの取得
CRoute_Search* CRoute_Search::GetInstance()
{
	if (cInstance == nullptr)
	{
		//インスタンスが生成されていなかったら生成する
		Create();
		return cInstance;
	}
	else
	{
		return cInstance;
	}
}

//初期化
void CRoute_Search::Init()
{
	List.clear();
	ListCnt = 0;
	IsFinish = false;
}

//後処理
void CRoute_Search::Exit()
{
	List.clear();
	ListCnt = 0;
	IsFinish = false;
}

//描画
void CRoute_Search::Draw(unsigned int Color)
{
	for (int a = 0; a < List.size(); a++)
	{
		CDraw3D::DrawBox3D(List[a].Pos, VGet(25.0f, 80.0f, 25.0f), Color);
	}
}


//経路探索
vector<VECTOR> CRoute_Search::Route_Search(VECTOR StartPos, VECTOR GoalPos, CMapManager& cMapManager)
{
	
	List.clear();			//念のため
	List.shrink_to_fit();	//念のため

	m_StartPos.x = (int)StartPos.x;
	m_StartPos.y = (int)StartPos.y;
	m_StartPos.z = (int)StartPos.z;

	m_GoalPos.x = (int)GoalPos.x;
	m_GoalPos.y = (int)GoalPos.y;
	m_GoalPos.z = (int)GoalPos.z;

	//X座標が50で割り切れないとき
	int Result = Remain((int)m_StartPos.x, CALC_DIS);
	if (Result != 0)
	{
		//計算結果が規定値より小さいとき
		if (Result <= 25)
		{
			m_StartPos.x -= Result;
		}
		else
		{
			Result = CALC_DIS - Result;
			m_StartPos.x += Result;
		}
	}

	Result = Remain((int)m_StartPos.z, CALC_DIS);
	if (Result != 0)
	{
		//計算結果が規定値より小さいとき
		if (Result < 25)
		{
			m_StartPos.z -= Result;
		}
		else
		{
			Result = CALC_DIS - Result;
			m_StartPos.z += Result;
		}
	}

	Info tmp;
	memset(&tmp, -1, sizeof(Info));
	tmp.Pos = m_StartPos;
	tmp.Renge_form_Start = 0;


	bool IsFinish = false;		//探索終了フラグ


	int SaveCnt = 0;			//前回のループで増えた配列の個数
	int CurrentCnt = Evaluat_Calc(tmp, -1, cMapManager);	//今回のループで増えた配列の個数(スタート地点の親番号を-1とする)
	
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


		//評価値が一番低いものを新たに計算する
		for (int i = vectorSize - 1; i > vectorSize - 1 - SaveCnt; i--)
		{
			if (List[i].Total_Cost == TotalMinCost)
			{
				CurrentCnt += Evaluat_Calc(List[i], i, cMapManager);
			}
		}

		//増えなかったらリストの中で結果がいいのを計算する
		if (CurrentCnt == 0)
		{
			TotalMinCost = MAX_COST;	//最少評価コスト再設定
			//評価がすべて並んだ時
			for (int i = vectorSize - 1; i > vectorSize - 1 - SaveCnt; i--)
			{
				if (List[i].Total_Cost < TotalMinCost)
				{
					TotalMinCost = List[i].Total_Cost;
				}
			}

			//評価値が一番低いものを新たに計算する
			for (int i = vectorSize - 1; i > vectorSize - 1 - SaveCnt; i--)
			{
				if (List[i].Total_Cost == TotalMinCost)
				{
					CurrentCnt += Evaluat_Calc(List[i], i, cMapManager);
				}
			}
		}
		
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

	vector<VECTOR>Pos_List;
	Pos_List.clear();
	//座標のみ格納する
	for (int i = 0; i < List.size(); i++)
	{
		Pos_List.push_back(List[i].Pos);
	}

	//リストを削除する
	List.clear();

	return Pos_List;
}


//評価計算
int CRoute_Search::Evaluat_Calc(Info info, int Info_Index, CMapManager& cMapManager)
{
	//のちにpush_backするやつがinfoになる
	Info tmp[DIR_NUM];

	//pushbackした回数保存
	int cnt = 0;
	
	for (int i = 0; i < DIR_NUM; i++)
	{
		//ゴールからスタートまでの距離を求める
		tmp[i].Pos = info.Pos;
		//配列の親番号を格納する
		tmp[i].Source_Num = Info_Index;
	}
	
	//上下左右に計算する
	tmp[DIR_UP].Pos.z += CALC_DIS;
	tmp[DIR_DOWN].Pos.z -= CALC_DIS;
	tmp[DIR_LEFT].Pos.x += CALC_DIS;
	tmp[DIR_RIGHT].Pos.x -= CALC_DIS;

	for (int i = 0; i < DIR_NUM; i++)
	{
		//スタートからの距離
		tmp[i].Renge_form_Start = (int)fabs((tmp[i].Pos.x - m_StartPos.x) / CALC_DIS) + (int)fabs((tmp[i].Pos.z - m_StartPos.z) / CALC_DIS)/* = info.Renge_form_Start + 1*/;
	}
	
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
				tmp[Index].Pos.z == List[i].Pos.z)
			{
				IsMatch = true;
				break;
			}
		}
		//trueならこれ以降計算せずfor文を回す
		if (IsMatch)
			continue;

		//オブジェクトと当たっているか判定する
		bool IsHit = false;
		for (int i = 0; i < cMapManager.GetMap().GetWallList().size(); i++)
		{
			if (tmp[Index].Pos.x == cMapManager.GetMap().GetWallList()[i].vPos.x &&
				//tmp[Index].Pos.y == cMap.GetMapInfo()[i].vPos.y &&
				tmp[Index].Pos.z == cMapManager.GetMap().GetWallList()[i].vPos.z)
			{
				if (cMapManager.GetMap().GetWallList()[i].IsMap == true)
				{
					IsHit = true;
					break;
				}
			}
		}
		//trueならこれ以降計算せずfor文を回す
		if (IsHit)
			continue;

		//移動コストを求める
		int _X = (int)fabs((m_GoalPos.x / CALC_DIS) - (tmp[Index].Pos.x / CALC_DIS));
		int _Z = (int)fabs((m_GoalPos.z / CALC_DIS) - (tmp[Index].Pos.z / CALC_DIS));
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

