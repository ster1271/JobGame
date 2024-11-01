#include "Goal.h"

const char MODEL_PATH[] = "data/Map/door.x";

//コンストラクタ
CGoal::CGoal()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));

	IsActive = false;
}

//デストラクタ
CGoal::~CGoal()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));

	IsActive = false;
}

//初期化
void CGoal::Init()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	cPos = VGet(400.0f, 0.0f, 400.0f);
	cRotate = VGet(0.0f, 0.0f, 0.0f);
	cSize = VGet(0.2f, 0.2f, 0.2f);

	IsActive = true;
}

//読み込み関連
void CGoal::Load()
{
	iHndl = MV1LoadModel(MODEL_PATH);
}

//描画
void CGoal::Draw()
{
	if (!IsActive)
		return;

	MV1DrawModel(iHndl);
	CDraw3D::DrawBox3D(cPos, VGet(25.0f, 25.0f, 25.0f), GetColor(255, 255, 0));
}

//毎フレーム行う処理
void CGoal::Step()
{
	if (!IsActive)
		return;

}

//更新処理
void CGoal::Update()
{
	MV1SetPosition(iHndl, cPos);		//座標の更新
	MV1SetScale(iHndl, cSize);			//サイズの更新
	MV1SetRotationXYZ(iHndl, cRotate);	//回転値の更新
}

//後処理
void CGoal::Exit()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));

	IsActive = false;
}