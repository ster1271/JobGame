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
	cTurret_Normal.Init();
}

//データロード
void CTurretManager::Load()
{
	cTurret_Normal.Load();
}

//終了処理
void CTurretManager::Exit()
{
	cTurret_Normal.Exit();
}

//繰り返し行う処理
void CTurretManager::Step(VECTOR Pos)
{

	cTurret_Normal.Step();

	//更新処理
	Update();
}

//更新処理
void CTurretManager::Update()
{
	cTurret_Normal.Update();
}

//描画処理
void CTurretManager::Draw()
{
	cTurret_Normal.Draw();
}

//タレット設置処理
void CTurretManager::TurretSpawn(const VECTOR& vPos)
{
	cTurret_Normal.TurretSpawn(vPos);
}