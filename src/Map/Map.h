#pragma once
#include "../Object/Object.h"

//マップ情報
struct MapInfo
{
	VECTOR vPos;
	bool IsMap;
};

class CMap :public CObject
{

private:

	FILE* fp_;				//ファイル用
	vector<MapInfo>MapList;	//マップ情報格納リスト

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

	//CSV読み込み
	void MapLoad();

	//マップ情報取得
	vector<MapInfo> GetMapInfo() { return MapList; }

	//マップサイズ取得
	VECTOR GetMapSize() { return cSize; }
};



