#pragma once
#include <DxLib.h>

//オブジェクトクラス
class CObject
{

public:
	//コンストラクタ・デストラクタ
	CObject();
	~CObject();

protected:
	VECTOR cPos;		//座標
	int cHp;			//HP
	float cGravity;		//重力
	float cYspeed;		//Yスピード

	VECTOR cRotate;		//回転値

	int iHndl;			//ハンドル
};
