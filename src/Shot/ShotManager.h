#pragma once
#include "PlayerShot.h"
#include "TurretShot.h"
#include "../SoundManager/SoundManager.h"

#define PL_SHOT_NUM	(5)
#define TURRET_SHOT_NUM	(10)

class CShotManager
{
private:
	int PlayerHndl;
	int TurretHndl;
	int Count;

	CPlayerShot cPlayerShot[PL_SHOT_NUM];
	CTurretShot cTurretShot[TURRET_SHOT_NUM];

public:
	//コンストラクタ・デストラクタ
	CShotManager();
	~CShotManager();

	//初期化
	void Init();
	//データロード
	void Load();
	//終了処理
	void Exit();
	//繰り返し行う処理
	void Step(VECTOR Pos);

	//描画処理
	void Draw();

	//タレット弾情報取得
	CTurretShot& GetTurretShotInfo(int Index) { return cTurretShot[Index]; }

	//プレイヤー弾情報取得
	CPlayerShot& GetPlayerShotInfo(int Index) { return cPlayerShot[Index]; }

	//プレイヤーのショットリクエスト
	void RequestPlayerShot(const VECTOR& vPos, const VECTOR& vSpeed);

	//タレットのショットリクエスト
	void RequestTurretShot(const VECTOR& vPos, const VECTOR& vSpeed);
};