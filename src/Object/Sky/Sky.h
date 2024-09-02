#pragma once
#include "../object.h"

class CSky :public CObject
{
private:

public:
	//コンストラクタ・デストラクタ
	CSky();
	~CSky();

	//初期化
	void Init();

	//通常処理
	void Step(VECTOR vForcus, float fRot);

	//移動処理
	void SetSkyPos(VECTOR vF, VECTOR dir);
};
