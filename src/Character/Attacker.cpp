#include "Attacker.h"


const char ATTACKER_PATH[] = { "data/character/il/あいえるたん.pmx" };

const float SPERE_R = 3.0f;
#define MOVESPEED	(0.3f)
#define ROT_SPEED	(0.05f)	

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
	cRotate = VGet(0.0f, 0.0f, 0.0f);
}

//データ読み込み
void CAttacker::Load()
{
	iHndl = MV1LoadModel(ATTACKER_PATH);
}

//毎フレーム行う処理
void CAttacker::Step(CShotManager& cShotManager)
{
	if (CInput::IsKeyKeep(KEY_INPUT_W))
	{
		cPos.z -= MOVESPEED;
	}
	if (CInput::IsKeyKeep(KEY_INPUT_S))
	{
		cPos.z += MOVESPEED;
	}
	if (CInput::IsKeyKeep(KEY_INPUT_A))
	{
		cPos.x += MOVESPEED;
	}
	if (CInput::IsKeyKeep(KEY_INPUT_D))
	{
		cPos.x -= MOVESPEED;
	}

	//発射処理
	if (CInput::IsKeyPush(KEY_INPUT_SPACE))
	{
		//弾の位置決定
		VECTOR BulletPos = cPos;

		//弾のスピード
		const float SHOT_SPEED = 5.0f;
		VECTOR vSpd;

		vSpd.x = sinf(cPos.y) * -SHOT_SPEED;
		vSpd.z = cosf(cRotate.y) * -SHOT_SPEED;
		vSpd.y = 0.0f;

		cShotManager.RequestPlayerShot(BulletPos, vSpd);
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
	//条件式がtrueならモデルをfalseなら球を表示
	if (iHndl != -1)
	{
		MV1DrawModel(iHndl);
	}
	else
	{
		DrawSphere3D(cPos, SPERE_R, 32, GetColor(255, 0, 0), GetColor(255, 0, 0), TRUE);
	}

	DrawFormatString(0, 100, GetColor(255, 255, 255), "アタッカーX座標:%f", cPos.x);
	DrawFormatString(0, 115, GetColor(255, 255, 255), "アタッカーY座標:%f", cPos.y);
	DrawFormatString(0, 130, GetColor(255, 255, 255), "アタッカーZ座標:%f", cPos.z);

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
