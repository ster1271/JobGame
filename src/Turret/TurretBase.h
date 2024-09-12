#pragma once
#include "../Object/Object.h"

//タレットベースクラス
class TurretBase : public CObject
{
protected:
	VECTOR ShotRenge;	//射程距離
	VECTOR ShotSpeed;		//射撃スピード
	float Life;			//タレットのHP
	int Power_Up_Count;	//強化回数

	bool IsActive;		//生存フラグ

public:
	TurretBase();
	~TurretBase();
	
	//初期化
	void Init();

	//データロード
	void Load(const char FILEPATH[]);

	//毎フレーム行う処理
	virtual void Step() = 0;

	//後処理
	void Exit();

	//タレット設置処理
	bool TurretSpawn(const VECTOR& vPos);

	//タレット強化
	void Turret_Power_Up();

};

