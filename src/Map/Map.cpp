#pragma once
#include "Map.h"

#define MAP_SIZE		50	//マップのサイズ
#define MAP_MAX_NUM		14	//マップの縦横

const char WALL_MODEL_PATH[] = "data/Map/wall.x";
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
		MV1SetPosition(WallList[i].iHndl, WallList[i].vPos);	//座標の更新
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
	//方法1(1文字読み込み)
	LoadMap1(MAPID_01);

	//方法2(1行読み込み)
	//LoadMap2();		
}


void CMap::Draw()
{
	for (int i = 0; i < WallList.size(); i++)
	{
		MV1DrawModel(WallList[i].iHndl);
	}

	for (int i = 0; i < FloarList.size(); i++)
	{
		MV1DrawModel(FloarList[i].iHndl);
	}
}

//マップの読み込み1
void CMap::LoadMap1(MapID id)
{
	int WallHndl = MV1LoadModel(WALL_MODEL_PATH);
	int FloarHndl = MV1LoadModel(FLOAR_MODEL_PATH);

	WallInfo Walltmp;
	FloarInfo Floartmp;

	fopen_s(&fp_, MapFilePath[id], "r");		//CSVファイル読み込み

	if (fp_ != nullptr)
	{
		int FileIndexX = 0;
		int FileIndexY = 0;
		int cnt = 0;

		while (true) {
			// 数値部分を読み込む
			char FileNum = fgetc(fp_);
			cnt++;

			if (FileNum == '0')
			{
				//床
				Floartmp.vPos = VGet(FileIndexX * MAP_SIZE, -40.0f, FileIndexY * MAP_SIZE);
				Floartmp.IsMap = false;
				Floartmp.iHndl = MV1DuplicateModel(FloarHndl);
				FloarList.push_back(Floartmp);
			}
			else if (FileNum == '1')
			{
				//壁
				Walltmp.vPos = VGet(FileIndexX * MAP_SIZE, 5.0f, FileIndexY * MAP_SIZE);
				Walltmp.MiniMapPos = VGet(FileIndexX * 10.0f, FileIndexY * 10.0f, 0.0f);
				Walltmp.IsMap = true;
				Walltmp.iHndl = MV1DuplicateModel(WallHndl);
				WallList.push_back(Walltmp);
			}

			FileIndexX++;

			// 「,」を飛ばすために読み込みを実行
			FileNum = fgetc(fp_);

			// EOFの場合は読み込み終了
			if (FileNum == EOF)
			{
				break;
			}

			// 改行コードの場合は保存先を変更する
			if (FileNum == '\n')
			{
				FileIndexY++;
				FileIndexX = 0;
			}
		}
	}
	fclose(fp_);
}

//マップの読み込み2
void CMap::LoadMap2(MapID id)
{
	int WallHndl = MV1LoadModel(WALL_MODEL_PATH);
	int FloarHndl = MV1LoadModel(FLOAR_MODEL_PATH);

	WallInfo Walltmp;
	FloarInfo Floartmp;

	int cnt = 0;
	int num[MAP_MAX_NUM] = { 0 };
	fopen_s(&fp_, MapFilePath[id], "r");		//ファイル読み込み

	//方法1
	if (fp_ != nullptr)
	{

		while (fscanf_s(fp_, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
			&num[0], &num[1], &num[2], &num[3], &num[4],
			&num[5], &num[6], &num[7], &num[8], &num[9],
			&num[10], &num[11], &num[12], &num[13]) != EOF)
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
}
