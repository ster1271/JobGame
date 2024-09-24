#include "TurretManager.h"

static const char TURRET_NORMAL_PATH[] = { "data/Turret/Turret_Normal.x" };

//コンストラクタ
CTurretManager::CTurretManager()
{
	Org_Hndl = -1;
}

//デストラクタ
CTurretManager::~CTurretManager()
{
}


//初期化
void CTurretManager::Init()
{
}

//データロード
void CTurretManager::Load()
{
	//オリジナルハンドルにロード
	if (Org_Hndl == -1)
	{
		Org_Hndl = MV1LoadModel(TURRET_NORMAL_PATH);
	}
	for (int TurretIndex = 0; TurretIndex < Turret_List.size(); TurretIndex++)
	{
		Turret_List[TurretIndex]->Load(Org_Hndl);
	}
}

//終了処理
void CTurretManager::Exit()
{
	for (int TurretIndex = 0; TurretIndex < Turret_List.size(); TurretIndex++)
	{
		Turret_List[TurretIndex]->Exit();
	}
}

//繰り返し行う処理
void CTurretManager::Step(VECTOR Pos)
{
	for (int TurretIndex = 0; TurretIndex < Turret_List.size(); TurretIndex++)
	{
		Turret_List[TurretIndex]->Step(Pos);
	}

	Update();

}

//更新処理
void CTurretManager::Update()
{
	for (int TurretIndex = 0; TurretIndex < Turret_List.size(); TurretIndex++)
	{
		Turret_List[TurretIndex]->Update();
	}
}

//描画処理
void CTurretManager::Draw()
{
	for (int TurretIndex = 0; TurretIndex < Turret_List.size(); TurretIndex++)
	{
		Turret_List[TurretIndex]->Draw();
	}
}

//タレット設置処理
void CTurretManager::TurretSpawn(const VECTOR& vPos)
{
	//変数代入用クラス
	CTurretBase* cTurretBase =  new CTurret_Normal;
	cTurretBase->Init();
	cTurretBase->Load(Org_Hndl);
	cTurretBase->TurretSpawn(vPos);
	
	//リストに追加
	Turret_List.push_back(cTurretBase);

}
