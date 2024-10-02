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
	cAttacker.Init();
	cTank.Init();
	cSupport.Init();

	//メインIDを初期化
	MainID = MainID_ATTACKER;
}

//データロード
void CCharacterManager::Load()
{
	cAttacker.Load();
	cTank.Load();
	cSupport.Load();
}

//終了処理
void CCharacterManager::Exit()
{
	//メインキャラ後処理
	cAttacker.Exit();
	cTank.Exit();
	cSupport.Exit();

}

//毎フレーム呼ぶ処理
void CCharacterManager::Step(CShotManager& cShotManager, CTurretManager& cTurretManager)
{
	//メインキャラ処理
	switch (MainID)
	{
	case MainID_ATTACKER:
		cAttacker.Step(cShotManager, cTurretManager);
		cAttacker.Update();
		break;

	case MainID_TANK:
		cTank.Step(cShotManager, cTurretManager);
		cTank.Update();
		break;

	case MainID_SUPPORT:
		cSupport.Step(cShotManager, cTurretManager);
		cSupport.Update();
		break;

	case ID_NUM:
		break;

	default:
		break;
	}

}

void CCharacterManager::DebugStep(CObjectManager& cObjectManager)
{
	//if (CInput::IsKeyPush(KEY_INPUT_SPACE))
	//{
	//	cObjectManager.Set_Point();
	//}
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
}