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
	cPos = VGet(200.0f, 0.0f, 100.0f);
	cNextPos = cPos;
	cRotate = VECTOR_ZERO;
	cScale = VGet(0.05f, 0.05f, 0.05f);
	cSize = PLAYER_SIZE;

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
	GetJoypadDirectInputState(DX_INPUT_PAD1, &pad);

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
	float fSpd = 0.0f;
	if (CInput::IsKeyKeep(KEY_INPUT_W) || pad.Y < 0 && pad.Y >= -1000)
	{
		Id = STATE_RUN;
		fSpd = -MOVESPEED;
	}
	else if (CInput::IsKeyKeep(KEY_INPUT_S) || pad.Y > 0 && pad.Y <= 1000)
	{
		Id = STATE_RUN;
		fSpd = -MOVESPEED;
	}
	else if (CInput::IsKeyKeep(KEY_INPUT_W) || pad.X < 0 && pad.X >= -1000)
	{
		Id = STATE_RUN;
		fSpd = -MOVESPEED;
	}
	else if (CInput::IsKeyKeep(KEY_INPUT_S) || pad.X > 0 && pad.X <= 1000)
	{
		Id = STATE_RUN;
		fSpd = -MOVESPEED;
	}
	
	cRotate.y = atan2(pad.X, pad.Y * -1);
	
	//入力したキー情報とプレイヤーの角度から、移動速度を求める
	VECTOR vSpeed = VGet(0.0f, 0.0f, 0.0f);
	vSpeed.x = sin(cRotate.y) * fSpd;
	vSpeed.z = cos(cRotate.y) * fSpd;

	//移動速度を現在の座標に加算する
	cNextPos.x += vSpeed.x;
	cNextPos.z += vSpeed.z;



	//発射処理
	if (CInput::IsKeyPush(KEY_INPUT_SPACE) ||CGamePad::IsPush_LR(RIGHT))
	{
		Id = STATE_SHOT;
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

		// 画面に構造体の中身を描画
		
		int Color = GetColor(0, 0, 0);
		DrawFormatString(0, 0, Color, "X:%d Y:%d Z:%d",
			pad.X, pad.Y, pad.Z);
		DrawFormatString(0, 16, Color, "Rx:%d Ry:%d Rz:%d",
			pad.Rx, pad.Ry, pad.Rz);
		DrawFormatString(0, 32, Color, "Slider 0:%d 1:%d",
			pad.Slider[0], pad.Slider[1]);
		DrawFormatString(0, 48, Color, "POV 0:%d 1:%d 2:%d 3:%d",
			pad.POV[0], pad.POV[1],
			pad.POV[2], pad.POV[3]);
		DrawString(0, 64, "Button", Color);
		for (int i = 0; i < 32; i++)
		{
			DrawFormatString(64 + i % 8 * 64, 64 + i / 8 * 16, Color,
				"%2d:%d", i, pad.Buttons[i]);
		}

	}
}

//終了処理
void CPlayer::Exit()
{
	CHumanBase::Exit();
}

