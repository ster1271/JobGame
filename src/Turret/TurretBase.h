#pragma once
#include <math.h>
#include "../Object/Object.h"



//タレットベースクラス
class CTurretBase
{
protected:
	int Org_Hndl;		//モデルハンドル(コピー元)
	int iHndl;			//モデルハンドル(コピー用)

	VECTOR cPos;		//座標
	VECTOR cRotate;		//回転値
	VECTOR cSize;		//拡縮値
	VECTOR ShotRenge;	//射程距離

	float Hp;			//タレットのHP
	int Power_Up_Count;	//強化回数

	bool IsActive;		//生存フラグ

public:
	CTurretBase();
	~CTurretBase();
	
	//初期化
	void Init();

	//モデル読み込み
	virtual void Load(int Hndl) = 0;
	
	//描画
	virtual void Draw() = 0;

	//毎フレーム行う処理
	virtual void Step(const VECTOR vPos) = 0;

	//情報更新
	void Update();

	//後処理
	void Exit();

	//座標取得
	VECTOR GetPos() { return cPos; }

	//サイズ取得
	VECTOR GetSize() { return cSize; }

	//回転地取得
	VECTOR GetRotate() { return cRotate; }

	//フラグ取得
	bool GetIsActive() { return IsActive; }

	//タレット設置処理
	virtual void TurretSpawn(const VECTOR &vPos) = 0;

	//タレット強化
	virtual void Turret_Power_Up();

	//タレット発射処理
	virtual void Turret_Rotate(const VECTOR vPos);

};

