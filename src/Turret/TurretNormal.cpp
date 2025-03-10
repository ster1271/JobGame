#include "Turret_Normal.h"
#include "../CollisionManager/Collision/Collision.h"

const float MAX_LIFE = 10.0f;		//最大体力
const float ATTACK = 5.0f;			//攻撃力
const int MAX_COOL_TIME = 30;		//弾の発射間隔
const float SET_RANGE = 175.0f;		//最大直線距離
const float MAX_LENGHT = 999.9f;	

//コンストラクタ
CTurret_Normal::CTurret_Normal()
{
	Attack = 0.0f;
	CoolTime = 0;
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
		DrawSphere3D(cPos, 5.0f, 16, GetColor(255, 255, 255), GetColor(255, 255, 255), false);
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
	//タレットが生成されていなかったら処理を行わない
	if (!IsActive)return;

	int Num = NULL;
	float Range = 0.0f;
	TotalMinLenge = MAX_LENGHT;

	//HPが0より大きいときに処理を行う
	if (Hp > 0.0f)
	{
		for (int Index = 0; Index < ENEMY_MAXNUM; Index++)
		{
			//このfor文でExitが呼ばれてたら敵が描画されない
			CEnemy_Normal& cEnemy = cEnemyManager.GetEnemy(Index);

			//敵のフラグがfalseなら以降の処理をしない
			if (!cEnemy.GetActive())
				continue;
	
			VECTOR Reng_Vec = VSub(cEnemy.GetPosition(), cPos);		//敵とタレットの距離を求める	
			Range = CMyLibrary::VecLong(Reng_Vec);

			if (Range <= TotalMinLenge)
			{
				TotalMinLenge = Range;
				Num = Index;
			}
		}

		//直線距離が設定値よりも大きかったら下の処理をしない
		if (TotalMinLenge >= SET_RANGE)
			return;

		Turret_Rotate(cEnemyManager.GetEnemy(Num).GetPosition());		//角度処理

		TurretShot(cShotManager);	//弾の発射リクエスト
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
	cPos.y -= 10.0f;
	cRotate = VECTOR_ZERO;
	cSize = VGet(0.1f, 0.1f, 0.1f);

	Hp = MAX_LIFE;
	Power_Up_Count = 0;
	Attack = ATTACK;
	CoolTime = 0;

	IsActive = true;
}

//弾発射処理
void CTurret_Normal::TurretShot(CShotManager& cShotManager)
{
	//弾の位置決定
	VECTOR BulletPos = cPos;

	//弾のスピード
	const float SHOT_SPEED = 5.0f;
	VECTOR vSpd = VECTOR_ZERO;

	vSpd.x = sinf(cRotate.y) * -SHOT_SPEED;
	vSpd.z = cosf(cRotate.y) * -SHOT_SPEED;
	vSpd.y = 0.0f;

	CoolTime++;
	if (CoolTime > MAX_COOL_TIME)
	{
		if (Dir > 1.0f)
			return;

		//タレットの弾リクエスト
		cShotManager.RequestTurretShot(BulletPos, vSpd);
		CoolTime = 0;
	}
}



//タレット強化
void CTurret_Normal::Turret_Power_Up()
{

}