#pragma once
#include "Map.h"

#define MAP_SIZE		50	//マップのサイズ
#define MAP_MAX_NUM		10	//マップの縦横

const char BLOCK_MODEL_PATH[] = "data/Map/block.x";

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
	cScale = VECTOR_ZERO;
	cRotate = VECTOR_ZERO;
	cSize = VECTOR_ZERO;

	//マップ情報の書き込み
	/*for (int i = 0; i < 10; i++)
	{
		for (int a = 0; a < 10; a++)
		{
			fopen_s(&fp_, "Data/Map/Place_Objects.txt", "a");

			if (fp_ != nullptr)
			{
				VECTOR vPos = VGet(-200.0f + a * 50.0f, 0.0f, -200.0f + i * 50.0f);
				fprintf(fp_, "%.1f, %.1f, %.1f, %d \n", vPos.x, vPos.y, vPos.z, matrix[i][a]);

				fclose(fp_);
			}
		}
	}*/


}

//モデル読み込み
void CMap::Load()
{
	//ファイル読み込み
	MapLoad();
}

//CSV読み込み
void CMap::MapLoad()
{
	iHndl = MV1LoadModel(BLOCK_MODEL_PATH);

	MapInfo tmp;
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
				tmp.vPos = VGet(i * MAP_SIZE, 5.0f, cnt * MAP_SIZE);

				if (num[i] == 1)
				{
					tmp.iHndl = MV1DuplicateModel(iHndl);
					tmp.IsMap = true;	//壁
					MapList.push_back(tmp);
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
	for (int i = 0; i < MapList.size(); i++)
	{
		if (MapList[i].IsMap)
		{
			MV1DrawModel(MapList[i].iHndl);
			//CDraw3D::DrawBox3D(MapList[i].vPos, cSize);
		}
	}
}
