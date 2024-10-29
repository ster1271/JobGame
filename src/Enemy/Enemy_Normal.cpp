#include "Enemy_Normal.h"

const int MAX_LIFE = 3;		//最大体力
const float SPEED = 5.0f;

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
	if (IsActive == false)
		return;

	MV1DrawModel(iHndl);
}

//毎フレーム行う処理
void CEnemy_Normal::Step(CBot& cBot, CMap& cMap)
{
	if (!IsActive)
		return;

	float Range = 0.0f;

	switch (State_Id)
	{
	case CEnemyBase::STATE_SEARCH:
		cRoute_Search.Route_Search(cPos, cBot.GetPos(), cMap);
		
		State_Id = STATE_MOVE;
		break;

	case CEnemyBase::STATE_MOVE:
		Range = (cBot.GetPos().x - cPos.x) * (cBot.GetPos().x - cPos.x) + (cBot.GetPos().z - cPos.z) * (cBot.GetPos().z - cPos.z);
		Range = sqrt(Range);

		if (Range < 150.0f)
		{
			//進行方向のどちら側にいるのかを調べる
			float Dir = 0.0f;

			//ボットから指定の地点へ行くベクトルを計算
			VECTOR Vtmp;
			Vtmp.x = cBot.GetPos().x - cPos.x;
			Vtmp.y = 0.0f;
			Vtmp.z = cBot.GetPos().z - cPos.z;

			VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);	//ボットの移動ベクトル
			vSpd.x = sinf(cRotate.y) * -SPEED;
			vSpd.y = 0.0f;
			vSpd.z = cosf(cRotate.y) * -SPEED;

			//外積計算
			Dir = (Vtmp.x * vSpd.z) - (vSpd.x * Vtmp.z);

			if (fabsf(Dir) < 1.0f)
			{
				float X = Vtmp.x = cPos.x - cBot.GetPos().x;
				float Z = Vtmp.x = cPos.z - cBot.GetPos().z;

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
		}
		else
		{
			cRoute_Search.Go_Route(cPos, cRotate);
		}

		break;

	case CEnemyBase::STATE_ATTACK:
		 
		break;
	
	default:
		break;
	}

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
	Respown_Pos = vPos;
	cSize = VGet(0.1f, 0.1f, 0.1f);
	cRotate = VGet(0.0f, DX_PI_F / 2, 0.0f);
	cSpeed = vSpeed;
	Life = MAX_LIFE;
	IsActive = true;

	return true;
}