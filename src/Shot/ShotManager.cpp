#include "ShotManager.h"


//定義
static const char PLSHOT_MODEL_PATH[] = { "data/shot/plshot.x" };
static const char TURRETSHOT_MODEL_PATH[] = { "data/shot/plshot.x" };

//------------------------------------
//コンストラクタ
//------------------------------------
CShotManager::CShotManager()
{
	PlayerHndl = -1;
	TurretHndl = -1;
}


//------------------------------------
//デストラクタ
//------------------------------------
CShotManager::~CShotManager()
{

}


//------------------------------------
//初期化
//------------------------------------
void CShotManager::Init()
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{
		cPlayerShot[i].Init();
	}

	for (int i = 0; i < TURRET_SHOT_NUM; i++)
	{
		cTurretShot[i].Init();
	}
}


//------------------------------------
//ロード
//------------------------------------
void CShotManager::Load()
{
	//オリジナルモデルの読み込み
	if (PlayerHndl == -1)
	{
		PlayerHndl = MV1LoadModel(PLSHOT_MODEL_PATH);
	}
	//モデルの複製
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{
		cPlayerShot[i].Load(PlayerHndl);
	}


	//オリジナルモデルの読み込み
	if (TurretHndl == -1)
	{
		TurretHndl = MV1LoadModel(TURRETSHOT_MODEL_PATH);
	}
	//モデルの複製
	for (int i = 0; i < TURRET_SHOT_NUM; i++)
	{
		cTurretShot[i].Load(TurretHndl);
	}
}


//------------------------------------
//終了処理
//------------------------------------
void CShotManager::Exit()
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{
		cPlayerShot[i].Exit();
	}

	for (int i = 0; i < TURRET_SHOT_NUM; i++)
	{
		cTurretShot[i].Exit();
	}

	MV1DeleteModel(PlayerHndl);
	PlayerHndl = -1;
	MV1DeleteModel(TurretHndl);
	TurretHndl = -1;
}

//------------------------------------
//毎フレーム呼ぶ処理
//------------------------------------
void CShotManager::Step(VECTOR Pos)
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{
		cPlayerShot[i].Step(Pos);
	}

	for (int i = 0; i < TURRET_SHOT_NUM; i++)
	{
		cTurretShot[i].Step();
	}
}

//------------------------------------
//更新処理
//------------------------------------
void CShotManager::Draw()
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{
		cPlayerShot[i].Draw();
	}

	
	for (int i = 0; i < TURRET_SHOT_NUM; i++)
	{
		cTurretShot[i].Draw();
	}
}


//------------------------------------
//プレイヤーのショットリクエスト
//------------------------------------
void CShotManager::RequestPlayerShot(const VECTOR& vPos, const VECTOR& vSpeed)
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{
		if (cPlayerShot[i].RequestShot(vPos, vSpeed))
		{
			//CSoundManager::Play(CSoundManager::SOUNDID_SE_PLSHOT);
			break;
		}
	}
}


//タレットのショットリクエスト
void CShotManager::RequestTurretShot(const VECTOR& vPos, const VECTOR& vSpeed)
{
	for (int i = 0; i < TURRET_SHOT_NUM; i++)
	{
		if (cTurretShot[i].RequestShot(vPos, vSpeed))
		{
			break;
		}
	}
}
