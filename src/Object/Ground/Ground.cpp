#include "Ground.h"

//コンストラクタ
CGround::CGround()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
}

//デストラクタ
CGround::~CGround()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
}

//初期化
void CGround::Init()
{
	//ハンドルの初期化
	iHndl = -1;

	//各変数の初期化
	cPos = VGet(0.0f, -20.0f, 0.0f);
	cSize = VGet(1.0f, 1.0f, 1.0f);
	cRotate = VGet(0.0f, 0.0f, 0.0f);
}

//モデル読み込み
void CGround::Load()
{
	iHndl = MV1LoadModel("data/Map/Map01.x");

	//コリジョン情報を取得する
	MV1SetupCollInfo(iHndl);
}


void CGround::Draw()
{
	MV1DrawModel(iHndl);

	//ボックスのサイズ約1500
	CDraw3D::DrawBox3D(VGet(0.0f, 0.0f, 0.0f), VGet(1500.0f, 20.0f, 1500.0f));
}
