#include "MapManager.h"

//コンストラクタ
CMapManager::CMapManager()
{

}

//デストラクタ
CMapManager::~CMapManager()
{

}

//初期化
void CMapManager::Init()
{
	cMap.Init();
	cGoal.Init();
}

//読み込み
void CMapManager::Load()
{
	cMap.Load();
	cGoal.Load();
}

//描画
void CMapManager::Draw()
{
	cMap.Draw();
	cGoal.Draw();
}

//毎フレーム行う処理
void CMapManager::Step()
{
	cMap.Step();
	cGoal.Step();

	Updata();
}

//情報更新
void CMapManager::Updata()
{
	cMap.Update();
	cGoal.Update();
}

//後処理
void CMapManager::Exit()
{
	cMap.Exit();
	cGoal.Exit();
}