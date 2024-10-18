#pragma once
#include "../object.h"

#define MAX_NUM		(10)

class CGround :public CObject
{
private:
	int tmp[MAX_NUM][MAX_NUM];
	

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

	//ハンドル取得
	int GetHndl() { return iHndl; }

};
