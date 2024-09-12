#include "Turret_Normal.h"

//コンストラクタ
CTurret_Normal::CTurret_Normal()
{
	Attack = 0.0f;
}

//デストラクタ
CTurret_Normal::~CTurret_Normal()
{
	Attack = 0.0f;
}

//初期化
void CTurret_Normal::Init()
{
	TurretBase::Init();
	Attack = 0.0f;
}

//データロード
void CTurret_Normal::Load(const char FILEPATH[])
{
	//モデルの読み込み
	iHndl = MV1LoadModel(FILEPATH);
}

//描画
void CTurret_Normal::Draw()
{
	if (iHndl != -1)
	{
		MV1DrawModel(iHndl);
	}

}

//毎フレーム行う処理
void CTurret_Normal::Step()
{
	if (!IsActive) return;

	//座標に速度を加算

	
}

//後処理
void CTurret_Normal::Exit()
{
	TurretBase::Exit();
	Attack = 0.0f;
}