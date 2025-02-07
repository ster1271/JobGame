#include "EnemyBoss.h"

const int MAX_LIFE = 5;		//最大体力


//コンストラクタ
CEnemyBoss::CEnemyBoss()
{
	memset(&Respown_Pos, 0, sizeof(VECTOR));
}

//デストラクタ
CEnemyBoss::~CEnemyBoss()
{
}

//初期化
void CEnemyBoss::Init()
{
	CEnemyBase::Init();
}

//データロード
void CEnemyBoss::Load(int Hndl)
{
	iHndl = MV1DuplicateModel(Hndl);
}

//描画
void CEnemyBoss::Draw()
{
	if (IsActive == false)
		return;

	MV1DrawModel(iHndl);
}

//毎フレーム行う処理
void CEnemyBoss::Step(VECTOR vPos, CMapManager& cMapManager)
{
	if (!IsActive)
	{
		return;
	}

	cPos = cNextPos;
	//座標に速度を加算
	cNextPos = VSub(cPos, cSpeed);
	//一定範囲を超えたら消す
	float fLength = 100.0f;
	if (cPos.x > Respown_Pos.x + fLength || cPos.x < Respown_Pos.x - fLength
		|| cPos.z > Respown_Pos.z + fLength || cPos.z < Respown_Pos.z - fLength)
	{
		IsActive = false;
	}

	//方向設定
	SetDir();

	//更新処理
	Update();
}

//後処理
void CEnemyBoss::Exit()
{
	CEnemyBase::Exit();
	memset(&Respown_Pos, 0, sizeof(VECTOR));
}

//リクエスト
bool CEnemyBoss::RequestEnemy(const VECTOR& vPos, const VECTOR& vSpeed)
{
	//すでに出現している
	if (IsActive)
		return false;

	cPos = vPos;
	Respown_Pos = vPos;
	cScale = VGet(0.1f, 0.1f, 0.1f);
	cSize = ENEMY_BOSS_SIZE;
	cRotate = VGet(0.0f, DX_PI_F / 2, 0.0f);
	cSpeed = vSpeed;
	Life = MAX_LIFE;
	IsActive = true;

	return true;
}