#pragma once
#include "../GamePad/GamePad.h"
#include "../HumanBase/HumanBase.h"
#include "../Shot/ShotManager.h"
#include "../Turret/TurretManager.h"

const VECTOR PLAYER_POS = VGet(50.0f, 0.0f, 50.0f);
const VECTOR PLAYER_SIZE = VGet(15.0f, 30.0f, 15.0f);
const VECTOR PLAYER_SCALE = VGet(0.05f, 0.05f, 0.05f);
const float SPERE_R = 3.0f;
const float MOVESPEED = 2.0f;
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
	float fSpd;

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

	//コントローラー移動処理
	void Move_CON();

};
