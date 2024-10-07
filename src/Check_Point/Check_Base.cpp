#include "Check_Base.h"

//コンストラクタ
CCheck_Base::CCheck_Base()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));

	iHndl = -1;
	IsActive = false;
}

//デストラクタ
CCheck_Base:: ~CCheck_Base() {};

//初期化
void CCheck_Base::Init()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));

	iHndl = -1;
	IsActive = false;
}

//データ読み込み
void CCheck_Base::Load(int Hndl)
{
	//コピーモデルの読み込み
	iHndl = MV1DuplicateModel(Hndl);
}

//後処理
void CCheck_Base::Exit()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));

	iHndl = -1;
	IsActive = false;
}

//情報更新
void CCheck_Base::Updata()
{
	MV1SetPosition(iHndl, cPos);		//座標の更新
	MV1SetScale(iHndl, cSize);			//サイズの更新
	MV1SetRotationXYZ(iHndl, cRotate);	//回転値の更新
}

//描画
void CCheck_Base::Draw() {};

//毎フレーム行う処理
void CCheck_Base::Step() {};