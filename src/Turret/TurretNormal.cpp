#include "Turret_Normal.h"

const float MAX_LIFE = 50.0f;
const float ATTACK = 5.0f;
const char TURRET_NORMAL_PATH[] = { "data/Turret/Turret_Normal.x" };

//コンストラクタ
CTurret_Normal::CTurret_Normal()
{
	Attack = 0.0f;
}

//デストラクタ
CTurret_Normal::~CTurret_Normal()
{
}

//初期化
void CTurret_Normal::Init()
{
	CTurretBase::Init();
	Attack = 0.0f;
}

//データロード
void CTurret_Normal::Load()
{
	if (iHndl == -1)
	{
		//モデルの読み込み
		iHndl = MV1LoadModel(TURRET_NORMAL_PATH);
	}
}

//描画
void CTurret_Normal::Draw()
{
	if (IsActive)
	{
		MV1DrawModel(iHndl);
	}

	DrawFormatString(0, 500, GetColor(255, 255, 0), "タレットX座標:%f", cPos.x);
	DrawFormatString(0, 515, GetColor(255, 255, 0), "タレットY座標:%f", cPos.y);
	DrawFormatString(0, 530, GetColor(255, 255, 0), "タレットZ座標:%f", cPos.z);

}

//毎フレーム行う処理
void CTurret_Normal::Step()
{
	
	if (!IsActive)return;


}

//後処理
void CTurret_Normal::Exit()
{
	CTurretBase::Exit();
	Attack = 0.0f;
}

//タレット設置処理
void CTurret_Normal::TurretSpawn(const VECTOR &vPos)
{
	//すでに生成されている
	if (IsActive) return;

	cPos = vPos;
	cRotate = VGet(0.0f, DX_PI_F / 2, DX_PI_F / 2);
	cSize = VGet(0.1f, 0.1f, 0.1f);

	ShotRenge = VGet(0.0f, 0.0f, 0.0f);
	Hp = MAX_LIFE;
	Power_Up_Count = 0;
	Attack = ATTACK;

	IsActive = true;
}


//タレット強化
void CTurret_Normal::Turret_Power_Up()
{

}