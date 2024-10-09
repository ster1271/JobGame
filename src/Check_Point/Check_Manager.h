#pragma once
#include "Check_Point.h"
#include "../Input/Input.h"

#define MAX_NUM	(5)

class CChecck_Manager
{
private:
	enum Check_ID
	{
		ID_CHECK_POINT = 0,	//チェックポイント
		ID_ENEMY_SPAWN,		//敵の沸きポイント

		ID_NUM
	};

	Check_ID check_id;
	int check_Hndl;
	CCheck_Point cCheck_Point[MAX_NUM];

	vector<VECTOR> Point_info_List;
	FILE* fp;


public:
	//コンストラクタ・デストラクタ
	CChecck_Manager();
	~CChecck_Manager();

	//初期化
	void Init();

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
};
