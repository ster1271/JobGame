#pragma once
#include "TurretBase.h"

//タレットクラス(通常)
class CTurret_Normal: public TurretBase
{
private:
	float Attack;
public:
	//コンストラクタ・デストラクタ
	CTurret_Normal();
	~CTurret_Normal();

	//初期化
	void Init();

	//データロード
	void Load(const char FILEPATH[]);

	//描画
	void Draw();

	//毎フレーム行う処理
	void Step();

	//後処理
	void Exit();
};
