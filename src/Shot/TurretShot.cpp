#include "TurretShot.h"


//コンストラクタ・デストラクタ
CTurretShot::CTurretShot()
{
}

CTurretShot::~CTurretShot()
{
}

//初期化
void CTurretShot::Init()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cSpeed, 0, sizeof(VECTOR));

	iHndl = -1;
	Radius = 0.0f;
	IsActive = false;
}

//読み込み
void CTurretShot::Load(int iMdlHndl)
{
	if (iHndl == -1)
	{
		iHndl = MV1DuplicateModel(iMdlHndl);
	}
}

//描画
void CTurretShot::Draw()
{
	if (IsActive)
	{
		MV1DrawModel(iHndl);

		/*DrawFormatString(500, 0, GetColor(255, 0, 0), "X座標：%f", cPos.x);
		DrawFormatString(500, 15, GetColor(255, 0, 0), "Y座標：%f", cPos.y);
		DrawFormatString(500, 30, GetColor(255, 0, 0), "Z座標：%f", cPos.z);*/
		/*DrawSphere3D(vPos, m_Radius, 16, GetColor(255, 255, 255), GetColor(255, 255, 255), FALSE);*/

	}
}

//毎フレーム行う処理
void CTurretShot::Step(VECTOR TurretPos)
{
	if (!IsActive) return;

	//座標に速度を加算
	cPos = VAdd(cPos, cSpeed);


	//一定範囲を超えたら消す
	float fLength = 100;

	/*if (cPos.x > TurretPos.x + fLength || cPos.x < TurretPos.x - fLength
		|| cPos.z > TurretPos.z + fLength || cPos.z < TurretPos.z - fLength)
	{
		IsActive = false;
	}*/

}

//リクエスト
bool CTurretShot::RequestShot(const VECTOR& vPos, const VECTOR& vSpeed)
{
	//すでに発射されている
	if (IsActive) return false;

	cPos = vPos;
	cSize = VGet(0.05f, 0.05f, 0.05f);
	cSpeed = vSpeed;
	IsActive = true;

	return true;
}
