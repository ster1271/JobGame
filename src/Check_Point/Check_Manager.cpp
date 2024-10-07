#include "Check_Manager.h"

const char POINT_PATH[] = { "data/Map/Point.x" };


//コンストラクタ
CChecck_Manager::CChecck_Manager()
{
	memset(&MousePos, 0, sizeof(VECTOR));
	MouseX = MouseY = 0;;

	check_Hndl = -1;
	check_id = ID_NUM;
}

//デストラクタ
CChecck_Manager::~CChecck_Manager() {};

//初期化
void CChecck_Manager::Init()
{
	MousePos = VGet(0.0f, 0.0f, 0.0f);
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

	if (CInput::IsKeyPush(KEY_INPUT_1))
	{
		check_id = ID_CHECK_POINT;
	}
	else if (CInput::IsKeyPush(KEY_INPUT_2))
	{
		check_id = ID_ENEMY_SPAWN;
	}


	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		//マウスのスクリーン座標をワールド座標に変換
		//MousePos = VGet(MouseX, MouseY, 0.0f);
		//MousePos = ConvScreenPosToWorldPos(MousePos);
	}
}

//デバック時の描画
void CChecck_Manager::DebugDraw()
{
	DrawFormatString(0, 60, GetColor(255, 255, 255), "マウスX座標：%d", MousePos.x);
	DrawFormatString(0, 75, GetColor(255, 255, 255), "マウスY座標：%d", MousePos.y);
	DrawFormatString(0, 90, GetColor(255, 255, 255), "マウスY座標：%d", MousePos.x);

	switch (check_id)
	{
	case ID_CHECK_POINT:
		DrawFormatString(0, 30, GetColor(255, 0, 0), "チェックポイントだよー");
		break;
	case ID_ENEMY_SPAWN:
		DrawFormatString(0, 30, GetColor(255, 0, 0), "敵沸きポイントだよー");
		break;
	case ID_NUM:
		DrawFormatString(0, 30, GetColor(255, 0, 0), "何も持ってないよ");
		break;
	default:
		break;
	}
}
