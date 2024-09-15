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
	/*for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Init();
	}*/

	//ベースクラスのポインタ配列へ代入
	CTurretBase* cTurretBase = new CTurret_Normal;
	cTurretBase->Init();
	//リストに追加
	Turret_List.push_back(cTurretBase);
}

//データロード
void CTurretManager::Load()
{
	/*for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Load();
	}*/

	for (auto itr = *Turret_List.begin(); itr != *Turret_List.end(); itr++)
	{
		itr->Load();
	}
}

//終了処理
void CTurretManager::Exit()
{
	/*for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Exit();
	}*/

	for (auto itr = *Turret_List.begin(); itr != *Turret_List.end(); itr++)
	{
		itr->Exit();
	}
}

//繰り返し行う処理
void CTurretManager::Step(VECTOR Pos)
{
	/*for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Step();
	}

	Update();*/

	for (auto itr = *Turret_List.begin(); itr != *Turret_List.end(); itr++)
	{
		itr->Step();
	}

	Update();
}

//更新処理
void CTurretManager::Update()
{
	/*for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Update();
	}*/

	for (auto itr = *Turret_List.begin(); itr != *Turret_List.end(); itr++)
	{
		itr->Update();
	}
}

//描画処理
void CTurretManager::Draw()
{
	/*for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Draw();
	}*/

	for (auto itr = *Turret_List.begin(); itr != *Turret_List.end(); itr++)
	{
		itr->Draw();
	}
}

//タレット設置処理
void CTurretManager::TurretSpawn(const VECTOR& vPos)
{
	/*for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->TurretSpawn(vPos);
	}*/

	//ベースクラスのポインタ配列へ代入
	CTurretBase* cTurretBase =  new CTurret_Normal;
	cTurretBase->Init();
	cTurretBase->TurretSpawn(vPos);
	//リストに追加
	Turret_List.push_back(cTurretBase);
	
	//削除しておく
	delete cTurretBase;

}