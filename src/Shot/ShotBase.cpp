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
	if (IsActive)
	{
		MV1DrawModel(iHndl);

		DrawFormatString(500, 0, GetColor(255, 0, 0), "X座標：%f", cPos.x);
		DrawFormatString(500, 15, GetColor(255, 0, 0), "Y座標：%f", cPos.y);
		DrawFormatString(500, 30, GetColor(255, 0, 0), "Z座標：%f", cPos.z);
		/*DrawSphere3D(vPos, m_Radius, 16, GetColor(255, 255, 255), GetColor(255, 255, 255), FALSE);*/

	}
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