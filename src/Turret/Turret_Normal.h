#pragma once
#include "TurretBase.h"

//タレットクラス(通常)
class CTurret_Normal: public CTurretBase
{
private:
	float Attack;
	int CoolTime;

public:
	//コンストラクタ・デストラクタ
	CTurret_Normal();
	~CTurret_Normal();

	//初期化
	void Init();

	//データロード
	void Load(int Hndl);

	//描画
	void Draw();

	//毎フレーム行う処理
	void Step(CShotManager& cShotManager, CEnemyManager& cEnemyManager);

	//後処理
	void Exit();

	//タレット設置処理
	void TurretSpawn(const VECTOR &vPos);

	//タレット弾発射処理

	//タレット強化
	void Turret_Power_Up();

};
