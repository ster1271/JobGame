#include "Shot.h"
#include "../Base/Base.h"
#include "../Character/Attacker.h"
#include "../Character/Tank.h"
#include "../Character/Support.h"

//----------------------------------------
//コンストラクタ
//----------------------------------------
CShot::CShot()
{
}

//----------------------------------------
//デストラクタ
//----------------------------------------
CShot::~CShot()
{
	//念のため
	Exit();
}

//----------------------------------------
//初期化
//----------------------------------------
void CShot::Init()
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
void CShot::Exit()
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
void CShot::Load(int iMdlHndl)
{
	if (iHndl == -1)
	{
		iHndl = MV1DuplicateModel(iMdlHndl);
	}
}


//----------------------------------------
//描画処理
//----------------------------------------
void CShot::Draw()
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


//----------------------------------------
//毎フレーム呼ぶ処理
//----------------------------------------
void CShot::Step(VECTOR Pos)
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
bool CShot::RequestShot(const VECTOR &vPos, const VECTOR &vSpeed)
{
	//すでに発射されている
	if (IsActive) return false;

	cPos = vPos;
	cSize = VGet(0.05f, 0.05f, 0.05f);
	cSpeed = vSpeed;
	IsActive = true;

	return true;
	
}


