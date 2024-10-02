#include "ObjectManager.h"

const char POINT_PATH[] = { "data/Map/Point.x" };



//コンストラクタ
CObjectManager::CObjectManager()
{
	Point_Hndl = -1;
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
	Point_Hndl = MV1LoadModel(POINT_PATH);
}

//描画
void CObjectManager::Draw()
{
	cSky.Draw();
	cGround.Draw();

	for (int Point_Index = 0; Point_Index < Point_List.size(); Point_Index++)
	{
		Point_List[Point_Index]->Draw();
	}
}

//毎フレーム行う処理
void CObjectManager::Step()
{
	cSky.Step();
	cGround.Step();

	for (int Point_Index = 0; Point_Index < Point_List.size(); Point_Index++)
	{
		Point_List[Point_Index]->Step();
	}

	Update();
}

//更新処理
void CObjectManager::Update()
{
	cSky.Update();
	cGround.Update();

	for (int Point_Index = 0; Point_Index < Point_List.size(); Point_Index++)
	{
		Point_List[Point_Index]->Update();
	}
}

//後処理
void CObjectManager::Exit()
{
	cSky.Exit();
	cGround.Exit();

	for (int Point_Index = 0; Point_Index < Point_List.size(); Point_Index++)
	{
		Point_List[Point_Index]->Exit();
	}

	if (Point_Hndl != -1)
	{
		MV1DeleteModel(Point_Hndl);
		Point_Hndl = -1;
	}
}

//設置処理
void CObjectManager::Set_Point(const VECTOR& vPos)
{
	//変数代入用クラス
	CObject* cObject = new CRoute_Point;
	cObject->Init();
	cObject->Load(Point_Hndl);
	cObject->Set_Point(vPos);

	//リストに追加
	Point_List.push_back(cObject);
}
