#pragma once
#include "DxLib.h"
#include "../Draw3D/Draw3D.h"
#include "math.h"
#include "../Input/Input.h"

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
	void Step();

	//描画
	void Draw();

	//後処理
	void Exit();

	//座標取得
	VECTOR GetPos() { return cPos; }


};