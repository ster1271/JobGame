#include "TurretBase.h"

#define MAX_POWER_UP_COUNT	(5)	//最大強化回数

//コンストラクタ
CTurretBase::CTurretBase()
{
	//ハンドルの初期化
	Org_Hndl = -1;
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	ShotRenge = 0.0f;

	Hp = 0.0f;
	Power_Up_Count = 0;
	IsActive = false;		
}

//デストラクタ
CTurretBase::~CTurretBase()
{
}

//初期化
void CTurretBase::Init()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	ShotRenge = 0.0f;

	Hp = 0.0f;
	Power_Up_Count = 0;
	IsActive = false;
}

//後処理
void CTurretBase::Exit()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	ShotRenge = 0.0f;

	Hp = 0.0f;
	Power_Up_Count = 0;
	IsActive = false;
}

//毎フレーム行う処理
void Step(const VECTOR vPos, CShotManager& cShotManager) {};

//情報更新
void CTurretBase::Update()
{
	MV1SetPosition(iHndl, cPos);		//座標の更新
	MV1SetScale(iHndl, cSize);			//サイズの更新
	MV1SetRotationXYZ(iHndl, cRotate);	//回転値の更新
}

//タレット強化
void CTurretBase::Turret_Power_Up()
{

}


//タレット発射処理
void CTurretBase::Turret_Rotate(const VECTOR vPos)
{
	//タレットと対象のベクトルを計算
	VECTOR Vtmp;
	Vtmp.x = vPos.x - cPos.x;
	Vtmp.y = 0.0f;
	Vtmp.z = vPos.z - cPos.z;

	//タレットの仮の移動ベクトルを計算
	VECTOR Turret_Vec;
	Turret_Vec.x = sinf(cRotate.y) * 1.0f;
	Turret_Vec.y = 0.0f;
	Turret_Vec.z = cosf(cRotate.y) * 1.0f;

	//外積計算
	float Dir = Vtmp.x * Turret_Vec.z - Vtmp.z * Turret_Vec.x;

	//回転する角度を決める
	if (Dir >= 0.0f)
	{
		cRotate.y += 0.01f;
	}
	else if (Dir < 0.0f)
	{
		cRotate.y -= 0.01f;
	}
}


