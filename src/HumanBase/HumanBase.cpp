#include "HumanBase.h"
#include "../Mouse/Mouse.h"


//コンストラクタ
CHumanBase::CHumanBase()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cNextPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cMoveRotate, 0, sizeof(VECTOR));
	memset(&cScale, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));

	IsActive = false;

	MouseX = MouseY = 0;

	Life = -1;
	iHndl = -1;
	PushCnt = 0;
	ReturnCnt = 0;
}

//デストラクタ
CHumanBase::~CHumanBase(){}


//初期化
void CHumanBase::Init()
{
	//変数の初期化
	cPos = VECTOR_ZERO;
	cNextPos = VECTOR_ZERO;
	cRotate = VECTOR_ZERO;
	cMoveRotate = VECTOR_ZERO;
	cScale = VECTOR_ZERO;
	cSize = VECTOR_ZERO;

	IsActive = false;

	MouseX = MouseY = 0;

	Life = 0;
	iHndl = 0;
	PushCnt = 0;
	ReturnCnt = 0;
}

//データ読み込み
void CHumanBase::Load(const char FILEPATH[])
{
	iHndl = MV1LoadModel(FILEPATH);
}

//描画
void CHumanBase::Draw()
{
	if (IsActive)
	{
		MV1DrawModel(iHndl);
	}
	else
	{
		CDraw3D::DrawBox3D(cPos, cSize);
	}

}

//毎フレーム行う処理
void CHumanBase::Step(){}

//情報更新
void CHumanBase::UpData()
{
	MV1SetPosition(iHndl, cPos);		//座標の更新
	MV1SetScale(iHndl, cScale);			//サイズの更新
	MV1SetRotationXYZ(iHndl, cRotate);	//回転値の更新

	CAnim::UpdateAnim(iHndl);						//アニメーションの情報更新
}

//後処理
void CHumanBase::Exit()
{
	//変数の初期化
	cPos = VECTOR_ZERO;
	cNextPos = VECTOR_ZERO;
	cRotate = VECTOR_ZERO;
	cMoveRotate = VECTOR_ZERO;
	cScale = VECTOR_ZERO;
	cSize = VECTOR_ZERO;

	IsActive = false;

	MouseX = MouseY = 0;

	Life = -1;
	iHndl = -1;
	PushCnt = 0;
	ReturnCnt = 0;
}

//キャラクター回転処理
void CHumanBase::Player_Rotation()
{
	StoreRot = cRotate.y;


	if (CGamePad::GetPadNumState() != 0)
	{
		cRotate.y = CGamePad::StickRot(STICK_RIGHT);
	}
	else
	{
		cRotate.y = CMouse::MouseToRot();
	}

	if (cRotate.y == 0.0f)
	{
		cRotate.y = StoreRot;
	}

}

//方向フラグ設定
void CHumanBase::SetDir()
{
	if (cNextPos.x > cPos.x)
	{
		//右に動いている
		IsDir[DIR_RIGHT] = true;
	}
	else
	{
		IsDir[DIR_RIGHT] = false;
	}

	if (cNextPos.x < cPos.x)
	{
		//左に動いている
		IsDir[DIR_LEFT] = true;
	}
	else
	{
		IsDir[DIR_LEFT] = false;
	}

	if (cNextPos.y > cPos.y)
	{
		//上に動いている
		IsDir[DIR_UP] = true;
	}
	else
	{
		IsDir[DIR_UP] = false;
	}

	if (cNextPos.y < cPos.y)
	{
		//下に動いている
		IsDir[DIR_DOWN] = true;
	}
	else
	{
		IsDir[DIR_DOWN] = false;
	}

	if (cNextPos.z > cPos.z)
	{
		//奥に動いている
		IsDir[DIR_BACK] = true;
	}
	else
	{
		IsDir[DIR_BACK] = false;
	}

	if (cNextPos.z < cPos.z)
	{
		//手前に動いている
		IsDir[DIR_NEAR] = true;
	}
	else
	{
		IsDir[DIR_NEAR] = false;
	}
}

