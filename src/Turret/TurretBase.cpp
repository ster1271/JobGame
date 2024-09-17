#include "TurretBase.h"

#define MAX_POWER_UP_COUNT	(5)	//最大強化回数

//コンストラクタ
CTurretBase::CTurretBase()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&ShotRenge, 0, sizeof(VECTOR));

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
	memset(&ShotRenge, 0, sizeof(VECTOR));

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
	memset(&ShotRenge, 0, sizeof(VECTOR));

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

