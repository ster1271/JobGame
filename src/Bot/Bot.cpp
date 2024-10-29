#include "Bot.h"
#include "../Map/Map.h"

const char BOT_FILE_PATH[] = { "data/enemy/Enemy01.x" };
const float MOVE_SPEED = 5.0f;
const float SPERE_R = 10.0f;

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
	cPos = VGet(50, 0.0f, 400.0f);
	cSize = VGet(0.1f, 0.1f, 0.1);
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
	DrawFormatString(0, 225, GetColor(0, 0, 0), "距離:%2f", tmp_Range);
	//DrawFormatString(0, 300, GetColor(0, 0, 255), "今行ってる処理:%d", NUM);
}

//マイフレーム行う処理
void CBot::Step(CMap &cMap)
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
		VECTOR GOAL = VGet(400.0f, 0.0f, 400.0f);
		if (cRoute_Search.Route_Search(cPos, GOAL, cMap))
		{
			IsCalcu = false;
			State_Id = STATE_MOVE;
		}


		break;
	case CBot::STATE_MOVE:
		cRoute_Search.Go_Route(cPos, cRotate);
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
	//進行方向のどちら側にいるのかを調べる
	float Dir = 0.0f;

	//ボットから指定の地点へ行くベクトルを計算
	VECTOR Vtmp;
	Vtmp.x = List[tmp].x - cPos.x;
	Vtmp.y = 0.0f;
	Vtmp.z = List[tmp].z - cPos.z;

	VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);	//ボットの移動ベクトル
	vSpd.x = sinf(cRotate.y) * -MOVE_SPEED;
	vSpd.y = 0.0f;
	vSpd.z = cosf(cRotate.y) * -MOVE_SPEED;

	//外積計算
	Dir = (Vtmp.x * vSpd.z) - (vSpd.x * Vtmp.z);
	//確認用
	tmp_dir = Dir;

	if (fabsf(Dir) < 1.0f)
	{
		float X = Vtmp.x = cPos.x - List[tmp].x;
		float Z = Vtmp.x = cPos.z - List[tmp].z;

		//指定の位置へ角度を変える
		float NextRotY = atan2f(X, Z);

		cRotate.y = NextRotY;
	}
	else if (Dir >= 0.0f)//それ以外は角度を変える
	{
		//NUM = 1;
		cRotate.y += 0.05f;
	}
	else if (Dir < 0.0f)
	{
		//NUM = 2;
		cRotate.y -= 0.05f;
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
	if (Range < 0.5f)
	{
		tmp++;

		if (tmp == List.size())
		{
			State_Id = STATE_STOP;
			tmp = 0;
		}
	}
}


