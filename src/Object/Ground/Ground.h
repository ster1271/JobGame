#pragma once
#include "../object.h"

#define MAX_NUM		(10)

class CGround :public CObject
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
	CGround();
	~CGround();
	

	//初期化
	void Init();

	//モデル読み込み
	void Load();

	//描画
	void Draw();

};
