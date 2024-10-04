#include "Check_Point.h"

const char POINT_PATH[] = { "data/Map/Point.x" };

#define MAX_NUM	(5)

//コンストラクタ
CCheck_Point::CCheck_Point()
{
	tmp_Hndl = -1;
}

//デストラクタ
CCheck_Point::~CCheck_Point()
{
	Exit();
}

//初期化
void CCheck_Point::Init()
{
	tmp = 0;
	tmp_Hndl = -1;
	
	memset(cPos, 0, sizeof(VECTOR));
	memset(cRotate, 0, sizeof(VECTOR));
	memset(cSize, 0, sizeof(VECTOR));

	for (int Index = 0; Index < MAX_NUM; Index++)
	{

		VECTOR vPos;
		vPos = VGet(GetRand(400.0f) - 200.0f, 5.0f, GetRand(600.0f) - 300.0f);
		Set_Point(Index,vPos);
	}
}

//モデル読み込み
void CCheck_Point::Load()
{
	if (tmp_Hndl == -1)
	{
		tmp_Hndl = MV1LoadModel(POINT_PATH);
	}

	for (int Index = 0; Index < MAX_NUM; Index++)
	{
		//モデルのコピー
		iHndl[Index] = MV1DuplicateModel(tmp_Hndl);
	}
}

//情報更新
void CCheck_Point::UpData()
{
	for (int tmp = 0; tmp < MAX_NUM; tmp++)
	{
		MV1SetPosition(iHndl[tmp], cPos[tmp]);		//座標の更新
		MV1SetScale(iHndl[tmp], cSize[tmp]);			//サイズの更新
		MV1SetRotationXYZ(iHndl[tmp], cRotate[tmp]);	//回転値の更新
	}
}


//描画
void CCheck_Point::Draw()
{
	for (int Index = 0; Index < MAX_NUM; Index++)
	{
		if (!IsActive)
			return;

		MV1DrawModel(iHndl[Index]);
	}
}

//毎フレーム行う処理
void CCheck_Point::Step()
{
	for (int Index = 0; Index < MAX_NUM; Index++)
	{
		if (!IsActive)
			return;

		UpData();
	}
}

//後処理
void CCheck_Point::Exit()
{
	memset(cPos, 0, sizeof(VECTOR));
	memset(cRotate, 0, sizeof(VECTOR));
	memset(cSize, 0, sizeof(VECTOR));

	for (int Index = 0; Index < MAX_NUM; Index++)
	{
		if (iHndl[Index] != -1)
		{
			MV1DeleteModel(iHndl[Index]);
			iHndl[Index] = -1;
		}
	}
	if (tmp_Hndl != -1)
	{
		MV1DeleteModel(tmp_Hndl);
		tmp_Hndl = -1;
	}
}

//設置処理
void CCheck_Point::Set_Point(int Index, VECTOR vPos)
{
	cPos[Index] = vPos;
	cSize[Index] = VGet(0.1f, 0.1f, 0.1f);
	IsActive[Index] = true;

	Point_info_List.push_back(cPos[Index]);
}

/*
//ファイル読み込み
void CCheck_Point::LoadFile()
{
	FILE* fp;

	//ファイルを開く
	fopen_s(&fp, "data/file/CheckPoint.txt", "r");

	if (fp != nullptr)
	{
		//1行目を読み込む
		fscanf_s(fp, "%f %f %f", &cPos[0].x, &cPos[0].y, &cPos[0].z);
	}

	//ファイルを閉じる
	fclose(fp);
}
*/

