#include "Check_Point.h"

const char POINT_PATH[] = { "data/Map/Point.x" };


//コンストラクタ
CCheck_Point::CCheck_Point()
{
	tmp_Hndl = -1;
}

//デストラクタ
CCheck_Point::~CCheck_Point()
{
	Exit();
}

//初期化
void CCheck_Point::Init()
{
	CBase_Check::Init();
	tmp_Hndl = -1;
	VECTOR vPos;
	vPos = VGet(GetRand(400.0f) - 200.0f, 5.0f, GetRand(600.0f) - 300.0f);
	Set_Point(vPos);
}

//モデル読み込み
void CCheck_Point::Load()
{
	if (tmp_Hndl == -1)
	{
		tmp_Hndl = MV1LoadModel(POINT_PATH);
	}

	//モデルのコピー
	iHndl = MV1DuplicateModel(tmp_Hndl);
}

//描画
void CCheck_Point::Draw()
{
	if (!IsActive)
		return;

	MV1DrawModel(iHndl);
}

//毎フレーム行う処理
void CCheck_Point::Step()
{
	if (!IsActive)
		return;

	CBase_Check::UpData();
}

//後処理
void CCheck_Point::Exit()
{
	if (iHndl != -1)
	{
		MV1DeleteModel(iHndl);
		iHndl = -1;
	}

	if (tmp_Hndl != -1)
	{
		MV1DeleteModel(tmp_Hndl);
		tmp_Hndl = -1;
	}
}

//設置処理
void CCheck_Point::Set_Point(VECTOR vPos)
{
	cPos = vPos;
	cSize = VGet(0.1f, 0.1f, 0.1f);
	IsActive = true;
}

