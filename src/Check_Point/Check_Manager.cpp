#include "Check_Manager.h"

const char POINT_PATH[] = { "data/Map/Point.x" };


//コンストラクタ
CChecck_Manager::CChecck_Manager()
{
	memset(&fp, 0, sizeof(FILE));

	check_Hndl = -1;
	Check_id = MAX_ID;
}

//デストラクタ
CChecck_Manager::~CChecck_Manager() {};

//初期化
void CChecck_Manager::Init()
{
	check_Hndl = -1;

	int Count = 0;
	//読み込み
	//ファイルを開く
	fopen_s(&fp, "Data/ObjectFile/Object_file.txt", "r");
	VECTOR vPos = VGet(0.0f, 0.0f, 0.0f);
	if (fp != nullptr)
	{
		while (fscanf_s(fp, "%f, %f, %f", &vPos.x, &vPos.y, &vPos.z) != EOF)
		{
			cCheck_Point[Count].Set_Point(vPos);
			Point_info_List.push_back(vPos);
			
			Count++;
		}
	}

	fclose(fp);

	
	
}

//全ての情報読み取り
void CChecck_Manager::LoadInfo()
{
	
}

//データ読み込み
void CChecck_Manager::Load()
{
	check_Hndl = MV1LoadModel(POINT_PATH);

	for (int Index = 0; Index < Point_info_List.size(); Index++)
	{
		cCheck_Point[Index].Load(check_Hndl);
	}
}

//後処理
void CChecck_Manager::Exit()
{
	for (int Index = 0; Index < Point_info_List.size(); Index++)
	{
		cCheck_Point[Index].Exit();
	}
}

//情報更新
void CChecck_Manager::Updata()
{
	for (int Index = 0; Index < Point_info_List.size(); Index++)
	{
		cCheck_Point[Index].Updata();
	}
}

//描画
void CChecck_Manager::Draw()
{
	for (int Index = 0; Index < Point_info_List.size(); Index++)
	{
		cCheck_Point[Index].Draw();
	}
}

void CChecck_Manager::Step()
{
	for (int Index = 0; Index < Point_info_List.size(); Index++)
	{
		cCheck_Point[Index].Step();
	}

	Updata();
}

//デバック時の処理
void CChecck_Manager::DebugStep(VECTOR vPos)
{

	//オブジェクトの変更処理
	if (CInput::IsKeyPush(KEY_INPUT_1))
	{
		Check_id = ID_CHECK_POINT;
	}
	else if (CInput::IsKeyPush(KEY_INPUT_2))
	{
		Check_id = ID_ENEMY_SPAWN;
	}

	//オブジェクトの設置処理
	if ((CInput::IsKeyPush(KEY_INPUT_P)))
	{

		
		switch (Check_id)
		{
		case ID_CHECK_POINT:
		//リストに追加する
		Point_info_List.push_back(vPos);


		fopen_s(&fp, "Data/ObjectFile/Object_file.txt", "a");

		if (fp != nullptr)
		{
			fprintf(fp, "%.1f, %.1f, %.1f \n", vPos.x, vPos.y, vPos.z);

			fclose(fp);
		}
			break;

		case ID_ENEMY_SPAWN:

			break;

		default:
			break;
		}
		
	}
}

//デバック時の描画
void CChecck_Manager::DebugDraw()
{
	switch (Check_id)
	{
	case ID_CHECK_POINT:
		DrawFormatString(800, 30, GetColor(255, 0, 0), "チェックポイントだよー");
		break;
	case ID_ENEMY_SPAWN:
		DrawFormatString(800, 30, GetColor(255, 0, 0), "敵沸きポイントだよー");
		break;
	case MAX_ID:
		DrawFormatString(800, 30, GetColor(255, 0, 0), "何も持ってないよ");
		break;
	default:
		break;
	}

	DrawFormatString(800, 50, GetColor(255, 0, 0), "設置物の数:%d", Point_info_List.size());

}