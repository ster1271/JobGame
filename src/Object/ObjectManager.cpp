#include "ObjectManager.h"

const char POINT_PATH[] = { "data/Map/Point.x" };



//コンストラクタ
CObjectManager::CObjectManager()
{
}

//デストラクタ
CObjectManager::~CObjectManager()
{
}

//初期化
void CObjectManager::Init()
{
	cSky.Init();
}

//読み込み関連
void CObjectManager::Load()
{
	cSky.Load();
}

//描画
void CObjectManager::Draw()
{
	cSky.Draw();
}

//毎フレーム行う処理
void CObjectManager::Step()
{
	cSky.Step();

	Update();
}

//更新処理
void CObjectManager::Update()
{
	cSky.Update();
}

//後処理
void CObjectManager::Exit()
{
	cSky.Exit();
}


