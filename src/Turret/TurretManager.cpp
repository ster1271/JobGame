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
	//ベースクラスのポインタ配列へ代入
	CTurretBase* cTurretBase = new CTurret_Normal;
	cTurretBase->Init();
	//リストに追加
	Turret_List.push_back(cTurretBase);
}

//データロード
void CTurretManager::Load()
{
	for (auto itr = Turret_List.begin(); itr != Turret_List.end(); itr++)
	{
		(*itr)->Load();
	}
}

//終了処理
void CTurretManager::Exit()
{
	for (auto itr = Turret_List.begin(); itr != Turret_List.end(); itr++)
	{
		(*itr)->Exit();
	}
}

//繰り返し行う処理
void CTurretManager::Step(VECTOR Pos)
{
	for (auto itr = Turret_List.begin(); itr != Turret_List.end(); itr++)
	{
		(*itr)->Step();
	}

	Update();
}

//更新処理
void CTurretManager::Update()
{
	for (auto itr = Turret_List.begin(); itr != Turret_List.end(); itr++)
	{
		(*itr)->Update();
	}
}

//描画処理
void CTurretManager::Draw()
{
	for (auto itr = Turret_List.begin(); itr != Turret_List.end(); itr++)
	{
		(*itr)->Draw();
	}
}

//タレット設置処理
void CTurretManager::TurretSpawn(const VECTOR& vPos)
{
	//変数代入用クラス
	CTurretBase* cTurretBase =  new CTurret_Normal;
	cTurretBase->Init();
	cTurretBase->Load();
	cTurretBase->TurretSpawn(vPos);
	//リストに追加
	Turret_List.push_back(cTurretBase);

}