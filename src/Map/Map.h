#pragma once
#include "../Object/Object.h"

const VECTOR MAP_SIZE = VGet(50.0f, 50.0f, 50.0f);
const float MAP_R = 30.0f;

enum MapID
{
	MAPID_01,


	MAPID_NUM
};

//マップのファイルパス
static const char MapFilePath[MAPID_NUM][128]
{
	"Data/Map/map01.txt",
};


struct WallInfo
{
	VECTOR vPos;
	VECTOR MiniMapPos;
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

	//マップの読み込み1
	void LoadMap1(MapID id);

	//マップの読み込み2
	void LoadMap2(MapID id);
};



