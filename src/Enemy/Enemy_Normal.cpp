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
	cPos = VSub(cPos, cSpeed);
	//一定範囲を超えたら消す
	float fLength = 100.0f;
	if (cPos.x > Respown_Pos.x + fLength || cPos.x < Respown_Pos.x -fLength
		|| cPos.z > Respown_Pos.z + fLength || cPos.z < Respown_Pos .z -fLength)
	{
		IsActive = false;
	}

	/*
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
	cPos.x += sinf(cRotate.y) * -0.1f;
	cPos.z += cosf(cRotate.y) * -0.1f;
	*/

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
	Respown_Pos = cPos;
	cSize = VGet(0.1f, 0.1f, 0.1f);
	cRotate = VGet(0.0f, -DX_PI_F / 2, 0.0f);
	cSpeed = vSpeed;
	Life = MAX_LIFE;
	IsActive = true;

	return true;
}