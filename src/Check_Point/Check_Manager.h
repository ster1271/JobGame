#pragma once
#include "Check_Point.h"

#define MAX_NUM	(5)

class CChecck_Manager
{
private:
	int check_Hndl;
	CCheck_Point cCheck_Point[MAX_NUM];

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

	void Step();

	//リスト情報取得
	vector<VECTOR> Get_List()
	{
		return cCheck_Point->Get_List();
	}
};
