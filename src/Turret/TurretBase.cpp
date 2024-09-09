#include "TurretBase.h"

#define MAX_POWER_UP_COUNT	(5)	//最大強化回数

//コンストラクタ
TurretBase::TurretBase()
{
	memset(&ShotRenge, 0, sizeof(VECTOR));
	Life = 0.0f;
	Power_Up_Count = 0;
	IsActive = false;		
}

//デストラクタ
TurretBase::~TurretBase()
{
	iHndl = -1;

	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&ShotRenge, 0, sizeof(VECTOR));

	Life = 0.0f;
	Power_Up_Count = 0;
	IsActive = false;
}

//初期化
void TurretBase::Init()
{
	iHndl = -1;

	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));

	Life = 0.0f;
	Power_Up_Count = 0;
	IsActive = false;
}

//データロード
void TurretBase::Load(const char FILEPATH[])
{
	//モデルの読み込み
	iHndl = MV1LoadModel(FILEPATH);
}

//毎フレーム行う処理
void TurretBase::Step()
{
	
}

//後処理
void TurretBase::Exit()
{
	iHndl = -1;

	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));

	Life = 0.0f;
	Power_Up_Count = 0;
	IsActive = false;
}

//タレット設置処理
bool TurretBase::TurretSpawn(const VECTOR& vPos)
{
	if (IsActive) return false;

	cPos = vPos;
	cSize = VGet(1.0f, 1.0f, 1.0f);
	cRotate = VGet(0.0f, 0.0f, 0.0f);
	Power_Up_Count = 0;

	IsActive = true;

	return true;
}


//タレット強化
void TurretBase::Turret_Power_Up()
{
}