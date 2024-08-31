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
	cAttacker.Step();
	cAttacker.Update();
}

//描画処理
void CCharacterManager::Draw()
{
	cAttacker.Draw();
}