#include "Support.h"


const char SUPPORT_PATH[] = { "" };

const float SPERE_R = 10.0f;
#define MOVESPEED	(0.3f)


//コンストラクタ・デストラクタ
CSupport::CSupport()
{
}

CSupport::~CSupport()
{
}

//初期化
void CSupport::Init()
{
	CBase::Init();
	cPos = VGet(0.0f, 0.0f, 0.0f);
	cSize = VGet(1.0f, 1.0f, 1.0f);
	cRotate = VGet(0.0f, DX_PI_F, 0.0f);
}

//データ読み込み
void CSupport::Load()
{
	iHndl = MV1LoadModel(SUPPORT_PATH);
}

//毎フレーム行う処理
void CSupport::Step(CShotManager& cShotManager, CTurretManager& cTurretManager)
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
void CSupport::Draw()
{
	//条件式がtrueならモデルをfalseなら球を表示
	if (iHndl != -1)
	{
		MV1DrawModel(iHndl);
	}
	else
	{
		DrawSphere3D(cPos, SPERE_R, 32, GetColor(0, 0, 255), GetColor(0, 0, 255), TRUE);
	}

	DrawFormatString(0, 100, GetColor(255, 255, 255), "サポートX座標:%f", cPos.x);
	DrawFormatString(0, 115, GetColor(255, 255, 255), "サポートY座標:%f", cPos.y);
	DrawFormatString(0, 130, GetColor(255, 255, 255), "サポートZ座標:%f", cPos.z);

}

//終了処理
void CSupport::Exit()
{
	CBase::Exit();
}
