#pragma once
#include "../Object/Object.h"

#define MAX_NUM		(10)

class CMap :public CObject
{
	struct MapInfo
	{
		VECTOR vPos;
		bool IsMap;
	};


private:

	MapInfo Mapinfo;
	int tmp[MAX_NUM][MAX_NUM];
	FILE* fp_;

	vector<MapInfo>MapList;

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

};



