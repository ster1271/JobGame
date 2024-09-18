#include "Enemy_Normal.h"

const int MAX_LIFE (3);		//最大体力

//コンストラクタ
CEnemy_Normal::CEnemy_Normal()
{
}
//デストラクタ
CEnemy_Normal::~CEnemy_Normal()
{
}

//初期化
void CEnemy_Normal::Init()
{
	CEnemyBase::Init();

}

//データロード
void CEnemy_Normal::Load(int Hndl)
{
	iHndl = MV1DuplicateModel(Hndl);
}

//描画
void CEnemy_Normal::Draw()
{
	MV1DrawModel(iHndl);
}

//毎フレーム行う処理
void CEnemy_Normal::Step(const VECTOR vPos)
{

}

//後処理
void CEnemy_Normal::Exit()
{
	CEnemyBase::Exit();
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
	Life = MAX_LIFE;
	IsActive = true;

	return true;
}