#pragma once
#include "Object.h"

class CRoute_Point :public CObject
{
private:


public:
	//コンストラクタ・デストラクタ
	CRoute_Point();
	~CRoute_Point();

	//初期化
	void Init();

	//モデル読み込み
	void Load();

};
