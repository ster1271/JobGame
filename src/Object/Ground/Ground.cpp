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


	
//読み込み
//ファイルを開く
fopen_s(&fp_, "Data/Map/Place_Objects.txt", "r");
MapInfo tmp;
VECTOR LoadPos = VGet(0.0f, 0.0f, 0.0f);
int num;
if (fp_ != nullptr)
{
	while (fscanf_s(fp_, "%f, %f, %f, %d", &LoadPos.x, &LoadPos.y, &LoadPos.z, &num) != EOF)
	{
		tmp.vPos = LoadPos;
		if (num == 1)
		{
			tmp.IsMap = true;
		}
		else
		{
			tmp.IsMap = false;
		}
		MapList.push_back(tmp);
	}
}
fclose(fp_);

	
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
void CGround::Load()
{
	/*iHndl = MV1LoadModel("data/Map/Map01.x");*/

	//コリジョン情報を取得する
	//MV1SetupCollInfo(iHndl);
}


void CGround::Draw()
{
	//MV1DrawModel(iHndl);
	VECTOR vSize = VGet(50.0f, 50.0f, 50.0f);
	for (int i = 0; i < MapList.size(); i++)
	{
		if (MapList[i].IsMap)
		{
			CDraw3D::DrawBox3D(MapList[i].vPos, vSize);
		}
	}
}


