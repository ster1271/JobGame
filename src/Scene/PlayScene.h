#pragma once

#include "../Input/Input.h"
#include "../CollisionManager/CollisionManager.h"
#include "../Camera/CameraManager.h"
#include "../Shot/ShotManager.h"
#include "../Character/CharacterManager.h"
#include "../Enemy/EnemyManager.h"
#include "../Turret/TurretManager.h"
#include "../Object/ObjectManager.h"
#include "../Bot/Bot.h"

class CPlayScene
{
private:
	enum tagPLAY_SCENE
	{
		PLAY_SCENE_INIT,
		PLAY_SCENE_LAOD,
		PLAY_SCENE_LOOP,
		PLAY_SCENE_END,

		PLAY_SCENE_NUM
	};

	//座標情報格納
	struct PosInfo
	{
		VECTOR PlayerPos;
		VECTOR TurretPos;
	};


	tagPLAY_SCENE eSceneID;
	PosInfo Posinfo;	

	CCameraManager cCameraManager;			//カメラマネージャー
	CShotManager cShotManager;				//ショットマネージャー
	CCharacterManager cCharacterManager;	//キャラクターマネージャー
	CEnemyManager cEnemyManager;			//エネミーマネージャー
	CObjectManager cObjectManager;			//オブジェクトマネージャー
	CTurretManager cTurretManager;			//タレットマネージャー
	CBot cBot;								//ボットクラス
	

public:
	//コンストラクタ・デストラクタ
	CPlayScene();
	~CPlayScene();

	//繰り返し行う処理
	int Loop();

	//描画処理
	void Draw();

private:
	//初期化
	void Init(void);

	//終了処理
	void Exit();

	//データロード
	void Load();

	//毎フレーム呼ぶ処理
	void Step();

};
