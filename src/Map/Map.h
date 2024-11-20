#pragma once
#include "../Object/Object.h"
#include "block/block.h"

const VECTOR MAP_SIZE = VGet(50.0f, 50.0f, 50.0f);


struct WallInfo
{
	VECTOR vPos;
	bool IsMap;
	int iHndl;
};

struct FloarInfo
{
	VECTOR vPos;
	bool IsMap;
	int iHndl;
};

class CMap :public CObject
{

private:
	
	FILE* fp_;				//ファイル用
	vector<WallInfo>WallList;	//壁情報格納リスト
	vector<FloarInfo>FloarList;	//床情報格納リスト

public:
	//コンストラクタ・デストラクタ
	CMap();
	~CMap();


	//初期化
	void Init();

	//モデル読み込み
	void Load();

	//描画
	void Draw();

	//更新
	void Updata();

	//CSV読み込み
	void MapLoad();

	//壁情報取得
	vector<WallInfo> GetWallList() { return WallList; }
	
	//床情報取得
	vector<FloarInfo> GetFloarList() { return FloarList; }
};



