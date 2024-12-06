#include "TurretManager.h"
#include "../Debug/DebugString.h"

const int TURRET_MAX_NUM = 1;		//タレットの最大設置数
const char TURRET_NORMAL_PATH[] = { "data/Turret/Turret_Normal.x" };	//タレットのモデルパス
const VECTOR TURRET_SIZE = VGet(30.0f, 30.0f, 30.0f);					//タレットのサイズ


//コンストラクタ
CTurretManager::CTurretManager()
{
	Turret_Normal_Hndl = -1;
}

//デストラクタ
CTurretManager::~CTurretManager()
{
}


//初期化
void CTurretManager::Init()
{
	Turret_List.clear();
}

//データロード
void CTurretManager::Load()
{
	//オリジナルハンドルにロード
	if (Turret_Normal_Hndl == -1)
	{
		Turret_Normal_Hndl = MV1LoadModel(TURRET_NORMAL_PATH);
	}
}

//終了処理
void CTurretManager::Exit()
{
	for (int TurretIndex = 0; TurretIndex < Turret_List.size(); TurretIndex++)
	{
		Turret_List[TurretIndex]->Exit();
	}

	Turret_List.clear();
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
	CDebugString::GetInstance()->AddFormatString(500, 525, "設置できる数残り：%d", TURRET_MAX_NUM - Turret_List.size());

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
	
	int NotHitCnt = 0;

	//タレットの設置数が0個じゃない時
	if (Turret_List.size() != 0)
	{
		//最大数以上は生成しない
		if (Turret_List.size() >= TURRET_MAX_NUM)
			return;

		//当たってないときにカウントをプラスする
		for (int Turret_Index = 0; Turret_Index < Turret_List.size(); Turret_Index++)
		{
			if (!CCollision::CheckHitBoxToBox(vPos, TURRET_SIZE, Turret_List[Turret_Index]->GetPos(), TURRET_SIZE))
			{
				NotHitCnt++;
			}		
		}

		//カウントがリストのサイズと同じ(誰とも当たってない場合)なら生成する
		if (NotHitCnt == Turret_List.size())
		{
			//変数代入用クラス
			CTurretBase* cTurretBase = new CTurret_Normal;
			//基本情報を格納する
			cTurretBase->Init();
			cTurretBase->Load(Turret_Normal_Hndl);
			cTurretBase->TurretSpawn(vPos);

			//リストに追加
			Turret_List.push_back(cTurretBase);
		}
	}
	//タレットの設置数が0個の時
	else if(Turret_List.size() == 0)
	{
		//変数代入用クラス
		CTurretBase* cTurretBase = new CTurret_Normal;
		cTurretBase->Init();
		cTurretBase->Load(Turret_Normal_Hndl);
		cTurretBase->TurretSpawn(vPos);

		//リストに追加
		Turret_List.push_back(cTurretBase);
	}
}
