#include "Bot.h"

const char BOT_FILE_PATH[] = { "" };
const float SPERE_R = 5.0f;

#define DEG_TO_RAD(a)	((a) * DX_PI_F / 180.0f)	//ラジアン角に変換する式

//コンストラクタ
CBot::CBot()
{
	State_Id = STATE_NUM;
}

//デストラクタ
CBot::~CBot()
{
	State_Id = STATE_NUM;
}

//初期化
void CBot::Init()
{
	CObject::Init();
	cPos = VGet(0.0f, 10.0f, 100.0f);
	cSize = VGet(1.0f, 1.0f, 1.0f);
	cRotate = VGet(0.0f, 0.0f, 0.0f);

	State_Id = STATE_NUM;
}

//読み込み
bool CBot::Load()
{
	iHndl = MV1LoadModel(BOT_FILE_PATH);
	State_Id = STATE_STOP;

	if (iHndl != -1)
		return true;
	else
		return false;
}

//描画
void CBot::Draw()
{
	//条件式がtrueならモデルをfalseなら球を表示
	if (iHndl != -1)
	{
		MV1DrawModel(iHndl);
	}
	else
	{
		DrawSphere3D(cPos, SPERE_R, 32, GetColor(255, 0, 0), GetColor(255, 0, 0), TRUE);
	}

	DrawFormatString(0, 150, GetColor(0, 0, 0), "ボットX座標:%f", cPos.x);
	DrawFormatString(0, 165, GetColor(0, 0, 0), "ボットY座標:%f", cPos.y);
	DrawFormatString(0, 180, GetColor(0, 0, 0), "ボットZ座標:%f", cPos.z);
	DrawFormatString(0, 195, GetColor(0, 0, 0), "外積:%f", tmp_dir);
	DrawFormatString(0, 210, GetColor(0, 0, 0), "距離:%f", tmp_Range);

}

//マイフレーム行う処理
void CBot::Step(VECTOR Set_Point)
{
	

	switch (State_Id)
	{
	case CBot::STATE_STOP:

		//テスト用処理
		if (CInput::IsKeyPush(KEY_INPUT_1))
		{
			//Idを変更する
			State_Id = STATE_MOVE;
		}
		break;

	case CBot::STATE_MOVE:

		Move_Bot(Set_Point);	//追尾処理
		break;

	default:
		break;
	}
	
	//更新処理
	Update();
}


//指定の場所に動く処理
void CBot::Move_Bot(VECTOR Set_Point)
{
	//ボットから指定の地点へ行くベクトルを計算
	VECTOR Vtmp;
	Vtmp.x = Set_Point.x - cPos.x;
	Vtmp.y = 0.0f;
	Vtmp.z = Set_Point.z - cPos.z;

	//進行方向のどちら側にいるのかを調べる
	float Dir = 0.0f;

	VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);	//ボットの移動ベクトル
	vSpd.x = sinf(cRotate.y) * -1.0f;
	vSpd.y = 0.0f;
	vSpd.z = cosf(cRotate.y) * -1.0f;
	
	//外積計算
	Dir = Vtmp.x * vSpd.z - vSpd.x * Vtmp.z;
	//確認用
	tmp_dir = Dir;

	//回転する角度を決める
	if (Dir >= 0.0f)
	{
		cRotate.y += 0.05f;
	}
	else if (Dir < 0.0f)
	{
		cRotate.y -= 0.05f;
	}

	//座標に速度を加算する
	cPos.x += sinf(cRotate.y) * -0.3f;
	cPos.z += cosf(cRotate.y) * -0.3f;

	//プレイヤーとの距離を計算
	float Range = (Set_Point.x - cPos.x) * (Set_Point.x - cPos.x) + (Set_Point.z - cPos.z) * (Set_Point.z - cPos.z);
	Range = sqrt(Range);
	//確認用
	tmp_Range = Range;

	//距離が一定値に達したらIdを変更する
	if (Range < 1.0f)
	{
		State_Id = STATE_STOP;
	}
}

