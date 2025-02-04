#include "UIManager.h"

//コンストラクタ
CUIManager::CUIManager(){}

//デストラクタ
CUIManager::~CUIManager(){}

//初期化
void CUIManager::Init()
{
	cPlayerUI.Init();
	cWaveUI.Init();
	cEnemyUI.Init();
}


//読み込み
void CUIManager::Load()
{
	cPlayerUI.Load();
	cWaveUI.Load();
	cEnemyUI.Load();
}

//描画
void CUIManager::Draw()
{
	cPlayerUI.Draw();
	cWaveUI.Draw();
	cEnemyUI.Draw();
}

//毎フレーム行う処理
void CUIManager::Step(CEnemyManager& cEnemyManager)
{
	cPlayerUI.Step();
	cEnemyUI.Step(cEnemyManager);
}
