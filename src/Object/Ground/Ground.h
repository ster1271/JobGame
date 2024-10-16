#pragma once
#include "../object.h"

class CGround :public CObject
{
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
