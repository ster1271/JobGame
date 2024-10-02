#include "Route_Point.h"

const char POINT_PATH[] = { "data/Map/Point.x" };


//コンストラクタ
CRoute_Point::CRoute_Point()
{
}

//デストラクタ
CRoute_Point::~CRoute_Point()
{
}

//初期化
void CRoute_Point::Init()
{

}

//モデル読み込み
void CRoute_Point::Load()
{
	if (Org_Hndl == -1)
	{
		Org_Hndl = MV1LoadModel(POINT_PATH);
	}
	iHndl = MV1DuplicateModel(Org_Hndl);
}

//設置処理
void CRoute_Point::Set_Point(const VECTOR& vPos)
{
	//すでに生成されている
	if (IsActive) return;

	cPos = vPos;
	cRotate = VGet(0.0, 0.0f, 0.0f);
	cSize = VGet(1.0f, 1.0f, 1.0f);

	IsActive = true;
}

