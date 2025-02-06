#include "TurretManager.h"
#include "../Debug/DebugString.h"

const int TURRET_MAX_NUM = 10;		//タレットの最大設置数
const char TURRET_NORMAL_PATH[] = { "data/Turret/Turret_Normal.x" };	//タレットのモデルパス
const VECTOR TURRET_SIZE = VGet(30.0f, 30.0f, 30.0f);					//タレットのサイズ
const VECTOR SPAWN_PLACE_SIZE = VGet(30.0f, 10.0f, 30.0f);				//設置場所のサイズ


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
	PlaceList.clear();
}

//データロード
void CTurretManager::Load()
{
	//オリジナルハンドルにロード
	if (Turret_Normal_Hndl == -1)
	{
		Turret_Normal_Hndl = MV1LoadModel(TURRET_NORMAL_PATH);
	}

	LoadTurretSpawn();
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

	for (int Index = 0; Index < PlaceList.size(); Index++)
	{
		MV1SetPosition(PlaceList[Index].iHndl, PlaceList[Index].vPos);		//座標の更新
		MV1SetScale(PlaceList[Index].iHndl, PlaceList[Index].vSize);		//サイズの更新
		MV1SetRotationXYZ(PlaceList[Index].iHndl, VGet(0.0f, 0.0f, 0.0f));	//回転値の更新
	}

	//CDebugString::GetInstance()->AddFormatString(500, 500, "リストの個数：%d", Turret_List.size());
	//CDebugString::GetInstance()->AddFormatString(500, 525, "設置できる数残り：%d", TURRET_MAX_NUM - Turret_List.size());

}

//描画処理
void CTurretManager::Draw()
{
	for (int TurretIndex = 0; TurretIndex < Turret_List.size(); TurretIndex++)
	{
		Turret_List[TurretIndex]->Draw();
	}

	for (int Index = 0; Index < PlaceList.size(); Index++)
	{
		MV1DrawModel(PlaceList[Index].iHndl);
	}
}

//タレット設置処理
void CTurretManager::TurretSpawn(const VECTOR& vPos)
{

	for (int SpawnIndex = 0; SpawnIndex < PlaceList.size(); SpawnIndex++)
	{
		//プレイヤーと設置位置との当たり判定をとる
		if (CCollision::CheckHitBoxToBox(vPos, VGet(15.0f, 30.0f, 15.0f), PlaceList[SpawnIndex].vPos, SPAWN_PLACE_SIZE))
		{
			//設置フラグがfalseなら設置する
			if (PlaceList[SpawnIndex].IsInstall)
				continue;

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
	
	//int NotHitCnt = 0;

	////タレットの設置数が0個じゃない時
	//if (Turret_List.size() != 0)
	//{
	//	//最大数以上は生成しない
	//	if (Turret_List.size() >= TURRET_MAX_NUM)
	//		return;

	//	//当たってないときにカウントをプラスする
	//	for (int Turret_Index = 0; Turret_Index < Turret_List.size(); Turret_Index++)
	//	{
	//		if (!CCollision::CheckHitBoxToBox(vPos, TURRET_SIZE, Turret_List[Turret_Index]->GetPos(), TURRET_SIZE))
	//		{
	//			NotHitCnt++;
	//		}		
	//	}

	//	//カウントがリストのサイズと同じ(誰とも当たってない場合)なら生成する
	//	if (NotHitCnt == Turret_List.size())
	//	{
	//		//変数代入用クラス
	//		CTurretBase* cTurretBase = new CTurret_Normal;
	//		//基本情報を格納する
	//		cTurretBase->Init();
	//		cTurretBase->Load(Turret_Normal_Hndl);
	//		cTurretBase->TurretSpawn(vPos);

	//		//リストに追加
	//		Turret_List.push_back(cTurretBase);
	//	}
	//}
	////タレットの設置数が0個の時
	//else if(Turret_List.size() == 0)
	//{
	//	//変数代入用クラス
	//	CTurretBase* cTurretBase = new CTurret_Normal;
	//	cTurretBase->Init();
	//	cTurretBase->Load(Turret_Normal_Hndl);
	//	cTurretBase->TurretSpawn(vPos);

	//	//リストに追加
	//	Turret_List.push_back(cTurretBase);
	//}
}


//タレット設置場所読み込み処理
void CTurretManager::LoadTurretSpawn()
{
	FILE* fp;
	int Pos[3];
	TurretPlaceInfo tmpInfo;

	int Hndl = MV1LoadModel("data/Turret/TS_Place.x");

	fopen_s(&fp, "data/Turret/TurretPlace.txt", "r");		//CSVファイル読み込み

	//方法1
	if (fp != nullptr)
	{

		while (fscanf_s(fp, "%d,%d,%d",&Pos[0], &Pos[1], &Pos[2]) != EOF)
		{
			tmpInfo.vPos = VGet(Pos[0], Pos[1], Pos[2]);
			tmpInfo.vSize = VGet(0.1f, 0.1f, 0.1f);
			tmpInfo.IsInstall = false;
			tmpInfo.iHndl = MV1DuplicateModel(Hndl);

			PlaceList.push_back(tmpInfo);
		}
	}

	for (int Index = 0; Index < PlaceList.size(); Index++)
	{
		MV1SetPosition(PlaceList[Index].iHndl, PlaceList[Index].vPos);		//座標の更新
		MV1SetScale(PlaceList[Index].iHndl, PlaceList[Index].vSize);		//サイズの更新
		MV1SetRotationXYZ(PlaceList[Index].iHndl, VGet(0.0f, 0.0f, 0.0f));	//回転値の更新
	}

	fclose(fp);
}
