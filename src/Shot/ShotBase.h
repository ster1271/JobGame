#pragma once
#include "../Common.h"

#define SHOT_RADIUS	(3.0f)


class CShotBase
{
protected:
	VECTOR cPos;			//座標
	VECTOR cRotate;			//回転値
	VECTOR cSize;			//拡縮値
	VECTOR cSpeed;			//移動速度

	VECTOR SetPos;			//初期地点

	int iHndl;				//モデルのハンドル
	float Radius;			//モデルの半径
	bool IsActive;			//生存フラグ

public:
	//コンストラクタ・デストラクタ
	CShotBase();
	~CShotBase();

	//描画処理
	virtual void Draw();

	//情報更新
	void UpDate();

	//リクエスト
	bool RequestShot(const VECTOR& vPos, const VECTOR& vSpeed);

	//後処理
	void Exit();

	//座標取得
	VECTOR GetPos() { return cPos; }

	//フラグ情報所得
	bool GetIsActive() { return IsActive; }

	//半径取得
	float GetRadius() { return SHOT_RADIUS; }

	//当たり判定の処理
	void HitCalc()
	{
		//当たったらフラグをおる
		IsActive = false;
	}

};
