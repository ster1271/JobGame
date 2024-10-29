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

		
		State_Id = STATE_MOVE;
		break;

	case CEnemyBase::STATE_MOVE:
		
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