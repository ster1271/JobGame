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
	Dir = 0.0f;
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
void CTurretBase::Turret_Rotate(VECTOR vPos)
{
	//進行方向用変数
	Dir = 0.0f;

	//タレットと対象のベクトルを計算
	VECTOR Vtmp;
	Vtmp.x = vPos.x - cPos.x;
	Vtmp.y = 0.0f;
	Vtmp.z = vPos.z - cPos.z;

	//タレットの仮の移動ベクトルを計算
	VECTOR Turret_Vec = VECTOR_ZERO;
	Turret_Vec.x = sinf(cRotate.y) * 1.0f;
	Turret_Vec.y = 0.0f;
	Turret_Vec.z = cosf(cRotate.y) * 1.0f;

	//外積計算
	Dir = (Vtmp.x * Turret_Vec.z) - (Turret_Vec.x * Vtmp.z);

	//絶対値が1.0fより小さかったら
	if (fabsf(Dir) < 5.0f)
	{
		float X = vPos.x - cPos.x;
		float Z = vPos.z - cPos.z;

		//強制的に角度を変える
		float NextRotY = atan2f(X, Z);

		cRotate.y = NextRotY;
	}
	//回転する角度を決める
	else if (Dir >= 0.0f)
	{
		cRotate.y += 0.1f;
	}
	else if (Dir < 0.0f)
	{
		cRotate.y -= 0.1f;
	}
}



