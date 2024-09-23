#pragma once
#include <DxLib.h>

class CShotBase
{
protected:
	VECTOR cPos;			//座標
	VECTOR cRotate;			//回転値
	VECTOR cSize;			//拡縮値
	VECTOR cSpeed;			//移動速度
	float Yspeed;			//Yスピード

	int iHndl;				//モデルのハンドル
	float Radius;			//モデルの半径
	bool IsActive;			//生存フラグ

public:

	//描画処理
	void Draw();

	//情報更新
	void UpDate();

	//座標取得
	VECTOR GetPos() { return cPos; }

	//フラグ情報所得
	bool GetIsActive() { return IsActive; }

};
