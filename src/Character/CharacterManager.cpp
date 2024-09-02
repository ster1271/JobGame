#include "CharacterManager.h"

//コンストラクタ
CCharacterManager::CCharacterManager()
{
	//メインIDを初期化
	MainID = ID_NUM;
}

//デストラクタ
CCharacterManager::~CCharacterManager()
{
}


//初期化
void CCharacterManager::Init()
{
	//ショットマネージャー初期化
	cShotManager.Init();

	cAttacker.Init();
	cTank.Init();
	cSupport.Init();

	//メインIDを初期化
	MainID = ID_NUM;
}

//データロード
void CCharacterManager::Load()
{
	//ショットマネージャー初期化
	cShotManager.Load();

	cAttacker.Load();
	cTank.Load();
	cSupport.Load();
}

//終了処理
void CCharacterManager::Exit()
{
	//メインキャラ後処理
	/*
	switch (MainID)
	{
	case MainID_ATTACKER:
		cAttacker.Exit();
		break;

	case MainID_TANK:
		cTank.Exit();
		break;

	case MainID_SUPPORT:
		cSupport.Exit();
		break;

	case ID_NUM:
		break;

	default:
		break;
	}
	*/
	cAttacker.Exit();
	cTank.Exit();
	cSupport.Exit();

	//ショットマネージャー後処理
	cShotManager.Exit();
}

//毎フレーム呼ぶ処理
void CCharacterManager::Step()
{
	//メインキャラ処理
	switch (MainID)
	{
	case MainID_ATTACKER:
		cAttacker.Step(cShotManager);
		cAttacker.Update();
		break;

	case MainID_TANK:
		cTank.Step(cShotManager);
		cTank.Update();
		break;

	case MainID_SUPPORT:
		cSupport.Step(cShotManager);
		cSupport.Update();
		break;

	case ID_NUM:
		break;

	default:
		break;
	}

	
	cShotManager.Step(cAttacker.GetPos());
}

//描画処理
void CCharacterManager::Draw()
{
	//メインキャラ描画
	switch (MainID)
	{
	case MainID_ATTACKER:
		cAttacker.Draw();
		break;

	case MainID_TANK:
		cTank.Draw();
		break;

	case MainID_SUPPORT:
		cSupport.Draw();
		break;

	case ID_NUM:
		break;

	default:
		break;
	}

	cShotManager.Draw();
}