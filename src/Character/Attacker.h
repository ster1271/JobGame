#pragma once
#include "../Base/Base.h"

enum PLAYER_STATE
{
	STATE_NONE = 0,
	STATE_DEFAULT,	//待機モーション
	STATE_RUN,		//走りモーション
	STATE_SHOT,		//走撃ちモーション
};

//アタッカークラス
class CAttacker : public CBase
{
private:
	PLAYER_STATE Id;
	PLAYER_STATE oldId;

	void Default();
	void Run();
	void RunShot();

public:
	//コンストラクタ・デストラクタ
	CAttacker();
	~CAttacker();

	//初期化
	void Init();

	//データ読み込み
	void Load();

	//毎フレーム行う処理
	void Step(CShotManager& cShotManager, CTurretManager& cTurretManager);

	//描画
	void Draw();

	//終了処理
	void Exit();
};
