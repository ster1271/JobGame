#include "TurretBase.h"

//コンストラクタ
TurretBase::TurretBase()
{
	memset(&ShotRenge, 0, sizeof(VECTOR));
	Life = 0.0f;
	IsActive = false;		
}

//デストラクタ
TurretBase::~TurretBase()
{
	memset(&ShotRenge, 0, sizeof(VECTOR));

	Life = 0.0f;
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

//タレット設置処理
bool TurretBase::TurretSpawn(const VECTOR& vPos)
{
	//すでに発射されている
	if (IsActive) return false;

	cPos = vPos;
	cSize = VGet(1.0f, 1.0f, 1.0f);
	cRotate = VGet(0.0f, 0.0f, 0.0f);
	IsActive = true;

	return true;
}


//タレット強化
void TurretBase::Turret_Power_Up()
{
	
}