#pragma once
#include "../GamePad/GamePad.h"
#include "../HumanBase/HumanBase.h"
#include "../Shot/ShotManager.h"
#include "../Turret/TurretManager.h"

const VECTOR PLAYER_SIZE = VGet(15.0f, 30.0f, 15.0f);
const float SPERE_R = 3.0f;
const float MOVESPEED = 1.0f;
const float ROT_SPEED = 0.05f;


//アニメーション状態
enum PLAYER_STATE
{
	STATE_NONE = 0,
	STATE_DEFAULT,	//待機モーション
	STATE_RUN,		//走りモーション
	STATE_SHOT,		//走撃ちモーション
};

//アタッカークラス
class CPlayer : public CHumanBase
{
private:
	bool IsDir[DIR_NUM];	//方向フラグ
	PLAYER_STATE Id;
	PLAYER_STATE oldId;

	DINPUT_JOYSTATE pad;

	void Default();
	void Run();
	void RunShot();

public:

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
