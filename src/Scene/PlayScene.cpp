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
		CPlayer::GetInstance()->Draw();
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
		//エフェクト描画
		CEffectManager::GetInstance()->Draw();
		//UI描画
		cUIManager.Draw();
	}

	//カメラ情報表示
	cCameraManager.Draw();

	//デバック文字表示

	CDebugString::GetInstance()->Draw();
}


//-----------------------------------
//初期化
//-----------------------------------
void CPlayScene::Init()
{
	//カメラ初期化
	cCameraManager.Init();
	//オブジェクト初期化
	cObjectManager.Init();
	//マップ全般初期化
	cMapManager.Init();
	//キャラクター初期化
	CPlayer::GetInstance()->Init();
	//エネミー初期化
	cEnemyManager.Init();
	//タレット初期化
	cTurretManager.Init();
	//弾初期化
	cShotManager.Init();
	//ボット初期化
	cBot.Init();
	//UIマネージャー初期化
	cUIManager.Init();
	//エフェクト初期化
	CEffectManager::GetInstance()->Init();
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
	CPlayer::GetInstance()->Exit();
	//エネミーマネジャー終了処理
	cEnemyManager.Exit();
	//タレットマネージャー終了処理
	cTurretManager.Exit();
	//弾終了処理
	cShotManager.Exit();
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
	CPlayer::GetInstance()->Load();
	//エネミーデータ読み込み
	cEnemyManager.Load();
	//タレットデータ読み込み
	cTurretManager.Load();
	//弾データ読み込み
	cShotManager.Load();
	//ボットデータ読み込み
	cBot.Load();
	//ミニマップ読み込み
	cMiniMap.Load();
	//UI読み込み
	cUIManager.Load();
	//エフェクト読み込み
	CEffectManager::GetInstance()->Load();
}


//-----------------------------------
//毎フレーム呼ぶ処理
//-----------------------------------
void CPlayScene::Step()
{
	//シーン終了処理
	if (cBot.GetFinish())
	{
		eSceneID = PLAY_SCENE_END;
	}

	//更新処理
	//プレイ時処理
	if (cCameraManager.GetCameraID() == CCameraManager::CAMERA_ID_PALY)
	{
		/*CDebugString::GetInstance()->AddFormatString(200, 200, "1200 / %d", CWave::GetInstance()->GetWaveTime());
		CDebugString::GetInstance()->AddFormatString(200, 215, "ウェーブ状態：%d", CWave::GetInstance()->GetWaveState());*/

		//オブジェクト更新処理
		cObjectManager.Step();
		//マップ全般処理 
		cMapManager.Step();
		//ミニマップ描画
		cMiniMap.Step(CPlayer::GetInstance()->GetPos(), CPlayer::GetInstance()->GetSpeed(), CPlayer::GetInstance()->GetRotate(), cMapManager);
		//キャラクター更新処理
		CPlayer::GetInstance()->Step(cShotManager, cTurretManager, cMapManager, cBot.GetPos());
		CPlayer::GetInstance()->UpData();
		
		//エネミー更新処理
		cEnemyManager.Step(cBot.GetPos(), cMapManager);
		//タレット更新処理
		cTurretManager.Step(cShotManager, cEnemyManager);
		//弾更新処理
		cShotManager.Step(CPlayer::GetInstance()->GetPos());
		//ボット更新処理
		cBot.Step(cMapManager);
		//ウェーブ処理
		CWave::GetInstance()->Step();
		//UI処理
		cUIManager.Step(cEnemyManager, CPlayer::GetInstance()->GetPushCnt());

		//=======当たり判定処理==========//
		cCollisionManager.PlayerToMap(cMapManager);
		cCollisionManager.TurretShotToEnemy(cShotManager, cEnemyManager);
		cCollisionManager.PlayerShotToEnemy(cShotManager, cEnemyManager);
		cCollisionManager.PlayerShotToMap(cShotManager, cMapManager);
		cCollisionManager.TurretShotToMap(cShotManager, cMapManager);
		cCollisionManager.PlayerToGoal(cMapManager);
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
	cCameraManager.Step(CPlayer::GetInstance()->GetPos(), CPlayer::GetInstance()->GetRotate(), VGet(0.0f, 1.0f, 0.0f));
	
}

