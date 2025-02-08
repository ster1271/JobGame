#pragma once
#include "../HumanBase/HumanBase.h"
#include "../Mouse/Mouse.h"
#include "../Shot/ShotManager.h"
#include "../Turret/TurretManager.h"
#include "../Wave/Wave.h"
#include "../Effect/EffectManager.h"
#include "../SoundManager/SoundManager.h"
#include "../Debug/DebugString.h"

const VECTOR PLAYER_POS = VGet(50.0f, 0.0f, 50.0f);		//初期座標
const VECTOR PLAYER_SIZE = VGet(15.0f, 30.0f, 15.0f);	//プレイヤーサイズ
const VECTOR PLAYER_SCALE = VGet(0.05f, 0.05f, 0.05f);	//プレイヤースケール
const float SPERE_R = 3.0f;								//半径
const float MOVESPEED = 1.5f;							//通常移動スピード
const float SHOTMOVESPEED = 0.5f;						//射撃中移動スピード
const float ROT_SPEED = 0.05f;							//回転スピード
const int SHOT_COOL_TIME = 15;							//弾の発射間隔
const int PLAYER_MAX_LIFE = 100;						//最大体力


//アニメーション状態
enum PLAYER_STATE
{
	STATE_NONE = 0,
	STATE_DEFAULT,	//待機モーション
	STATE_RUN,		//走りモーション
	STATE_SHOT,		//射撃モーション
};

//アタッカークラス
class CPlayer : public CHumanBase
{
private:
	static CPlayer* cInstance;		//インスタンス

	FILE* fp = nullptr;

	bool IsDir[DIR_NUM];	//方向フラグ
	PLAYER_STATE Id;
	PLAYER_STATE oldId;
	float fSpd;
	int ShotCoolCount;			//弾クールタイム用変数

	vector<VECTOR> LIST;		//設置表示用

	void Default();
	void Run();
	void Shot();

	//コンストラクタ・デストラクタ
	CPlayer();
	~CPlayer();

public:

	static void Create();				//インスタンスの生成

	static void Destroy();				//インスタンスの削除

	static CPlayer* GetInstance();		//インスタンスの取得

	//初期化
	void Init();

	//データ読み込み
	void Load();

	//毎フレーム行う処理
	void Step(CShotManager& cShotManager, CTurretManager& cTurretManager, CMapManager& cMapManager, VECTOR BotPos);

	//描画
	void Draw();

	//終了処理
	void Exit();

	//移動処理
	void Move();

	//発射リクエスト処理
	void PlayerShot(CShotManager& cShotManager);

	//ウェーブ開始処理
	void StartWave();

	//ボットの位置に移動
	void BackBotPosition(VECTOR vPos);

	//タレット設置場所指定
	void SetPlace();

};
