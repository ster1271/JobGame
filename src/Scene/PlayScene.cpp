#include "PlayScene.h"



//定義関連----------------------------------

//------------------------------------------


//------------------------------------------
//コンストラクタ
//------------------------------------------
CPlayScene::CPlayScene()
{
	//ひとまず初期化にしておく
	eSceneID = PLAY_SCENE_INIT;
}


//------------------------------------------
//デストラクタ
//------------------------------------------
CPlayScene::~CPlayScene()
{
	//念の為
	Exit();
}

//------------------------------------------
//毎フレーム呼ぶ処理
//------------------------------------------
int CPlayScene::Loop()
{
	int iRet = 0;
	switch (eSceneID)
	{
	case PLAY_SCENE_INIT:
		Init();
		eSceneID = PLAY_SCENE_LAOD;
		break;

	case PLAY_SCENE_LAOD:
		Load();
		eSceneID = PLAY_SCENE_LOOP;
		break;

	case PLAY_SCENE_LOOP:
		Step();
		break;

	case PLAY_SCENE_END:
		Exit();
		eSceneID = PLAY_SCENE_INIT;
		iRet = 1;
		break;

	default:
		break;
	}

	return iRet;
}


//-----------------------------------
//更新処理
//-----------------------------------
void CPlayScene::Draw()
{
	//プレイ時処理
	if (cCameraManager.GetCameraID() == CCameraManager::CAMERA_ID_PALY)
	{
		
		//オブジェクト描画
		cObjectManager.Draw();
		//マップ全般描画 
		cMapManager.Draw();
		//キャラクター描画
		cPlayer.Draw();
		//タレット描画
		cTurretManager.Draw();
		//エネミー描画
		cEnemyManager.Draw();
		//弾描画
		cShotManager.Draw();
		//ボット描画
		cBot.Draw();
		//ミニマップ描画
		cMiniMap.Draw();
	}
	else if (cCameraManager.GetCameraID() == CCameraManager::CAMERA_ID_DEBUG)
	{
		//オブジェクト描画
		cObjectManager.Draw();
		//デバック時描画
	}

	//カメラ情報表示
	cCameraManager.Draw();

	CDebugString::GetInstance()->Draw();

}


//-----------------------------------
//初期化
//-----------------------------------
void CPlayScene::Init()
{
	//カメラ初期化
	cCameraManager.Init();
	cCameraManager.SetNearFar(5.0f, 10000.0f);
	//オブジェクト初期化
	cObjectManager.Init();
	//マップ全般初期化
	cMapManager.Init();
	//キャラクター初期化
	cPlayer.Init();
	//エネミー初期化
	cEnemyManager.Init();
	//タレット初期化
	cTurretManager.Init();
	//弾初期化
	cShotManager.Init();
	//ボット初期化
	cBot.Init();

}


//-----------------------------------
//終了処理
//-----------------------------------
void CPlayScene::Exit()
{
	//カメラマネージャー終了処理
	cCameraManager.Exit();
	//オブジェクトマネージャー終了処理
	cObjectManager.Exit();
	//マップ全般終了処理
	cMapManager.Exit();
	//キャラクター終了処理
	cPlayer.Exit();
	//エネミーマネジャー終了処理
	cEnemyManager.Exit();
	//タレットマネージャー終了処理
	cTurretManager.Exit();
	//弾終了処理
	//cShotManager.Exit();
	//ボットクラス終了処理
	cBot.Exit();

}


//-----------------------------------
//データロード
//-----------------------------------
void CPlayScene::Load()
{
	//オブジェクトデータ読み込み
	cObjectManager.Load();
	//マップ全般データ読み込み
	cMapManager.Load();
	//キャラクターデータ読み込み
	cPlayer.Load();
	//エネミーデータ読み込み
	cEnemyManager.Load();
	//タレットデータ読み込み
	cTurretManager.Load();
	//弾データ読み込み
	cShotManager.Load();
	//ボットデータ読み込み
	cBot.Load();
	//ミニマップ描画
	cMiniMap.Load();
}


//-----------------------------------
//毎フレーム呼ぶ処理
//-----------------------------------
void CPlayScene::Step()
{
	//シーン遷移処理(仮)
	if (cBot.GetFinish())
	{
		eSceneID = PLAY_SCENE_END;
	}

	//更新処理
	//プレイ時処理
	if (cCameraManager.GetCameraID() == CCameraManager::CAMERA_ID_PALY)
	{
		//オブジェクト更新処理
		cObjectManager.Step();
		//マップ全般処理 
		cMapManager.Step();
		//ミニマップ描画
		cMiniMap.Step(cPlayer.GetPos(), cPlayer.GetRotate(), cMapManager);
		//キャラクター更新処理
		cPlayer.Step(cShotManager, cTurretManager, cMapManager, cBot.GetPos());
		cPlayer.UpData();
		//エネミー更新処理
		cEnemyManager.Step(cBot, cMapManager);
		//タレット更新処理
		cTurretManager.Step(cShotManager, cEnemyManager);
		//弾更新処理
		cShotManager.Step(cPlayer.GetPos());
		//ボット更新処理
		cBot.Step(cMapManager);



		//=======当たり判定処理==========//
		cCollisionManager.PlayerToMap(cPlayer, cMapManager);
		cCollisionManager.TurretShotToEnemy(cShotManager, cEnemyManager);
		cCollisionManager.PlayerShotToEnemy(cShotManager, cEnemyManager);
		cCollisionManager.PlayerShotToMap(cShotManager, cMapManager);
		cCollisionManager.TurretShotToMap(cShotManager, cMapManager);
		cCollisionManager.PlayerToGoal(cPlayer, cMapManager);
	}

	//デバック時処理
	if (cCameraManager.GetCameraID() == CCameraManager::CAMERA_ID_DEBUG)
	{

	}

	//デバックカメラとの切り替え処理
	if (CInput::IsKeyPush(KEY_INPUT_C))
	{
		cCameraManager.ChangeCamera(CCameraManager::CAMERA_ID_DEBUG);
	}
	else if (CInput::IsKeyPush(KEY_INPUT_V))
	{
		cCameraManager.ChangeCamera(CCameraManager::CAMERA_ID_PALY);
	}

	//カメラ更新処理
	cCameraManager.Step(cPlayer.GetPos(), cPlayer.GetRotate(), VGet(0.0f,0.0f,0.0f));
}

