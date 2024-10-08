#include "Check_Manager.h"

const char POINT_PATH[] = { "data/Map/Point.x" };


//コンストラクタ
CChecck_Manager::CChecck_Manager()
{
	memset(&WorldPos, 0, sizeof(VECTOR));
	memset(&fp, 0, sizeof(FILE));
	MouseX = MouseY = 0;;

	check_Hndl = -1;
	check_id = ID_NUM;
}

//デストラクタ
CChecck_Manager::~CChecck_Manager() {};

//初期化
void CChecck_Manager::Init()
{
	memset(&WorldPos, 0, sizeof(VECTOR));
	MouseX = MouseY = 0;;
	check_Hndl = -1;

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

//デバック時の処理
void CChecck_Manager::DebugStep()
{
	//マウスの座標取得
	GetMousePoint(&MouseX, &MouseY);

	//オブジェクトの変更処理
	if (CInput::IsKeyPush(KEY_INPUT_1))
	{
		check_id = ID_CHECK_POINT;
	}
	else if (CInput::IsKeyPush(KEY_INPUT_2))
	{
		check_id = ID_ENEMY_SPAWN;
	}

	//オブジェクトの設置処理
	if ((CInput::IsKeyPush(KEY_INPUT_P)))
	{
		//マウスのスクリーン座標をワールド座標に変換(マウスのY座標を3DのZ座標と置き換える)
		WorldPos = ConvScreenPosToWorldPos(VGet(MouseX, 0.0f, MouseY));
		//Y座標を既定の高さにする
		WorldPos.y = 5.0f;

		//リストに追加する
		Point_info_List.push_back(WorldPos);


		fopen_s(&fp, "Data/ObjectFile/Object_file.txt", "a");

		if (fp != nullptr)
		{
			fprintf(fp, "X座標 = %.1f, Y座標 = %.1f, Z座標 = %.1f \n", WorldPos.x, WorldPos.y, WorldPos.z);

			fclose(fp);
		}
	}
}

//デバック時の描画
void CChecck_Manager::DebugDraw()
{
	DrawFormatString(0, 30, GetColor(255, 0, 0), "マウスX座標：%d", MouseX);
	DrawFormatString(0, 45, GetColor(255, 0, 0), "マウスY座標：%d", MouseX);


	DrawFormatString(0, 60, GetColor(255, 0, 0), "マウスワールドX座標：%f", WorldPos.x);
	DrawFormatString(0, 75, GetColor(255, 0, 0), "マウスワールドZ座標：%f", WorldPos.z);



	switch (check_id)
	{
	case ID_CHECK_POINT:
		DrawFormatString(800, 30, GetColor(255, 0, 0), "チェックポイントだよー");
		break;
	case ID_ENEMY_SPAWN:
		DrawFormatString(800, 30, GetColor(255, 0, 0), "敵沸きポイントだよー");
		break;
	case ID_NUM:
		DrawFormatString(800, 30, GetColor(255, 0, 0), "何も持ってないよ");
		break;
	default:
		break;
	}
}
