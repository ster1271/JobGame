#include "Ground.h"

//コンストラクタ
CGround::CGround()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
}

//デストラクタ
CGround::~CGround()
{
	//ハンドルの初期化
	iHndl = -1;

	//変数の初期化
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
}

//初期化
void CGround::Init()
{
	//ハンドルの初期化
	iHndl = -1;

	//各変数の初期化
	cPos = VGet(0.0f, -20.0f, 0.0f);
	cSize = VGet(1.0f, 1.0f, 1.0f);
	cRotate = VGet(0.0f, 0.0f, 0.0f);


	int matrix[MAX_NUM][MAX_NUM] = {
		{1, 1, 1, 1, 1, 1, 1 ,1 ,1, 1},
		{1, 0, 0, 0, 0, 0, 1 ,0 ,0, 1},
		{1, 0, 0, 0, 0, 0, 1 ,0 ,0, 1},
		{1, 0, 0, 0, 0, 0, 1 ,0 ,0, 1},
		{1, 0, 0, 0, 0, 0, 1 ,0 ,0, 1},
		{1, 0, 0, 0, 0, 0, 0 ,0 ,0, 1},
		{1, 0, 1, 1, 0, 0, 0 ,0 ,0, 1},
		{1, 0, 0, 1, 0, 0, 0 ,0 ,0, 1},
		{1, 0, 0, 0, 0, 0, 0 ,0 ,0, 1},
		{1, 1, 1, 1, 1, 1, 1 ,1 ,1, 1},
	};

	/*VECTOR POS[] = {
		{-200.0f, 50.0f, 200.0f}, {-150.0f, 50.0f, 200.0f},
		{-100.0f, 50.0f, 200.0f}, {-50.0f, 50.0f, 200.0f},
		{0.0f, 50.0f, 200.0f}, {50.0f, 50.0f, 200.0f},
		{50.0f, 50.0f, 200.0f}, {100.0f, 50.0f, 200.0f},
		{-200.0f, 50.0f, 200.0f}, {-150.0f, 50.0f, 200.0f},
		{-200.0f, 50.0f, 200.0f}, {-150.0f, 50.0f, 200.0f},

	}*/

	for (int i = 0; i < 10; i++)
	{
		for (int a = 0; a < 10; a++)
		{
			tmp[i][a] = matrix[i][a];
		}
	}
}

//モデル読み込み
void CGround::Load()
{
	/*iHndl = MV1LoadModel("data/Map/Map01.x");*/

	//コリジョン情報を取得する
	//MV1SetupCollInfo(iHndl);
}


void CGround::Draw()
{
	//MV1DrawModel(iHndl);

	//ボックスのサイズ約1500
	//CDraw3D::DrawBox3D(VGet(0.0f, 0.0f, 0.0f), VGet(50.0f, 50.0f, 50.0f));

	for (int i = 0; i < 10; i++)
	{
		for (int a = 0; a < 10; a++)
		{
			if (tmp[i][a] == 1)
			{
				CDraw3D::DrawBox3D(VGet(-200.0f + a * 50.0f, 0.0f, -200.0f + i * 50.0f), VGet(50.0f, 50.0f, 50.0f));
			}
		}
	}

}
