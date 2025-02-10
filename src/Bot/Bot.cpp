#include "Bot.h"

const char BOT_FILE_PATH[] = { "data/Bot/Bot.x" };
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
	
	cPos = VGet(150, 0.0f, 160.0f);
	cSize = VGet(0.06f, 0.06f, 0.06f);
	cRotate = VGet(0.0f, 0.0f, 0.0f);

	Route_List.clear();
	IsFinish = false;
	IsActive = false;
	State_Id = STATE_STOP;
}

//後処理
void CBot::Exit()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));

	iHndl = -1;
	Route_List.clear();
	IsFinish = false;
	IsActive = false;

	State_Id = STATE_NUM;
}

//読み込み
bool CBot::Load()
{
	iHndl = MV1LoadModel(BOT_FILE_PATH);

	if (iHndl != -1)
	{
		IsActive = true;
		Updata();
		return true;
	}
	else
		return false;
}

//情報更新
void CBot::Updata()
{
	MV1SetPosition(iHndl, cPos);		//座標の更新
	MV1SetScale(iHndl, cSize);			//サイズの更新
	MV1SetRotationXYZ(iHndl, cRotate);	//回転値の更新
}

//描画
void CBot::Draw()
{
	if (!IsActive)
		return;

	MV1DrawModel(iHndl);

	if (IS_DEBUG)
	{
		DrawFormatString(0, 150, GetColor(0, 0, 0), "ボットX座標:%f", cPos.x);
		DrawFormatString(0, 165, GetColor(0, 0, 0), "ボットY座標:%f", cPos.y);
		DrawFormatString(0, 180, GetColor(0, 0, 0), "ボットZ座標:%f", cPos.z);
		DrawFormatString(0, 195, GetColor(0, 0, 0), "Y軸角度:%f", cRotate.y);
		DrawFormatString(0, 210, GetColor(0, 0, 0), "外積:%f", tmp_dir);
		DrawFormatString(0, 225, GetColor(0, 0, 0), "距離:%2f", tmp_Range);

		for (int i = 0; i < Route_List.size(); i++)
		{
			CDraw3D::DrawBox3D(VGet(Route_List[i].x, Route_List[i].y, Route_List[i].z), VGet(10, 30, 10));
		}
	}
}

//マイフレーム行う処理
void CBot::Step(CMapManager& cMapManager)
{
	switch (State_Id)
	{
	case CBot::STATE_STOP:

		//リストが空なら値を入れる(1度のみ)
		if (Route_List.empty() == true)
		{
			tmp = 0;
			Route_List = CRoute_Search::GetInstance()->Route_Search(cPos, cMapManager.GetGoal().GetPos(), cMapManager);
		}

		//ウェーブが変更されたら状態を変更する
		if (CWave::GetInstance()->GetIsWave() && CWave::GetInstance()->GetIsBotMove())
		{
			//Idを変更する
			State_Id = STATE_SEARCH;
		}
		break;

	case CBot::STATE_SEARCH:
		
		State_Id = STATE_MOVE;
		break;

	case CBot::STATE_MOVE:
		Move_Bot(Route_List);
		break;

	default:
		break;
	}
	
	//更新処理
	Updata();
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
		float X = cPos.x - List[tmp].x;
		float Z = cPos.z - List[tmp].z;

		//指定の位置へ角度を変える
		float NextRotY = atan2f(X, Z);

		cRotate.y = NextRotY;
	}
	else if (Dir >= 0.0f)//それ以外は角度を変える
	{
		cRotate.y += 0.05f;
	}
	else if (Dir < 0.0f)
	{
		cRotate.y -= 0.05f;
	}

	//座標に速度を加算する
	cPos.x += sinf(cRotate.y) * -0.2f;
	cPos.z += cosf(cRotate.y) * -0.2f;

	//プレイヤーとの距離を計算
	VECTOR v_tmp;
	v_tmp.x = List[tmp].x - cPos.x;
	v_tmp.y = 0.0f;
	v_tmp.z = List[tmp].z - cPos.z;

	float Range = VSize(v_tmp);

	//確認用
	tmp_Range = Range;

	//距離が一定値に達したらIdを変更する
	if (Range < 0.5f)
	{
		tmp++;

		if (tmp == List.size())
		{
			IsFinish = true;
			State_Id = STATE_STOP;
			CWave::GetInstance()->WaveStateChange(STATE_WAVE_END);

			tmp = 0;
		}
	}
}


