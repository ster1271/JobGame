#include "Player.h"
#include "../Debug/DebugString.h"

const char ATTACKER_PATH[] = { "data/character/human.x" };

//コンストラクタ・デストラクタ
CPlayer::CPlayer()
{
	IsDir[DIR_NUM] = { false };
	memset(&Id, 0, sizeof(PLAYER_STATE));
}

CPlayer::~CPlayer()
{
}

//初期化
void CPlayer::Init()
{
	cPos = PLAYER_POS;
	cNextPos = cPos;
	cRotate = VECTOR_ZERO;
	cMoveRotate = VECTOR_ZERO;
	cScale = PLAYER_SCALE;
	cSize = PLAYER_SIZE;
	fSpd = 0.0f;
	ShotCoolCount = 0;

	Life = 100;
}

//データ読み込み
void CPlayer::Load()
{
	iHndl = MV1LoadModel(ATTACKER_PATH);
}

void CPlayer::Default()
{
	ReqestLoop(STATE_DEFAULT, 0.8f);
}

void CPlayer::Run()
{
	ReqestLoop(STATE_RUN, 0.7f);
}

void CPlayer::RunShot()
{
	ReqestLoop(STATE_SHOT, 0.1f);
}

//毎フレーム行う処理
void CPlayer::Step(CShotManager& cShotManager, CTurretManager& cTurretManager)
{
	fSpd = 0.0f;

	switch (Id)
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

	cPos = cNextPos;
	
	//キャラクターの移動
	Move_CON();
	
	//キャラクターの移動角度計算
	cMoveRotate.y = CGamePad::StickRot(STICK_LEFT);
	if (CGamePad::Stick(STICK_RX_POS))
	{
		cRotate.y -= 0.03f;
	}
	else if (CGamePad::Stick(STICK_RX_NEG))
	{
		cRotate.y += 0.03f;
	}
	
	//入力したキー情報とプレイヤーの角度から、移動速度を求める
	VECTOR vSpeed = VGet(0.0f, 0.0f, 0.0f);
	vSpeed.x = sin(cMoveRotate.y) * fSpd;
	vSpeed.z = cos(cMoveRotate.y) * fSpd;

	//移動速度を現在の座標に加算する
	cNextPos.x += vSpeed.x;
	cNextPos.z += vSpeed.z;



	//発射処理
	ShotCoolCount++;
	if (CInput::IsKeyKeep(KEY_INPUT_SPACE) ||CGamePad::IsKeep_LR(RIGHT))
	{
		Id = STATE_SHOT;

		if (ShotCoolCount < SHOT_COOL_TIME)
			return;

		//弾の位置決定
		VECTOR BulletPos = cPos;

		//弾のスピード
		const float SHOT_SPEED = 5.0f;
		VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);

		vSpd.x = sinf(cRotate.y) * -SHOT_SPEED;
		vSpd.z = cosf(cRotate.y) * -SHOT_SPEED;
		vSpd.y = 0.0f;

		cShotManager.RequestPlayerShot(BulletPos, vSpd);
		ShotCoolCount = 0;
	}

	//タレット生成処理
	if (CInput::IsKeyPush(KEY_INPUT_P) || CGamePad::IsPadPush(DX_INPUT_PAD1, BUTTON_A))
	{
		cTurretManager.TurretSpawn(cPos);
	}


	//方向のチェック
	SetDir();

	//過去のアニメーションIDに現在アニメーションを代入
	oldId = Id;
}

//描画
void CPlayer::Draw()
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

	if (IS_DEBUG)
	{
		DrawFormatString(0, 100, GetColor(255, 0, 0), "アタッカーX座標:%f", cPos.x);
		DrawFormatString(0, 115, GetColor(255, 0, 0), "アタッカーY座標:%f", cPos.y);
		DrawFormatString(0, 130, GetColor(255, 0, 0), "アタッカーZ座標:%f", cPos.z);
		CDebugString::GetInstance()->AddFormatString(300, 300, "プレイヤーY軸：%f", cRotate.y);
		CDebugString::GetInstance()->Draw();
	}
}

//終了処理
void CPlayer::Exit()
{
	CHumanBase::Exit();
}



//コントローラー処理
void CPlayer::Move_CON()
{
	if (CGamePad::Stick(STICK_LY_NEG))
	{
		//射撃中に移動
		if (CGamePad::IsKeep_LR(RIGHT))
		{
			Id = STATE_SHOT;
			fSpd = -0.5f;
		}
		else
		{
			Id = STATE_RUN;
			fSpd = -MOVESPEED;
			cRotate.y = cMoveRotate.y;
		}
	}
	else if (CGamePad::Stick(STICK_LY_POS))
	{
		//射撃中に移動
		if (CGamePad::IsKeep_LR(RIGHT))
		{
			Id = STATE_SHOT;
			fSpd = -0.5f;
		}
		else
		{
			Id = STATE_RUN;
			fSpd = -MOVESPEED;
			cRotate.y = cMoveRotate.y;
		}
	}
	else if (CGamePad::Stick(STICK_LX_NEG))
	{
		//射撃中に移動
		if (CGamePad::IsKeep_LR(RIGHT))
		{
			Id = STATE_SHOT;
			fSpd = -0.5f;
		}
		else
		{
			Id = STATE_RUN;
			fSpd = -MOVESPEED;
			cRotate.y = cMoveRotate.y;
		}
	}
	else if (CGamePad::Stick(STICK_LX_POS))
	{
		//射撃中に移動
		if (CGamePad::IsKeep_LR(RIGHT))
		{
			Id = STATE_SHOT;
			fSpd = -0.5f;
		}
		else
		{
			Id = STATE_RUN;
			fSpd = -MOVESPEED;
			cRotate.y = cMoveRotate.y;
		}
	}
	else
	{
		Id = STATE_DEFAULT;
	}
	
}

