#pragma once
#include "../Object.h"

class Check_Point :public CObject
{
private:


public:
	//コンストラクタ・デストラクタ
	Check_Point();
	~Check_Point();

	//初期化
	void Init();

	//モデル読み込み
	void Load(int Hndl);

	//設置処理
	void Set_Point(const VECTOR vPos);

};
