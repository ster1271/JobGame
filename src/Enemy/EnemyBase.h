#pragma once
#include "../Common.h"
#include "../CollisionManager/Collision/Collision.h"
#include "../Bot/Bot.h"
#include "../RouteSearch/RouteSearch.h"
#include "../SoundManager/SoundManager.h"

const float ENEMY_RADIUS	(10.0f);		//モデルの半径


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
	VECTOR cSize;		//サイズ
	VECTOR cRotate;		//回転値
	VECTOR cSpeed;		//移動速度
	float Radius;		//半径
	int iHndl;			//ハンドル

	float Life;			//ライフ
	int HitCount;		//弾の当たった回数
	bool IsActive;		//生存フラグ

	vector<VECTOR>List;	//座標格納用
	int ListCnt;

public:
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
	virtual void Draw();

	//リクエスト
	virtual bool RequestEnemy(const VECTOR& vPos, const VECTOR& vSpeed);

	//生存判定
	bool GetActive() { return IsActive; }

	//座標取得
	VECTOR GetPosition() { return cPos; }

	//モデルの半径取得
	float GetRadius() {	return ENEMY_RADIUS;}

	//当たり判定の処理
	void HitCalc()
	{
		CSoundManager::Play(CSoundManager::SOUNDID_SE_EXPLORE);
		Life--;
		HitCount++;

		//ライフがなくなったらフラグをおる
		if (Life <= 0)
		{
			HitCount = 0;
			State_Id = STATE_SEARCH;
			List.clear();
			IsActive = false;
		}
	}

	//移動処理
	void Enemy_Move(vector<VECTOR> List, int& Cnt);

};