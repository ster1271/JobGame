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
	StoreRot = 0.0f;
	ShotCoolCount = 0;
	PushCnt = 0;

	Life = PLAYER_MAX_LIFE;
}

//データ読み込み
void CPlayer::Load()
{
	iHndl = MV1LoadModel(ATTACKER_PATH);
}

//デフォルトモーション
void CPlayer::Default()
{
	ReqestLoop(STATE_DEFAULT, 0.8f);
}

//走りモーション
void CPlayer::Run()
{
	ReqestLoop(STATE_RUN, 0.7f);
}

//撃つモーション
void CPlayer::Shot()
{
	ReqestLoop(STATE_SHOT, 0.1f);
}

//毎フレーム行う処理
void CPlayer::Step(CShotManager& cShotManager, CTurretManager& cTurretManager, CMapManager& cMapManager, VECTOR BotPos)
{
	switch (Id)
	{
	case STATE_DEFAULT:
		Default();
		break;

	case STATE_RUN:
		Run();
		break;

	case STATE_SHOT:
		Shot();
		break;

	default:
		break;
	}

	cPos = cNextPos;
	//キャラクターの移動
	Move();

	//マウスポインタの座標取得
	GetMousePoint(&MouseX, &MouseY);
	
	//弾発射処理
	ShotCoolCount++;
	if (CMouse::IsMouseKeep(MOUSE_INPUT_LEFT) || CGamePad::IsKeep_LR(RIGHT))
	{
		Id = STATE_SHOT;						//アニメーションを変更する
		fSpd = -SHOTMOVESPEED;					//移動速度を変更する
		Player_Rotation();						//プレイヤーの角度変更(射撃中)

		if (ShotCoolCount < SHOT_COOL_TIME)		//クールタイム中なら処理しない
			return;

		PlayerShot(cShotManager);				//リクエスト処理
	}

	//タレット生成処理
	if (CInput::IsKeyPush(KEY_INPUT_E) || CGamePad::IsPadPush(DX_INPUT_PAD1, BUTTON_A))
	{
		cTurretManager.TurretSpawn(cPos);
	}

	//ウェーブ開始
	if (!CWave::GetInstance()->GetIsWave())
	{

		VECTOR GoalPos = cMapManager.GetGoal().GetPos();
		GoalPos.z -= 10.0f;
		if (CCollision::CheckHitBoxToBox(cPos, PLAYER_SIZE, GoalPos, GOAL_SIZE))
		{
			StartWave();
		}
	}

	//ボットの場所に移動
	BackBotPosition(BotPos);

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
		DrawFormatString(0, 0, GetColor(255, 0, 0), "アタッカーX座標:%f", cPos.x);
		DrawFormatString(0, 15, GetColor(255, 0, 0), "アタッカーY座標:%f", cPos.y);
		DrawFormatString(0, 30, GetColor(255, 0, 0), "アタッカーZ座標:%f", cPos.z);
		DrawFormatString(0, 45, GetColor(255, 0, 0), "プレイヤーY軸:%f", cRotate.y);
		DrawFormatString(0, 60, GetColor(255, 0, 0), "マウスX座標:%d", MouseX);
		DrawFormatString(0, 75, GetColor(255, 0, 0), "マウスY座標:%d", MouseY);
	}

	if (CGamePad::GetPadNumState() != 0)
	{
		CDebugString::GetInstance()->AddString(0, 285, "コントローラーで操作中");
		CDebugString::GetInstance()->AddString(0, 300, "左スティックで移動");
		CDebugString::GetInstance()->AddString(0, 315, "RTボタンで射撃");
		CDebugString::GetInstance()->AddString(0, 330, "右スティックで射撃中角度変更");
		CDebugString::GetInstance()->AddString(0, 345, "Aボタンでタレット設置");
		CDebugString::GetInstance()->AddString(0, 360, "Bボタン長押しでボットにワープ");
		CDebugString::GetInstance()->AddString(0, 375, "ゴールにLBボタン長押しでウェーブスタート");
		CDebugString::GetInstance()->AddFormatString(0, 390, "LBボタンを押した時間：%d", PushCnt);
		CDebugString::GetInstance()->AddString(0, 405, "Xボタンでマップ表示切り替え");
	}
	else
	{
		CDebugString::GetInstance()->AddString(0, 285, "キーボードで操作中");
		CDebugString::GetInstance()->AddString(0, 300, "WASDで移動");
		CDebugString::GetInstance()->AddString(0, 315, "マウス左クリックで射撃");
		CDebugString::GetInstance()->AddString(0, 330, "マウスポインタで射撃中角度変更");
		CDebugString::GetInstance()->AddString(0, 345, "Eキーでタレット設置");
		CDebugString::GetInstance()->AddString(0, 360, "Qキー長押しでボットにワープ");
		CDebugString::GetInstance()->AddString(0, 375, "ゴールに1キー長押しでウェーブスタート");
		CDebugString::GetInstance()->AddFormatString(0, 390, "1キーを押した時間：%d", PushCnt);
		CDebugString::GetInstance()->AddString(0, 405, "TABキーでマップ表示切り替え");
	}
	
	CDebugString::GetInstance()->Draw();
}

