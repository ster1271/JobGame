#pragma once
#include <DxLib.h>
#include <iostream>
#include <vector>

#define  MAX_NUM	(5)

using namespace std;

class CCheck_Point
{
private:
	VECTOR cPos[MAX_NUM];		//座標
	VECTOR cSize[MAX_NUM];		//サイズ
	VECTOR cRotate[MAX_NUM];	//回転値

	int iHndl[MAX_NUM];			//ハンドル

	bool IsActive[MAX_NUM];		//フラグ

	vector<VECTOR> Point_info_List;
	int tmp_Hndl;
	int tmp;

public:
	//コンストラクタ・デストラクタ
	CCheck_Point();
	~CCheck_Point();

	//初期化
	void Init();

	//モデル読み込み
	void Load();

	//描画
	void Draw();

	//情報更新
	void UpData();

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
	void Set_Point(int Index, const VECTOR vPos);


	//ファイル読み込み
	void LoadFile();
};
