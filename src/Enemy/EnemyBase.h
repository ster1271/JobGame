#pragma once
#include "../Common.h"
#include "../Bot/Bot.h"
#include "../RouteSearch/RouteSearch.h"
#include "../SoundManager/SoundManager.h"
#include "../Debug/DebugString.h"

const float ENEMY_RADIUS(10.0f);		//モデルの半径


//敵方向
enum ENEMY_DIR
{
	ENEMY_DIR_RIGHT = 0,	//右
	ENEMY_DIR_LEFT,		//左
	ENEMY_DIR_UP,			//上
	ENEMY_DIR_DOWN,		//下
	ENEMY_DIR_BACK,		//奥
	ENEMY_DIR_NEAR,		//手前

	ENEMY_DIR_NUM,		//総番号
};


class CEnemyBase
{
protected:
	enum ENEMY_STATE
	{
		STATE_SEARCH = 0,	//経路探索
		STATE_MOVE,			//移動
		STATE_ATTACK,		//攻撃

		STATE_NUM,
	};

	ENEMY_STATE State_Id;

	VECTOR cPos;		//座標
	VECTOR cNextPos;	//1フレーム後の座標
	VECTOR cScale;		//サイズ(倍率)
	VECTOR cSize;		//サイズ(縦幅、横幅、奥行)
	VECTOR cRotate;		//回転値
	VECTOR cSpeed;		//移動速度
	float Radius;		//半径
	int iHndl;			//ハンドル

	float Life;			//ライフ
	int HitCount;		//弾の当たった回数
	bool IsActive;		//生存フラグ

	bool IsDir[ENEMY_DIR_NUM];	//方向フラグ

	vector<VECTOR>List;	//座標格納用
	int ListCnt;

public:
	VECTOR GetPosition() { return cPos; }						//座標取得
	VECTOR GetNextPosision() { return cNextPos; }				//座標取得
	void SetNextPosision(VECTOR NewPos) { cNextPos = NewPos; }	//座標設定
	bool GetDir(int dir) { return IsDir[dir]; }					//方向フラグ取得

	//コンストラクタ・デストラクタ
	CEnemyBase();
	~CEnemyBase();

	//初期化
	void Init();

	//データロード
	void Load(int iMdlHndl);

	//終了処理
	void Exit();

	//毎フレーム呼ぶ処理
	virtual void Step();

	//更新処理
	void Update();

	//描画処理
	void Draw();

	//リクエスト
	virtual bool RequestEnemy(const VECTOR& vPos, const VECTOR& vSpeed);

	bool GetActive() { return IsActive; }						//生存判定

	float GetRadius() {	return ENEMY_RADIUS;}					//モデルの半径取得

	//当たり判定の処理
	void HitCalc()
	{
		Life--;
		HitCount++;

		//ライフがなくなったらフラグをおる
		if (Life <= 0)
		{
			//ひとまず初期化
			/*memset(&cPos, 0, sizeof(VECTOR));
			memset(&cNextPos, 0, sizeof(VECTOR));
			memset(&cRotate, 0, sizeof(VECTOR));
			memset(&cScale, 0, sizeof(VECTOR));
			memset(&cSize, 0, sizeof(VECTOR));
			memset(&cSpeed, 0, sizeof(VECTOR));*/
			iHndl = -1;

			HitCount = 0;
			State_Id = STATE_NUM;
			List.clear();
			IsActive = false;
		}
	}

	//経路移動処理
	void Enemy_Move(vector<VECTOR> List, int& Cnt);

	//自動追尾処理
	void Out_Move(VECTOR vPos);

	//方向フラグ設定
	void SetDir();


};