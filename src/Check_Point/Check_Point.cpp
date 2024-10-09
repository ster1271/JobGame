#include "Check_Point.h"

//コンストラクタ
CCheck_Point::CCheck_Point()
{
}

//デストラクタ
CCheck_Point::~CCheck_Point()
{
	Exit();
}

//初期化
void CCheck_Point::Init(FILE* fp)
{
	CCheck_Base::Init();
}

//モデル読み込み
void CCheck_Point::Load(int Hndl)
{
	//モデルのコピー
	iHndl = MV1DuplicateModel(Hndl);
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

}

//後処理
void CCheck_Point::Exit()
{
	CCheck_Base::Exit();
}

//設置処理
void CCheck_Point::Set_Point(const VECTOR vPos)
{
	cPos = vPos;
	cSize= VGet(0.1f, 0.1f, 0.1f);
	IsActive = true;
}


//ファイル読み込み
void CCheck_Point::LoadFile()
{

}

//ファイル書き込み
void CCheck_Point::WriteFile(const VECTOR vPos)
{
	
}





