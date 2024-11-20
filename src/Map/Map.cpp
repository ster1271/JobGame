#pragma once
#include "Map.h"

#define MAP_SIZE		50	//マップのサイズ
#define MAP_MAX_NUM		10	//マップの縦横

const char BLOCK_MODEL_PATH[] = "data/Map/block.x";
const char FLOAR_MODEL_PATH[] = "data/Map/floar.x";

//コンストラクタ
CMap::CMap()
{
}

//デストラクタ
CMap::~CMap()
{
}

//初期化
void CMap::Init()
{
	//ハンドルの初期化
	iHndl = -1;

	//各変数の初期化
	cPos = VECTOR_ZERO;
	cScale = VGet(2.5f, 2.5f, 2.5f);
	cRotate = VECTOR_ZERO;
	cSize = VECTOR_ZERO;

	WallList.clear();
	FloarList.clear();
}

//モデル読み込み
void CMap::Load()
{
	//ファイル読み込み
	MapLoad();
}

//更新
void CMap::Updata()
{
	for (int i = 0; i < WallList.size(); i++)
	{
		MV1SetPosition(WallList[i].iHndl, WallList[i].vPos);		//座標の更新
		MV1SetScale(WallList[i].iHndl, cScale);					//サイズの更新
		MV1SetRotationXYZ(WallList[i].iHndl, cRotate);			//回転値の更新
	}

	for (int i = 0; i < FloarList.size(); i++)
	{
		MV1SetPosition(FloarList[i].iHndl, FloarList[i].vPos);		//座標の更新
		MV1SetScale(FloarList[i].iHndl, cScale);					//サイズの更新
		MV1SetRotationXYZ(FloarList[i].iHndl, cRotate);				//回転値の更新
	}

}

//CSV読み込み
void CMap::MapLoad()
{
	int WallHndl = MV1LoadModel(BLOCK_MODEL_PATH);
	int FloarHndl = MV1LoadModel(FLOAR_MODEL_PATH);

	WallInfo Walltmp;
	FloarInfo Floartmp;

	int cnt = 0;
	int num[MAP_MAX_NUM] = { 0 };
	fopen_s(&fp_, "Data/Map/Maptest.csv", "r");
	if (fp_ != nullptr)
	{
	
		while (fscanf_s(fp_, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
			&num[0], &num[1], &num[2], &num[3], &num[4],
			&num[5], &num[6], &num[7], &num[8], &num[9]) != EOF)
		{
			for (int i = 0; i < MAP_MAX_NUM; i++)
			{
				if (num[i] == 1)
				{
					Walltmp.vPos = VGet(i * MAP_SIZE, 5.0f, cnt * MAP_SIZE);
					Walltmp.IsMap = true;
					Walltmp.iHndl = MV1DuplicateModel(WallHndl);	//壁
					WallList.push_back(Walltmp);
				}
				else if (num[i] == 0)
				{
					Floartmp.vPos = VGet(i * MAP_SIZE, -40.0f, cnt * MAP_SIZE);
					Floartmp.IsMap = false;
					Floartmp.iHndl = MV1DuplicateModel(FloarHndl);	//床
					FloarList.push_back(Floartmp);
				}
			}


			cnt++;
		}
	}
	fclose(fp_);
}


void CMap::Draw()
{
	cSize = VGet(50.0f, 50.0f, 50.0f);
	for (int i = 0; i < WallList.size(); i++)
	{
		MV1DrawModel(WallList[i].iHndl);
	}

	for (int i = 0; i < FloarList.size(); i++)
	{
		MV1DrawModel(FloarList[i].iHndl);
	}
}