//終了処理
void CPlayer::Exit()
{
	CHumanBase::Exit();
}

//移動処理
void CPlayer::Move()
{
	VECTOR KeyBuf = VECTOR_ZERO;
	fSpd = 0.0f;

	if (CGamePad::Stick(STICK_LY_NEG) || CInput::IsKeyKeep(KEY_INPUT_W))
	{
		fSpd = -MOVESPEED;
		KeyBuf.z = -1000;
		Id = STATE_RUN;

		//射撃中は移動速度を遅くする
		if (CMouse::IsMouseKeep(MOUSE_INPUT_LEFT) || CGamePad::IsKeep_LR(RIGHT))
		{
			fSpd = -SHOTMOVESPEED;
		}
	}
	if (CGamePad::Stick(STICK_LY_POS) || CInput::IsKeyKeep(KEY_INPUT_S))
	{
		fSpd = -MOVESPEED;
		KeyBuf.z = 1000;
		Id = STATE_RUN;

		//射撃中は移動速度を遅くする
		if (CMouse::IsMouseKeep(MOUSE_INPUT_LEFT) || CGamePad::IsKeep_LR(RIGHT))
		{
			fSpd = -SHOTMOVESPEED;
		}
	}
	if (CGamePad::Stick(STICK_LX_NEG) || CInput::IsKeyKeep(KEY_INPUT_A))
	{
		fSpd = -MOVESPEED;
		KeyBuf.x = 1000;
		Id = STATE_RUN;

		//射撃中は移動速度を遅くする
		if (CMouse::IsMouseKeep(MOUSE_INPUT_LEFT) || CGamePad::IsKeep_LR(RIGHT))
		{
			fSpd = -SHOTMOVESPEED;
		}
	}
	if (CGamePad::Stick(STICK_LX_POS) || CInput::IsKeyKeep(KEY_INPUT_D))
	{
		fSpd = -MOVESPEED;
		KeyBuf.x = -1000;
		Id = STATE_RUN;

		//射撃中は移動速度を遅くする
		if (CMouse::IsMouseKeep(MOUSE_INPUT_LEFT) || CGamePad::IsKeep_LR(RIGHT))
		{
			fSpd = -SHOTMOVESPEED;
		}
	}
	
	//動いているかどうか
	if (fSpd == 0.0f)
	{
		Id = STATE_DEFAULT;
	}
	else
	{
		cRotate.y = cMoveRotate.y;
	}

	//キャラクターの移動角度計算
	cMoveRotate.y = (float)atan2((int)KeyBuf.x * -1, (int)KeyBuf.z * -1);

	if(CGamePad::GetPadNumState() != 0)
	{
		cMoveRotate.y = CGamePad::StickRot(STICK_LEFT);
	}

	//入力したキー情報とプレイヤーの角度から、移動速度を求める
	cSpeed.x = sin(cMoveRotate.y) * fSpd;
	cSpeed.z = cos(cMoveRotate.y) * fSpd;

	//移動速度を現在の座標に加算する
	cNextPos = VAdd(cPos, cSpeed);
}

//発射リクエスト処理
void CPlayer::PlayerShot(CShotManager& cShotManager)
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
	ShotCoolCount = 0;
}


//ウェーブ開始処理
void CPlayer::StartWave()
{
	if (CGamePad::IsPadKeep(DX_INPUT_PAD1, BUTTON_LB) || CInput::IsKeyKeep(KEY_INPUT_1))
	{
		PushCnt++;

		if (PushCnt > 50)
		{
			CWave::GetInstance()->WaveStateChange(STATE_WAVE_PREPAR);
			
			PushCnt = 0;
		}
	}
	else
	{
		PushCnt = 0;
	}
}


//ボットの位置に移動
void CPlayer::BackBotPosition(VECTOR vPos)
{
	if (CGamePad::IsPadKeep(DX_INPUT_PAD1, BUTTON_B) || CInput::IsKeyKeep(KEY_INPUT_Q))
	{
		ReturnCnt++;

		if (ReturnCnt > 50)
		{
			cPos = vPos;
			cNextPos = cPos;
			ReturnCnt = 0;
		}
	}
	else
	{
		ReturnCnt = 0;
	}
}
