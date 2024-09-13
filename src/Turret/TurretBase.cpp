#include "TurretBase.h"

#define MAX_POWER_UP_COUNT	(5)	//最大強化回数

//コンストラクタ
TurretBase::TurretBase()
{
	CObject::Init();
	memset(&ShotRenge, 0, sizeof(VECTOR));

	Hp = 0.0f;
	Power_Up_Count = 0;
	IsActive = false;		
}

//デストラクタ
TurretBase::~TurretBase()
{
}

//初期化
void TurretBase::Init()
{
	CObject::Init();
	memset(&ShotRenge, 0, sizeof(VECTOR));

	Hp = 0.0f;
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
	memset(&ShotRenge, 0, sizeof(VECTOR));

	Hp = 0.0f;
	Power_Up_Count = 0;
	/*IsActive = false;*/
}

//タレット設置処理
bool TurretBase::TurretSpawn(const VECTOR vPos)
{
	return true;
}


//タレット強化
void TurretBase::Turret_Power_Up()
{
}