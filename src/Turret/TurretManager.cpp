#include "TurretManager.h"
#include "../Debug/DebugString.h"

static const char TURRET_NORMAL_PATH[] = { "data/Turret/Turret_Normal.x" };

//コンストラクタ
CTurretManager::CTurretManager()
{
	TurretN_Hndl = -1;
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
	if (TurretN_Hndl == -1)
	{
		TurretN_Hndl = MV1LoadModel(TURRET_NORMAL_PATH);
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
void CTurretManager::Step(CShotManager& cShotManager, CEnemyManager& cEnemyManager)
{
	for (int TurretIndex = 0; TurretIndex < Turret_List.size(); TurretIndex++)
	{
		Turret_List[TurretIndex]->Step(cShotManager, cEnemyManager);
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


	CDebugString::GetInstance()->AddFormatString(500, 500, "リストの個数：%d", Turret_List.size());

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
	VECTOR vSize = VGet(30.0f, 30.0f, 30.0f);
	bool IsPossible = false;
	int size = 0;

	//タレットの設置数が0個じゃないとき
	if (Turret_List.size() != 0)
	{

		for (int Turret_Index = 0; Turret_Index < Turret_List.size(); Turret_Index++)
		{
			if (!CCollision::CheckHitBoxToBox(vPos, vSize, Turret_List[Turret_Index]->GetPos(), vSize))
			{
				size++;
				IsPossible = true;	//設置可能フラグをtrueにする
			}
			
			if (IsPossible)
			{
				

				//現在のサイズを格納
				int cnt = Turret_List.size();

				//変数代入用クラス
				CTurretBase* cTurretBase = new CTurret_Normal;
				cTurretBase->Init();
				cTurretBase->Load(TurretN_Hndl);
				cTurretBase->TurretSpawn(vPos);

				//リストに追加
				Turret_List.push_back(cTurretBase);

				if (cnt != Turret_List.size())
				{
					return;
				}
			}
		}
	}
	//タレットの設置数が0個の時
	else if(Turret_List.size() == 0)
	{
		//変数代入用クラス
		CTurretBase* cTurretBase = new CTurret_Normal;
		cTurretBase->Init();
		cTurretBase->Load(TurretN_Hndl);
		cTurretBase->TurretSpawn(vPos);

		//リストに追加
		Turret_List.push_back(cTurretBase);
	}


	/*
	//変数代入用クラス
	CTurretBase* cTurretBase = new CTurret_Normal;
	cTurretBase->Init();
	cTurretBase->Load(TurretN_Hndl);
	cTurretBase->TurretSpawn(vPos);

	//リストに追加
	Turret_List.push_back(cTurretBase);
	*/
}
