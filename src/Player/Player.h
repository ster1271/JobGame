#pragma once
#include "../Base/Base.h"
#include "../GamePad/GamePad.h"

const VECTOR PLAYER_SIZE = VGet(15.0f, 30.0f, 15.0f);

//アニメーション状態
enum PLAYER_STATE
{
	STATE_NONE = 0,
	STATE_DEFAULT,	//待機モーション
	STATE_RUN,		//走りモーション
	STATE_SHOT,		//走撃ちモーション
};

//プレイヤー方向
enum PLAYER_DIR
{
	DIR_RIGHT = 0,	//右
	DIR_LEFT,		//左
	DIR_UP,			//上
	DIR_DOWN,		//下
	DIR_BACK,		//奥
	DIR_NEAR,		//手前

	DIR_NUM,		//総番号
};

//アタッカークラス
class CPlayer : public CBase
{
private:
	VECTOR cNextPos;		//1フレーム後の座標
	bool IsDir[DIR_NUM];	//方向フラグ
	PLAYER_STATE Id;
	PLAYER_STATE oldId;

	DINPUT_JOYSTATE pad;

	void Default();
	void Run();
	void RunShot();

public:
	
	VECTOR GetNextPos() { return cNextPos; }				//座標の取得
	void SetNextPos(VECTOR NewPos) { cNextPos = NewPos;	}	//座標の設定

	VECTOR GetModelSize() { return PLAYER_SIZE; }			//プレイヤーのサイズ取得

	bool GetDir(int dir) { return IsDir[dir]; }				//方向フラグ取得
	void SetDir();											//方向フラグ設定

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
