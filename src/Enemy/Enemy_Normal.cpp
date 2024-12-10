#include "Enemy_Normal.h"

const int MAX_LIFE = 20;		//最大体力
const float SPEED = 5.0f;		//移動速度
const int RESEARCH_TIME = 300;	//経路探索し直し時間

//コンストラクタ
CEnemy_Normal::CEnemy_Normal()
{
	memset(&Respown_Pos, 0, sizeof(VECTOR));
}
//デストラクタ
CEnemy_Normal::~CEnemy_Normal()
{
}

//初期化
void CEnemy_Normal::Init()
{
	CEnemyBase::Init();
	ReSeachTime = 0;
	State_Id = STATE_SEARCH;
}

//データロード
void CEnemy_Normal::Load(int Hndl)
{
	iHndl = MV1DuplicateModel(Hndl);
}

//描画
void CEnemy_Normal::Draw()
{
	if (IsActive == false)	return;

	MV1DrawModel(iHndl);
	//DrawSphere3D(cPos, Radius, 16, GetColor(255, 255, 255), GetColor(255, 255, 255), FALSE);

	if (IS_DEBUG)
	{
		cRoute_Search.Draw(GetColor(0, 0, 255));
		//DrawString(200, 200, "描画中", GetColor(0, 0, 255));
		//DrawFormatString(200, 215, GetColor(0, 0, 255), "X座標:%f", cPos.x);
		//DrawFormatString(200, 230, GetColor(0, 0, 255), "Y座標:%f", cPos.y);
		//DrawFormatString(200, 245, GetColor(0, 0, 255), "Z座標:%f", cPos.z);
	}
}

//毎フレーム行う処理
void CEnemy_Normal::Step(CBot& cBot, CMapManager& cMapManager)
{
	if (!IsActive)
		return;

	float Range = 0.0f;

	switch (State_Id)
	{
	case CEnemyBase::STATE_SEARCH:
		List = cRoute_Search.Route_Search(cPos, cBot.GetPos(), cMapManager);
		
		State_Id = STATE_MOVE;
		break;

	case CEnemyBase::STATE_MOVE:

		//プレイヤーとの距離を計算
		VECTOR v_tmp;
		v_tmp.x = cBot.GetPos().x - cPos.x;
		v_tmp.y = 0.0f;
		v_tmp.z = cBot.GetPos().z - cPos.z;

		Range = VSize(v_tmp);

		if (Range >= 50.0f)
		{
			ReSeachTime++;

			//時間経過で経路探索し直し
			if (ReSeachTime >= RESEARCH_TIME)
			{
				List.clear();
				ReSeachTime = 0;
				ListCnt = 0;
				State_Id = STATE_SEARCH;

				break;
			}

			//経路移動処理
			Enemy_Move(List, ListCnt);
		}
		else
		{
			//追尾移動
			Out_Move(cBot.GetPos());
		}


		break;
	case CEnemyBase::STATE_ATTACK:
		


		break;
	
	default:
		break;
	}

	//方向設定
	SetDir();

	//更新処理
	Update();

}

//後処理
void CEnemy_Normal::Exit()
{
	CEnemyBase::Exit();
	memset(&Respown_Pos, 0, sizeof(VECTOR));
}

//リクエスト
bool CEnemy_Normal::RequestEnemy(const VECTOR& vPos, const VECTOR& vSpeed)
{
	//すでに出現している
	if (IsActive)
	{
		return false;
	}

	cPos = vPos;
	cNextPos = cPos;
	Respown_Pos = vPos;
	cScale = VGet(0.1f, 0.1f, 0.1f);
	cSize = ENEMY_NORMAL_SIZE;
	cRotate = VGet(0.0f, DX_PI_F / 2, 0.0f);
	cSpeed = vSpeed;
	Life = MAX_LIFE;
	List.clear();
	ListCnt = 0;
	IsActive = true;

	State_Id = STATE_SEARCH;

	return true;
}

