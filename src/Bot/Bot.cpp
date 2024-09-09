#include "Bot.h"

const char BOT_FILE_PATH[] = { "" };
const float SPERE_R = 3.0f;

#define DEG_TO_RAD(a)	((a) * DX_PI_F / 180.0f)	//ラジアン角に変換する式

//コンストラクタ
CBot::CBot()
{
}

//デストラクタ
CBot::~CBot()
{
}

//初期化
void CBot::Init()
{
	CObject::Init();
	cPos = VGet(0.0f, 10.0f, 100.0f);
	cSize = VGet(1.0f, 1.0f, 1.0f);
	cRotate = VGet(0.0f, 0.0f, 0.0f);

	IsMove = false;
}

//読み込み
bool CBot::Load()
{
	iHndl = MV1LoadModel(BOT_FILE_PATH);

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
	DrawFormatString(0, 195, GetColor(0, 0, 0), "内積:%f", tmp_dir);
}

//マイフレーム行う処理
void CBot::Step(VECTOR Set_Point)
{
	if (CInput::IsKeyPush(KEY_INPUT_1))
	{
		IsMove = true;
	}


	if (IsMove)
	{
		//追尾処理
		Move_Bot(Set_Point);
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
	Vtmp.z = 0.0f;
	Vtmp.y = Set_Point.z - cPos.z;

	//進行方向のどちら側にいるのかを調べる
	float Dir = 0.0f;

	VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);	//ボットの移動速度
	vSpd.x = cosf(DEG_TO_RAD(cRotate.x));
	vSpd.y = sinf(DEG_TO_RAD(cRotate.x));
	vSpd.z = 0.0f;

	Dir = (Vtmp.x * vSpd.y) - (vSpd.x * Vtmp.y);
	//確認用
	tmp_dir = Dir;

	//回転する角度を決める
	if (Dir > 0.0f)
	{
		cRotate.x -= 1.0f;
	}
	else if (Dir < 0.0f)
	{
		cRotate.x += 1.0f;
	}
	else
	{
		IsMove = false;
	}

	vSpd.x = cosf(DEG_TO_RAD(cRotate.x));
	vSpd.y = sinf(DEG_TO_RAD(cRotate.x));

	//座標に速度を加算する
	cPos.x += vSpd.x * 0.5f;
	cPos.z += vSpd.y * 0.5f;

}

