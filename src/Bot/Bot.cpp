#include "Bot.h"
#include "../Map/Map.h"

const char BOT_FILE_PATH[] = { "" };
const float MOVE_SPEED = 5.0f;
const float SPERE_R = 10.0f;

#define DEG_TO_RAD(a)	((a) * DX_PI_F / 180.0f)	//ラジアン角に変換する式

//コンストラクタ
CBot::CBot()
{
	tmp_dir = 0;
	tmp_Range = 0;
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
	cPos = VGet(200.0f, 0.0f, -150.0f);
	cSize = VGet(1.0f, 1.0f, 1.0f);
	cRotate = VGet(0.0f, 0.0f, 0.0f);

	tmp = 0;

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
	DrawFormatString(0, 195, GetColor(0, 0, 0), "Y軸角度:%f", cRotate.y);
	DrawFormatString(0, 210, GetColor(0, 0, 0), "外積:%f", tmp_dir);
	DrawFormatString(0, 225, GetColor(0, 0, 0), "距離:%f", tmp_Range);
}

//マイフレーム行う処理
void CBot::Step(CRoute_Search& cRoute_Search, CMap &cMap)
{
	

	switch (State_Id)
	{
	case CBot::STATE_STOP:

		//テスト用処理
		if (CInput::IsKeyPush(KEY_INPUT_1))
		{
			//Idを変更する
			State_Id = STATE_SEARCH;
		}
		break;

	case CBot::STATE_SEARCH:
		//経路探索が終了したら
		VECTOR GOAL = VGet(-150.0f, 0.0f, 200.0f);
		if (cRoute_Search.Route_Search(cPos, GOAL, cMap))
		{
			State_Id = STATE_MOVE;
		}


		break;
	case CBot::STATE_MOVE:
		
		Move_Bot(cRoute_Search.GetSearch_List());	//追尾処理
		break;

	default:
		break;
	}
	
	//更新処理
	Update();
}


//指定の場所に動く処理
void CBot::Move_Bot(vector<VECTOR> List)
{
	
	//ボットから指定の地点へ行くベクトルを計算
	VECTOR Vtmp;
	Vtmp.x = List[tmp].x - cPos.x;
	Vtmp.y = 0.0f;
	Vtmp.z = List[tmp].z - cPos.z;

	//進行方向のどちら側にいるのかを調べる
	float Dir = 0.0f;

	VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);	//ボットの移動ベクトル
	vSpd.x = sinf(cRotate.y) * -MOVE_SPEED;
	vSpd.y = 0.0f;
	vSpd.z = cosf(cRotate.y) * -MOVE_SPEED;

	//外積計算
	Dir = Vtmp.x * vSpd.z - vSpd.x * Vtmp.z;
	//確認用
	tmp_dir = Dir;

	//回転する角度を決める
	if (Dir >= 0.0f)
	{
		cRotate.y += 0.01f;
	}
	else if (Dir < 0.0f)
	{
		cRotate.y -= 0.01f;
	}

	//座標に速度を加算する
	cPos.x += sinf(cRotate.y) * -0.2f;
	cPos.z += cosf(cRotate.y) * -0.2f;

	//プレイヤーとの距離を計算
	float Range = (List[tmp].x - cPos.x) * (List[tmp].x - cPos.x) + (List[tmp].z - cPos.z) * (List[tmp].z - cPos.z);
	Range = sqrt(Range);
	//確認用
	tmp_Range = Range;

	//距離が一定値に達したらIdを変更する
	if (Range < 0.1f)
	{
		//float X = List[tmp].x - cPos.x;
		//float Z = List[tmp].z - cPos.z;

		////指定の位置へ角度を変える
		//float NextRotY = atan2f(X, Z);
		//cRotate.y += NextRotY;

		tmp++;

		if (tmp == List.size())
		{
			State_Id = STATE_STOP;
			tmp = 0;
		}
	}
}


