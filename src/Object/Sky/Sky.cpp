#include "Sky.h"
#include <math.h>

//コンストラクタ
CSky::CSky()
{
}

//デストラクタ
CSky::~CSky()
{
}

//初期化
void CSky::Init()
{
	cPos = VGet(0.0f, 0.0f, 0.0f);
	cSize = VGet(2.0f, 2.0f, 2.0f);
	cRotate = VGet(0.0f, 0.0f, 0.0f);
}


//モデル読み込み
void CSky::Load()
{
	iHndl = MV1LoadModel("data/Sky/Sky.x");
}


//通常処理
void CSky::Step()
{
	cRotate.y += 0.0005f;

	/*
	VECTOR vDir;
	vDir.x = sinf(fRot) * 30.0f;
	vDir.z = cosf(fRot) * 30.0f;

	//視点の高さは固定
	vDir.y = 10.0f;

	SetSkyPos(vForcus, vDir);
	*/
}

//移動処理
void CSky::SetSkyPos(VECTOR vF, VECTOR dir)
{
	cPos = VAdd(vF, dir);
}