#include "Attacker.h"


const char ATTACKER_PATH[] = { "data/character/human.x" };

const float SPERE_R = 3.0f;
#define MOVESPEED	(1.0f)
#define ROT_SPEED	(0.05f)	

//コンストラクタ・デストラクタ
CAttacker::CAttacker()
{
}

CAttacker::~CAttacker()
{
}

//初期化
void CAttacker::Init()
{
	CBase::Init();
	cPos = VGet(0.0f, 0.0f, 0.0f);
	cSize = VGet(0.05f, 0.05f, 0.05f);
	cRotate = VGet(0.0f, 0.0f, 0.0f);

	Life = 100;


}

//データ読み込み
void CAttacker::Load()
{
	iHndl = MV1LoadModel(ATTACKER_PATH);
}

void CAttacker::Default()
{
	if (Id != STATE_DEFAULT)
	{
		ReqestLoop(STATE_DEFAULT, 0.8f);
		Id = STATE_DEFAULT;
	}
}

void CAttacker::Run()
{
	if (Id != STATE_RUN)
	{
		ReqestLoop(STATE_RUN, 0.7f);
		Id = STATE_RUN;
	}
}

void CAttacker::RunShot()
{

}


//毎フレーム行う処理
void CAttacker::Step(CShotManager& cShotManager, CTurretManager& cTurretManager)
{
	switch (AnimData.m_AnimID)
	{
	case STATE_DEFAULT:
		Default();
		break;

	case STATE_RUN:
		Run();
		break;

	case STATE_SHOT:
		RunShot();
		break;

	default:
		break;
	}

	//キャラクターの移動
	float fSpd = 0.0f;
	if (CInput::IsKeyKeep(KEY_INPUT_W))
	{
		Id = STATE_RUN;
		fSpd = -MOVESPEED;
	}
	else if (CInput::IsKeyKeep(KEY_INPUT_S))
	{
		Id = STATE_RUN;
		fSpd = MOVESPEED;
	}
	else
	{
		Id = STATE_DEFAULT;
	}

	//入力したキー情報とプレイヤーの角度から、移動速度を求める
	VECTOR vSpeed = VGet(0.0f, 0.0f, 0.0f);
	vSpeed.x = sin(cRotate.y) * fSpd;
	vSpeed.z = cos(cRotate.y) * fSpd;

	//移動速度を現在の座標に加算する
	cPos.x += vSpeed.x;
	cPos.z += vSpeed.z;

	if (CInput::IsKeyKeep(KEY_INPUT_A))
	{
		cRotate.y -= 0.05f;
	}
	if (CInput::IsKeyKeep(KEY_INPUT_D))
	{
		cRotate.y += 0.05f;
	}

	//発射処理
	if (CInput::IsKeyPush(KEY_INPUT_SPACE))
	{
		//弾の位置決定
		VECTOR BulletPos = cPos;

		//弾のスピード
		const float SHOT_SPEED = 5.0f;
		VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);

		vSpd.x = sinf(cRotate.y) * -SHOT_SPEED;
		vSpd.z = cosf(cRotate.y) * -SHOT_SPEED;
		vSpd.y = 0.0f;

		cShotManager.RequestPlayerShot(BulletPos, vSpd);
	}

	//タレット生成処理
	if (CInput::IsKeyPush(KEY_INPUT_P))
	{
		cTurretManager.TurretSpawn(cPos);
	}
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

	DrawFormatString(0, 100, GetColor(255, 0, 0), "アタッカーX座標:%f", cPos.x);
	DrawFormatString(0, 115, GetColor(255, 0, 0), "アタッカーY座標:%f", cPos.y);
	DrawFormatString(0, 130, GetColor(255, 0, 0), "アタッカーZ座標:%f", cPos.z);

	DrawFormatString(0, 0, GetColor(255, 0, 0), "アタッカーY軸:%f", cRotate.y);

}

//終了処理
void CAttacker::Exit()
{
	CBase::Exit();
}
