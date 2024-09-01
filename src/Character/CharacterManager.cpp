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
	//メインIDを初期化
	MainID = ID_NUM;
}

//データロード
void CCharacterManager::Load()
{
	cAttacker.Load();
}

//終了処理
void CCharacterManager::Exit()
{
	cAttacker.Exit();
}

//毎フレーム呼ぶ処理
void CCharacterManager::Step()
{
	//メインキャラ処理
	switch (MainID)
	{
	case MainID_ATTACKER:
		cAttacker.Step();
		cAttacker.Update();
		break;

	case MainID_TANK:
		break;

	case MainID_SUPPORT:
		break;

	case ID_NUM:
		break;

	default:
		break;
	}
	
}

//描画処理
void CCharacterManager::Draw()
{
	cAttacker.Draw();
}