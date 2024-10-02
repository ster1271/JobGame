#include "Object.h"

//コンストラクタ
CObject::CObject()
{
	//ハンドルの初期化
	Org_Hndl = -1;
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));

	IsActive = false;
}

//デストラクタ
CObject::~CObject()
{
	//ハンドルの初期化
	Org_Hndl = -1;
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));

	IsActive = false;
}

//初期化
void CObject::Init()
{
	//ハンドルの初期化
	Org_Hndl = -1;
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));

	IsActive = false;
}

//読み込み関連
void CObject::Load(int Org_Hndl)
{
	//モデルの読み込み
	iHndl = MV1DuplicateModel(Org_Hndl);
}

//描画
void CObject::Draw()
{
	//モデルの描画
	MV1DrawModel(iHndl);
}

//毎フレーム行う処理
void CObject::Step() {};

//更新処理
void CObject::Update()
{
	MV1SetPosition(iHndl, cPos);		//座標の更新
	MV1SetScale(iHndl, cSize);			//サイズの更新
	MV1SetRotationXYZ(iHndl, cRotate);	//回転値の更新
}

//後処理
void CObject::Exit()
{
	//ハンドルの削除
	if (iHndl != -1)
	{
		MV1DeleteModel(iHndl);
		iHndl = -1;
	}

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
}

//設置処理
void CObject::Set_Point(const VECTOR& vPos) {};
