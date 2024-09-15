#include "TurretManager.h"



//コンストラクタ
CTurretManager::CTurretManager()
{
}

//デストラクタ
CTurretManager::~CTurretManager()
{
}


//初期化
void CTurretManager::Init()
{
	for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index] = new CTurret_Normal;
		cTurretBase[Turret_Index]->Init();
	}
}

//データロード
void CTurretManager::Load()
{
	for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Load();
	}
}

//終了処理
void CTurretManager::Exit()
{
	for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Exit();
	}
}

//繰り返し行う処理
void CTurretManager::Step(VECTOR Pos)
{
	for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Step();
	}

	Update();
}

//更新処理
void CTurretManager::Update()
{
	for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Update();
	}
}

//描画処理
void CTurretManager::Draw()
{
	for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Draw();
	}
}

//タレット設置処理
void CTurretManager::TurretSpawn(const VECTOR& vPos)
{
	for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->TurretSpawn(vPos);
	}
}