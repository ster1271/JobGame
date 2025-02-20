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
	cButtonUI.Init();
}


//読み込み
void CUIManager::Load()
{
	cPlayerUI.Load();
	cWaveUI.Load();
	cEnemyUI.Load();
	cButtonUI.Load();
}

//描画
void CUIManager::Draw()
{
	cPlayerUI.Draw();
	cWaveUI.Draw();
	cEnemyUI.Draw();
	cButtonUI.Draw();
}

//毎フレーム行う処理
void CUIManager::Step(CEnemyManager& cEnemyManager, const int Cnt)
{
	cPlayerUI.Step();
	cEnemyUI.Step(cEnemyManager);
	cButtonUI.Step(Cnt);
}
