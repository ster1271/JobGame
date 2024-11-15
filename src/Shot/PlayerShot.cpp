#include "PlayerShot.h"
#include "../Player/Player.h"

//----------------------------------------
//コンストラクタ
//----------------------------------------
CPlayerShot::CPlayerShot()
{
}

//----------------------------------------
//デストラクタ
//----------------------------------------
CPlayerShot::~CPlayerShot()
{
	//念のため
	Exit();
}

//----------------------------------------
//初期化
//----------------------------------------
void CPlayerShot::Init()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cSpeed, 0, sizeof(VECTOR));

	iHndl = -1;
	Radius = 0.0f;
	IsActive = false;
}


//----------------------------------------
//終了処理
//----------------------------------------
void CPlayerShot::Exit()
{
	//モデルハンドル解放
	if (iHndl != -1)
	{
		MV1DeleteModel(iHndl); 
		iHndl = -1;
	}
}


//----------------------------------------
//データロード
//----------------------------------------
void CPlayerShot::Load(int iMdlHndl)
{
	if (iHndl == -1)
	{
		iHndl = MV1DuplicateModel(iMdlHndl);
	}
}


//----------------------------------------
//描画処理
//----------------------------------------
void CPlayerShot::Draw()
{
	if (IsActive)
	{
		MV1DrawModel(iHndl);

		if (IS_DEBUG)
		{
			DrawFormatString(500, 0, GetColor(255, 0, 0), "プレイヤー弾X座標：%f", cPos.x);
			DrawFormatString(500, 15, GetColor(255, 0, 0), "プレイヤー弾Y座標：%f", cPos.y);
			DrawFormatString(500, 30, GetColor(255, 0, 0), "プレイヤー弾Z座標：%f", cPos.z);
			DrawSphere3D(cPos, SHOTRADIUS, 16, GetColor(255, 255, 255), GetColor(255, 255, 255), FALSE);
		}
	}

}


//----------------------------------------
//毎フレーム呼ぶ処理
//----------------------------------------
void CPlayerShot::Step(VECTOR Pos)
{
	if (!IsActive) return;

	//座標に速度を加算
	cPos = VAdd(cPos, cSpeed);


	//一定範囲を超えたら消す
	float fLength =	500;

	if (cPos.x > Pos.x + fLength || cPos.x < Pos.x -fLength
		|| cPos.z > Pos.z + fLength || cPos.z < Pos.z - fLength)
	{
		IsActive = false;
	}

	//情報更新
	UpDate();
}


//----------------------------------------
//リクエスト
//----------------------------------------
bool CPlayerShot::RequestShot(const VECTOR &vPos, const VECTOR &vSpeed)
{
	//すでに発射されている
	if (IsActive) return false;

	cPos = vPos;
	cSize = VGet(0.05f, 0.05f, 0.05f);
	cSpeed = vSpeed;
	IsActive = true;

	return true;
	
}


