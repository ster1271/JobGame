#include "TurretShot.h"

#define RADIUS	(3.0f)


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
	iHndl = MV1DuplicateModel(iMdlHndl);
}

//描画
void CTurretShot::Draw()
{
	if (IsActive)
	{
		MV1DrawModel(iHndl);
		DrawFormatString(500, 0, GetColor(255, 0, 0), "タレット弾X座標：%f", cPos.x);
		DrawFormatString(500, 15, GetColor(255, 0, 0), "タレット弾Y座標：%f", cPos.y);
		DrawFormatString(500, 30, GetColor(255, 0, 0), "タレット弾Z座標：%f", cPos.z);

		//DrawSphere3D(cPos, RADIUS, 16, GetColor(255, 255, 255), GetColor(255, 255, 255), FALSE);


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

	//情報の更新
	UpDate();
}

//リクエスト
bool CTurretShot::RequestShot(const VECTOR& vPos, const VECTOR& vSpeed)
{
	//すでに発射されている
	if (IsActive) return false;

	cPos = vPos;
	cSize = VGet(0.0005f, 0.0005f, 0.0005f);
	cSpeed = vSpeed;
	IsActive = true;

	return true;
}
