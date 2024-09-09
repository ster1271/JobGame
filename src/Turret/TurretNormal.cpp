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

}

//描画
void CTurret_Normal::Draw()
{

}

//毎フレーム行う処理
void CTurret_Normal::Step()
{

}

//後処理
void CTurret_Normal::Exit()
{
	TurretBase::Exit();
	Attack = 0.0f;
}