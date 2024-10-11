#pragma once
#include "DxLib.h"
#include "math.h"
#include "../Draw3D/Draw3D.h"
#include "../Input/Input.h"
#include "../Check_Point/Check_Manager.h"


class CGame_Pointer
{
private:
	VECTOR cPos;
	VECTOR cBoxSize;

	int	iHndl;

public:
	//コンストラクタ・デストラクタ
	CGame_Pointer();
	~CGame_Pointer();

	//初期化
	void Init();
	
	//読み込み
	void Load();

	//毎フレーム行う処理
	void Step(Check_ID id);

	//描画
	void Draw(Check_ID id);

	//後処理
	void Exit();

	//座標取得
	VECTOR GetPos() { return cPos; }


};