#include "Turret_Normal.h"

const float MAX_LIFE = 50.0f;
const float ATTACK = 5.0f;

//コンストラクタ
CTurret_Normal::CTurret_Normal()
{
	Attack = 0.0f;
}

//デストラクタ
CTurret_Normal::~CTurret_Normal()
{
}

//初期化
void CTurret_Normal::Init()
{
	CTurretBase::Init();
	Attack = 0.0f;
}

//データロード
void CTurret_Normal::Load(int Hndl)
{
	//コピーモデルをロード
	iHndl = MV1DuplicateModel(Hndl);
}

//描画
void CTurret_Normal::Draw()
{
	if (IsActive)
	{
		MV1DrawModel(iHndl);
	}

	DrawFormatString(0, 500, GetColor(255, 255, 0), "タレットX座標:%f", cPos.x);
	DrawFormatString(0, 515, GetColor(255, 255, 0), "タレットY座標:%f", cPos.y);
	DrawFormatString(0, 530, GetColor(255, 255, 0), "タレットZ座標:%f", cPos.z);


	DrawFormatString(0, 550, GetColor(255, 255, 0), "タレットY軸:%f", cRotate.y);

}

//毎フレーム行う処理
void CTurret_Normal::Step(const VECTOR vPos, CShotManager& cShotManager)
{
	
	if (!IsActive)return;

	
	//角度計算
	Turret_Rotate(vPos);


	//弾の位置決定
	VECTOR BulletPos = cPos;

	//弾のスピード
	const float SHOT_SPEED = 5.0f;
	VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);

	vSpd.x = sinf(cRotate.y) * -SHOT_SPEED;
	vSpd.z = cosf(cRotate.y) * -SHOT_SPEED;
	vSpd.y = 0.0f;
	
	//タレットの弾リクエスト
	cShotManager.RequestTurretShot(BulletPos, vSpd);
}

//後処理
void CTurret_Normal::Exit()
{
	CTurretBase::Exit();
	Attack = 0.0f;
}

//タレット設置処理
void CTurret_Normal::TurretSpawn(const VECTOR &vPos)
{
	//すでに生成されている
	if (IsActive) return;

	cPos = vPos;
	cPos.y += 5.0f;
	cRotate = VGet(0.0, 0.0f, 0.0f);
	cSize = VGet(0.1f, 0.1f, 0.1f);

	ShotRenge = 0.0f;
	Hp = MAX_LIFE;
	Power_Up_Count = 0;
	Attack = ATTACK;

	IsActive = true;
}


//タレット強化
void CTurret_Normal::Turret_Power_Up()
{

}