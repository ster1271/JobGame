#include "Check_Point.h"

const char POINT_PATH[] = { "data/Map/Point.x" };


//コンストラクタ
Check_Point::Check_Point()
{
}

//デストラクタ
v::~CRoute_Point()
{
}

//初期化
void CRoute_Point::Init()
{
	VECTOR vPos = VGet(GetRand(400.0f) - 200.0f, 5.0f, GetRand(600.0f) - 300.0f);
	Set_Point(vPos);
}

//モデル読み込み
void CRoute_Point::Load(int Hndl)
{
	iHndl = MV1DuplicateModel(Hndl);
}

//設置処理
void CRoute_Point::Set_Point(const VECTOR vPos)
{
	//すでに生成されている
	if (IsActive) return;

	cPos = vPos;
	cRotate = VGet(0.0, 0.0f, 0.0f);
	cSize = VGet(0.1f, 0.1f, 0.1f);

	IsActive = true;
}

