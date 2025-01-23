#pragma once
#include "../Common.h"
#include "../MyLibrary/MyLibrary.h"
#include "../Map/MapManager.h"
#include "../Debug/DebugString.h"


//状態遷移
enum NODE_STATE
{
	NONE = 0,	//未定
	OPEN,		//判定中
	CLOSE,		//判定終了
};

class CRoute_Search
{
private:

	static CRoute_Search* cInstance;		//インスタンス

	enum DIR
	{
		DIR_UP = 0,
		DIR_DOWN,
		DIR_LEFT,
		DIR_RIGHT,
		DIR_NUM,
	};

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
	int ListCnt;				//リストカウント
	bool IsFinish;				//探索終了フラグ


	VECTOR m_StartPos;	//保存用
	VECTOR m_GoalPos;	//保存用

	float tmp;

	//コンストラクタ・デストラクタ
	CRoute_Search();
	~CRoute_Search();

public:

	static void Create();				//インスタンスの生成

	static void Destroy();				//インスタンスの削除

	static CRoute_Search* GetInstance();		//インスタンスの取得

	//初期化
	void Init();

	//後処理
	void Exit();

	//フラグ取得
	bool GetIsFinish() { return IsFinish; }

	//経路探索
	vector<VECTOR> Route_Search(VECTOR StartPos, VECTOR GoalPos, CMapManager& cMapManager);

	//評価計算
	int Evaluat_Calc(Info info, int Info_Index, CMapManager& cMapManager);

	//描画
	void Draw(unsigned int Color);
	
	//割り算
	int Remain(int A, int B){ return A % B; }

};


