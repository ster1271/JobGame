#pragma once
#include <DxLib.h>
#include <iostream>
#include <vector>
#include "../Check_Point/Check_Base.h"

#define  MAX_NUM	(5)

using namespace std;

class CCheck_Point: public CCheck_Base
{
private:
	vector<VECTOR> Point_info_List;
	int tmp_Hndl;
	int tmp;

public:
	//コンストラクタ・デストラクタ
	CCheck_Point();
	~CCheck_Point();

	//初期化
	void Init(FILE * fp);

	//モデル読み込み
	void Load(int Hndl);

	//描画
	void Draw();

	//毎フレーム行う処理
	void Step();

	//後処理
	void Exit();

	//リスト所得
	vector<VECTOR> Get_List()
	{
		return Point_info_List;
	}

	//設置処理
	void Set_Point(const VECTOR vPos);


	//ファイル読み込み
	void LoadFile();
};
