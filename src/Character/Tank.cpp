#include "Tank.h"

const char TANK_PATH[] = { "" };

const float SPERE_R = 10.0f;
#define MOVESPEED	(0.3f)


//コンストラクタ・デストラクタ
CTank::CTank()
{
}

CTank::~CTank()
{
}

//初期化
void CTank::Init()
{
	CBase::Init();
	cPos = VGet(0.0f, 0.0f, 0.0f);
	cSize = VGet(1.0f, 1.0f, 1.0f);
	cRotate = VGet(0.0f, DX_PI_F, 0.0f);
}

//データ読み込み
void CTank::Load()
{
	iHndl = MV1LoadModel(TANK_PATH);
}

//毎フレーム行う処理
void CTank::Step(CShotManager& cShotManager, CTurretManager& cTurretManager)
{
	//キャラクターの移動
	float fSpd = 0.0f;
	if (CInput::IsKeyKeep(KEY_INPUT_W))
	{
		fSpd = -MOVESPEED;
	}
	else if (CInput::IsKeyKeep(KEY_INPUT_S))
	{
		fSpd = MOVESPEED;
	}

	//入力したキー情報とプレイヤーの角度から、移動速度を求める
	VECTOR vSpeed = VGet(0.0f, 0.0f, 0.0f);
	vSpeed.x = sin(cRotate.y) * fSpd;
	vSpeed.z = cos(cRotate.y) * fSpd;

	//移動速度を現在の座標に加算する
	cPos.x += vSpeed.x;
	cPos.z += vSpeed.z;

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

	//タレット生成処理
	if (CInput::IsKeyPush(KEY_INPUT_P))
	{
		cTurretManager.TurretSpawn(cPos);
	}
}

//描画
void CTank::Draw()
{
	//条件式がtrueならモデルをfalseなら球を表示
	if (iHndl != -1)
	{
		MV1DrawModel(iHndl);
	}
	else
	{
		DrawSphere3D(cPos, SPERE_R, 32, GetColor(0, 255, 0), GetColor(0, 255, 0), TRUE);
	}

	DrawFormatString(0, 100, GetColor(255, 255, 255), "タンクX座標:%f", cPos.x);
	DrawFormatString(0, 115, GetColor(255, 255, 255), "タンクY座標:%f", cPos.y);
	DrawFormatString(0, 130, GetColor(255, 255, 255), "タンクZ座標:%f", cPos.z);

}

//終了処理
void CTank::Exit()
{
	CBase::Exit();
}
