#include "Turret_Normal.h"

const float MAX_LIFE = 50.0f;
const float ATTACK = 5.0f;
const int MAX_COOL_TIME = 30;

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
	CoolTime = 0;
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

	if (IS_DEBUG)
	{
		DrawFormatString(0, 500, GetColor(255, 255, 0), "タレットX座標:%f", cPos.x);
		DrawFormatString(0, 515, GetColor(255, 255, 0), "タレットY座標:%f", cPos.y);
		DrawFormatString(0, 530, GetColor(255, 255, 0), "タレットZ座標:%f", cPos.z);
		DrawFormatString(0, 550, GetColor(255, 255, 0), "タレットY軸:%f", cRotate.y);
	}
}

//毎フレーム行う処理
void CTurret_Normal::Step(CShotManager& cShotManager, CEnemyManager& cEnemyManager)
{
	
	if (!IsActive)return;

	//角度計算
	float MIN_RANGE = 999.9f;
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		//このfor文でExitが呼ばれてたら敵が描画されない
		CEnemy_Normal cEnemy = cEnemyManager.GetEnemy(i);

		if (CCollision::IsHitCircle(cPos.x, cPos.z, 50.0f, cEnemy.GetPosition().x, cEnemy.GetPosition().z, 50.0f))
		{
			float Range = (cEnemy.GetPosition().x - cPos.x) * (cEnemy.GetPosition().x - cPos.x) + (cEnemy.GetPosition().z - cPos.z) * (cEnemy.GetPosition().z - cPos.z);
			Range = sqrt(Range);
			if (Range < MIN_RANGE)
			{
				MIN_RANGE = Range;
			}
			else
				continue;

			Turret_Rotate(cEnemy.GetPosition());

			//弾の位置決定
			VECTOR BulletPos = cPos;

			//弾のスピード
			const float SHOT_SPEED = 5.0f;
			VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);

			vSpd.x = sinf(cRotate.y) * -SHOT_SPEED;
			vSpd.z = cosf(cRotate.y) * -SHOT_SPEED;
			vSpd.y = 0.0f;

			CoolTime++;
			if (CoolTime > MAX_COOL_TIME)
			{
				//タレットの弾リクエスト
				cShotManager.RequestTurretShot(BulletPos, vSpd);
				CoolTime = 0;
			}
		}
	}
}

//後処理
void CTurret_Normal::Exit()
{
	CTurretBase::Exit();
	Attack = 0.0f;
	CoolTime = 0;
}

//タレット設置処理
void CTurret_Normal::TurretSpawn(const VECTOR &vPos)
{
	//すでに生成されている
	if (IsActive) return;

	cPos = vPos;
	cRotate = VGet(0.0, 0.0f, 0.0f);
	cSize = VGet(0.1f, 0.1f, 0.1f);

	ShotRenge = 0.0f;
	Hp = MAX_LIFE;
	Power_Up_Count = 0;
	Attack = ATTACK;
	CoolTime = 0;

	IsActive = true;
}


//タレット強化
void CTurret_Normal::Turret_Power_Up()
{

}