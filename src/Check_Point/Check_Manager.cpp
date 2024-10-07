#include "Check_Manager.h"

const char POINT_PATH[] = { "data/Map/Point.x" };


//コンストラクタ
CChecck_Manager::CChecck_Manager()
{
	check_Hndl = -1;
}

//デストラクタ
CChecck_Manager::~CChecck_Manager() {};

//初期化
void CChecck_Manager::Init()
{
	for (int Index = 0; Index < MAX_NUM; Index++)
	{
		cCheck_Point[Index].Init();
	}
}

//データ読み込み
void CChecck_Manager::Load()
{
	check_Hndl = MV1LoadModel(POINT_PATH);

	for (int Index = 0; Index < MAX_NUM; Index++)
	{
		cCheck_Point[Index].Load(check_Hndl);
	}
}

//後処理
void CChecck_Manager::Exit()
{
	for (int Index = 0; Index < MAX_NUM; Index++)
	{
		cCheck_Point[Index].Exit();
	}
}

//情報更新
void CChecck_Manager::Updata()
{
	for (int Index = 0; Index < MAX_NUM; Index++)
	{
		cCheck_Point[Index].Updata();
	}
}

//描画
void CChecck_Manager::Draw()
{
	for (int Index = 0; Index < MAX_NUM; Index++)
	{
		cCheck_Point[Index].Draw();
	}
}

void CChecck_Manager::Step()
{
	for (int Index = 0; Index < MAX_NUM; Index++)
	{
		cCheck_Point[Index].Step();
	}

	Updata();
}