#pragma once
#include "../Base/Base.h"
#include "../GamePad/GamePad.h"

enum PLAYER_STATE
{
	STATE_NONE = 0,
	STATE_DEFAULT,	//待機モーション
	STATE_RUN,		//走りモーション
	STATE_SHOT,		//走撃ちモーション
};

//アタッカークラス
class CPlayer : public CBase
{
private:
	VECTOR cNextPos;
	PLAYER_STATE Id;
	PLAYER_STATE oldId;

	DINPUT_JOYSTATE pad;

	void Default();
	void Run();
	void RunShot();

public:
	VECTOR GetNextPos() { return cNextPos; }

	//コンストラクタ・デストラクタ
	CPlayer();
	~CPlayer();

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
