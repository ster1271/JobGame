#include "UIManager.h"

//コンストラクタ
CUIManager::CUIManager(){}

//デストラクタ
CUIManager::~CUIManager(){}


//読み込み
void CUIManager::Load()
{
	cWaveUI.Load();
}

//描画
void CUIManager::Draw()
{
	cWaveUI.Draw();
}
