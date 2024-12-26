#pragma once

#include "../Input/Input.h"
#include "../CollisionManager/CollisionManager.h"
#include "../Camera/CameraManager.h"
#include "../Shot/ShotManager.h"
#include "../Player/Player.h"
#include "../Enemy/EnemyManager.h"
#include "../Turret/TurretManager.h"
#include "../Object/ObjectManager.h"
#include "../Bot/Bot.h"
#include "../RouteSearch/RouteSearch.h"
#include "../Map/MapManager.h"
#include "../MiniMap/MiniMap.h"

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

	
	tagPLAY_SCENE eSceneID;

	CCameraManager cCameraManager;			//カメラマネージャー
	CShotManager cShotManager;				//ショットマネージャー
	CPlayer cPlayer;						//プレイヤークラス
	CEnemyManager cEnemyManager;			//エネミーマネージャー
	CObjectManager cObjectManager;			//オブジェクトマネージャー
	CTurretManager cTurretManager;			//タレットマネージャー
	CBot cBot;								//ボットクラス
	CRoute_Search cRoute_Search;			//経路探索クラス
	CCollisionManager cCollisionManager;	//コリジョンマネージャー
	CMapManager cMapManager;				//マップマネージャー
	CMiniMap cMiniMap;						//ミニマップクラス
	

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
	void Init();

	//終了処理
	void Exit();

	//データロード
	void Load();

	//毎フレーム呼ぶ処理
	void Step();

};
