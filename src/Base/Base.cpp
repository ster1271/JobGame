#include "Base.h"

//コンストラクタ
CBase::CBase()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&Life, 0, sizeof(float));
	
}

//デストラクタ
CBase::~CBase()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&Life, 0, sizeof(float));

}

//初期化
void CBase::Init()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&Life, 0, sizeof(float));

}

//読み込み関連
bool CBase::Load(const char FILEPATH[])
{
	//モデルの読み込み
	iHndl = MV1LoadModel(FILEPATH);

	/*読み込み成功 = true, 読み込み失敗 = false*/	
	if (iHndl != -1)
		return true;
	else
		return false;
}

//描画
void CBase::Draw()
{
	//モデルの描画
	MV1DrawModel(iHndl);
}

//更新処理
void CBase::Update()
{
	MV1SetPosition(iHndl, cPos);		//座標の更新
	MV1SetScale(iHndl, cSize);			//サイズの更新
	MV1SetRotationXYZ(iHndl, cRotate);	//回転値の更新
}

//後処理
void CBase::Exit()
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
	memset(&Life, 0, sizeof(float));
}

