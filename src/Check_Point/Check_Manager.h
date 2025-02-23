#pragma once
#include "Check_Base.h"
#include "Check_Point.h"
#include "../Input/Input.h"

#define CHECK_MAX_NUM	(5)

enum CHECK_ID
{
	ID_CHECK_POINT = 0,	//チェックポイント
	ID_ENEMY_SPAWN,		//敵の沸きポイント

	MAX_ID,
};

class CChecck_Manager
{
private:
	

	vector<VECTOR> Point_info_List;
	vector<CCheck_Base*> Info_List;
	FILE* fp;

	CHECK_ID Check_id;
	int check_Hndl;
	CCheck_Point cCheck_Point[CHECK_MAX_NUM];


public:
	//コンストラクタ・デストラクタ
	CChecck_Manager();
	~CChecck_Manager();

	//初期化
	void Init();

	//全ての情報読み取り
	void LoadInfo();

	//データ読み込み
	void Load();

	//後処理
	void Exit();

	//情報更新
	void Updata();

	//描画
	void Draw();

	//プレイ時の処理
	void Step();

	//デバック時の処理
	void DebugStep(VECTOR vPos);

	//デバック時の描画
	void DebugDraw();

	//リスト情報取得
	vector<VECTOR> Get_List()
	{
		return Point_info_List;
	}

	CHECK_ID GetID() { return Check_id; }
};
