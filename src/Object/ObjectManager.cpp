#include "ObjectManager.h"


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
	cGround.Init();
}

//読み込み関連
void CObjectManager::Load()
{
	cSky.Load();
	cGround.Load();
}

//描画
void CObjectManager::Draw()
{
	cSky.Draw();
	cGround.Draw();
}

//毎フレーム行う処理
void CObjectManager::Step()
{
	cSky.Step();
	cGround.Step();

	Update();
}

//更新処理
void CObjectManager::Update()
{
	cSky.Update();
	cGround.Update();
}

//後処理
void CObjectManager::Exit()
{
	cSky.Exit();
	cSky.Exit();
}