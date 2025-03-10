#include "Player.h"

//インスタンスの初期化
CPlayer* CPlayer::cInstance = nullptr;

const char ATTACKER_PATH[] = { "data/character/human.x" };


//コンストラクタ
CPlayer::CPlayer()
{
	for (int Index = 0; Index < DIR_NUM; Index++)
	{
		IsDir[Index] = false;
	}
	memset(&Id, 0, sizeof(PLAYER_STATE));
	memset(&oldId, 0, sizeof(PLAYER_STATE));

	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cNextPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cMoveRotate, 0, sizeof(VECTOR));
	memset(&cScale, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));

	fSpd = 0.0f;
	StoreRot = 0.0f;
	ShotCoolCount = 0;
	PushCnt = 0;

	Life = 0;
	IsActive = false;
}

//デストラクタ
CPlayer::~CPlayer(){}

//インスタンスの生成
void CPlayer::Create()
{
	//インスタンスにが生成されていなかったら
	if (cInstance == nullptr)
	{
		//新しくnewする
		cInstance = new CPlayer();
	}
}


//インスタンスの削除
void CPlayer::Destroy()
{
	//インスタンスが生成されていたら
	if (cInstance != nullptr)
	{
		//deleteしてnullptrを入れる
		delete cInstance;
		cInstance = nullptr;
	}
}


//インスタンスの取得
CPlayer* CPlayer::GetInstance()
{
	if (cInstance == nullptr)
	{
		//インスタンスが生成されていなかったら生成する
		Create();
		return cInstance;
	}
	else
	{
		return cInstance;
	}
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
	IsActive = false;
}

//データ読み込み
void CPlayer::Load()
{
	iHndl = MV1LoadModel(ATTACKER_PATH);
	IsActive = true;
	MV1SetPosition(iHndl, cPos);		//座標の更新
	MV1SetScale(iHndl, cScale);			//サイズの更新
	MV1SetRotationXYZ(iHndl, cRotate);	//回転値の更新
}

//デフォルトモーション
void CPlayer::Default()
{
	CAnim::ReqestLoop(iHndl, STATE_DEFAULT, 0.8f);
}

//走りモーション
void CPlayer::Run()
{
	CAnim::ReqestLoop(iHndl, STATE_RUN, 0.7f);
}

//撃つモーション
void CPlayer::Shot()
{
	CAnim::ReqestLoop(iHndl, STATE_SHOT, 0.1f);
}

//毎フレーム行う処理
void CPlayer::Step(CShotManager& cShotManager, CTurretManager& cTurretManager, CMapManager& cMapManager, VECTOR BotPos)
{
	SetPlace();

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

	if (CInput::IsKeyPush(KEY_INPUT_R))
	{
		Life -= 2;
	}
	
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
			if (CWave::GetInstance()->GetWaveState() == STATE_WAVE_PREPAR)
				return;

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
	if (!IsActive)
		return;

	//プレイヤーの描画
	MV1DrawModel(iHndl);


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
		CDebugString::GetInstance()->AddString(0, 0, "コントローラーで操作中");
		CDebugString::GetInstance()->AddString(0, 15, "左スティックで移動");
		CDebugString::GetInstance()->AddString(0, 30, "RTボタンで射撃");
		CDebugString::GetInstance()->AddString(0, 45, "右スティックで射撃中角度変更");
		CDebugString::GetInstance()->AddString(0, 60, "Aボタンでタレット設置");
		CDebugString::GetInstance()->AddString(0, 75, "Bボタン長押しでボットにワープ");
		CDebugString::GetInstance()->AddString(0, 90, "ゴールにLBボタン長押しでウェーブスタート");
		CDebugString::GetInstance()->AddFormatString(0, 105, "LBボタンを押した時間：%d", PushCnt);
		CDebugString::GetInstance()->AddString(0, 120, "Xボタンでマップ表示切り替え");

		CDebugString::GetInstance()->AddFormatString(0, 150, "アタッカーX座標:%d", (int)cPos.x);
		CDebugString::GetInstance()->AddFormatString(0, 165, "アタッカーY座標:%d", (int)cPos.y);
		CDebugString::GetInstance()->AddFormatString(0, 180, "アタッカーZ座標:%d", (int)cPos.z);
	}
	else
	{
		CDebugString::GetInstance()->AddString(0, 0, "キーボードで操作中");
		CDebugString::GetInstance()->AddString(0, 15, "WASDで移動");
		CDebugString::GetInstance()->AddString(0, 30, "マウス左クリックで射撃");
		CDebugString::GetInstance()->AddString(0, 45, "マウスポインタで射撃中角度変更");
		CDebugString::GetInstance()->AddString(0, 60, "Eキーでタレット設置");
		CDebugString::GetInstance()->AddString(0, 75, "Qキー長押しでボットにワープ");
		CDebugString::GetInstance()->AddString(0, 90, "ゴールに1キー長押しでウェーブスタート");
		CDebugString::GetInstance()->AddFormatString(0, 105, "1キーを押した時間：%d", PushCnt);
		CDebugString::GetInstance()->AddString(0, 120, "TABキーでマップ表示切り替え");

		CDebugString::GetInstance()->AddFormatString(0, 150, "アタッカーX座標:%d", (int)cPos.x);
		CDebugString::GetInstance()->AddFormatString(0, 165, "アタッカーX座標:%d", (int)cPos.y);
		CDebugString::GetInstance()->AddFormatString(0, 180, "アタッカーX座標:%d", (int)cPos.z);
	}
}

//終了処理
void CPlayer::Exit()
{
	CHumanBase::Exit();
	LIST.clear();
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
	cSpeed.y = 0.0f;

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
			//状態を変える
			CWave::GetInstance()->WaveStateChange(STATE_WAVE_PREPAR);
			//ボット移動ウェーブフラグを変更
			CWave::GetInstance()->SetIsBotMove(true);
			CWave::GetInstance()->SetWaveTime(0);
			
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


//タレット設置場所指定
void CPlayer::SetPlace()
{
	VECTOR vPos = VECTOR_ZERO;

	//data/Turret/TurretPlace.txt	//タレット用(Y座標：-13)
	//data/enemy/Enemy_Pass01.txt	//敵の移動用

	const char TMP[] = { "aaa" };

	//ファイルを開く
	fopen_s(&fp, TMP, "a+");

	if (CInput::IsKeyPush(KEY_INPUT_RETURN))
	{
		if (fp != nullptr)
		{
			//プレイヤーの現在座標を渡す
			vPos = cPos;
			LIST.push_back(vPos);

			fprintf(fp, "%d, %d, %d\n", (int)vPos.x, vPos.y, (int)vPos.z);
		}
	}

	//ファイルを閉じる
	fclose(fp);
}
