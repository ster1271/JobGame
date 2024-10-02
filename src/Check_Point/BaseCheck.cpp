#include "BaseCheck.h"

//コンストラクタ・デストラクタ
CBase_Check::CBase_Check()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));

	iHndl = -1;

	IsActive = false;
}

CBase_Check::~CBase_Check()
{
	Exit();
}

//初期化
void CBase_Check::Init()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));

	iHndl = -1;

	IsActive = false;
}

//読み込み
void CBase_Check::Load()
{
}

//情報更新
void CBase_Check::UpData()
{
	MV1SetPosition(iHndl, cPos);		//座標の更新
	MV1SetScale(iHndl, cSize);			//サイズの更新
	MV1SetRotationXYZ(iHndl, cRotate);	//回転値の更新
}

//後処理
void CBase_Check::Exit()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));

	iHndl = -1;

	IsActive = false;
}