#include "ShotBase.h"

//コンストラクタ・デストラクタ
CShotBase::CShotBase()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cSpeed, 0, sizeof(VECTOR));

	iHndl = -1;
	Radius = 0.0f;
	IsActive = false;
}

CShotBase::~CShotBase()
{
	Exit();
}

//描画処理
void CShotBase::Draw()
{
}

//情報更新
void CShotBase::UpDate()
{
	MV1SetPosition(iHndl, cPos);
	MV1SetScale(iHndl, cSize);
	MV1SetRotationXYZ(iHndl, cRotate);
}

//後処理
void CShotBase::Exit()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cSpeed, 0, sizeof(VECTOR));

	iHndl = -1;
	Radius = 0.0f;
	IsActive = false;
}


//リクエスト
bool CShotBase::RequestShot(const VECTOR& vPos, const VECTOR& vSpeed)
{
	//すでに発射されている
	if (IsActive) return false;

	cPos = vPos;
	cSpeed = vSpeed;
	IsActive = true;

	return true;

}