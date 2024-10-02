#include "Enemy_Normal.h"

const int MAX_LIFE (3);		//最大体力

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

	cPos = VGet(0.0f, 5.0f, GetRand(200.0f) + 100.0f);
	cSize = VGet(0.1f, 0.1f, 0.1f);
	cSpeed = VGet(0.0f, 0.0f, 0.5f);
	IsActive = true;
	Respown_Pos = cPos;
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
void CEnemy_Normal::Step()
{
	if (!IsActive)
	{
		return;
	}

	//座標に速度を加算
	cPos = VAdd(cPos, cSpeed);
	//一定範囲を超えたら消す
	float fLength = 100.0f;
	if (cPos.x > Respown_Pos.x + fLength || cPos.x < Respown_Pos.x -fLength
		|| cPos.z > Respown_Pos.z + fLength || cPos.z < Respown_Pos .z -fLength)
	{
		IsActive = false;
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
	cSpeed = vSpeed;
	Life = MAX_LIFE;
	IsActive = true;

	return true;
}