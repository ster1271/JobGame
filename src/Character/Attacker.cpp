#include "Attacker.h"

const char ATTACKER_PATH[] = { "data/character/il/あいえるたん.pmx" };

#define MOVESPEED	(0.3f)

//コンストラクタ・デストラクタ
CAttacker::CAttacker()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
}

CAttacker::~CAttacker()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
}

//初期化
void CAttacker::Init()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	cPos = VGet(0.0f, 0.0f, 0.0f);
	cSize = VGet(1.0f, 1.0f, 1.0f);
	cRotate = VGet(0.0f, DX_PI_F, 0.0f);

}

//データ読み込み
void CAttacker::Load()
{
	iHndl = MV1LoadModel(ATTACKER_PATH);
}

//毎フレーム行う処理
void CAttacker::Step()
{
	if (CInput::IsKeyKeep(KEY_INPUT_W))
	{
		cPos.z += MOVESPEED;
	}
	if (CInput::IsKeyKeep(KEY_INPUT_S))
	{
		cPos.z -= MOVESPEED;
	}
	if (CInput::IsKeyKeep(KEY_INPUT_A))
	{
		cPos.x -= MOVESPEED;
	}
	if (CInput::IsKeyKeep(KEY_INPUT_D))
	{
		cPos.x += MOVESPEED;
	}

}

//更新処理
void CAttacker::Update()
{
	MV1SetPosition(iHndl, cPos);		//座標の更新
	MV1SetScale(iHndl, cSize);			//サイズの更新
	MV1SetRotationXYZ(iHndl, cRotate);	//回転値の更新
}

//描画
void CAttacker::Draw()
{
	MV1DrawModel(iHndl);

	DrawFormatString(0, 100, GetColor(255, 255, 255), "プレイヤーX座標:%f", cPos.x);
	DrawFormatString(0, 115, GetColor(255, 255, 255), "プレイヤーY座標:%f", cPos.y);
	DrawFormatString(0, 130, GetColor(255, 255, 255), "プレイヤーZ座標:%f", cPos.z);

}

//終了処理
void CAttacker::Exit()
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