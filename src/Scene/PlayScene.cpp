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
		Draw();
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
	//オブジェクト描画
	cObjectManager.Draw();
	//キャラクター描画
	cCharacterManager.Draw();
	//エネミー描画
	cEnemyManager.Draw();
	//タレット描画
	cTurretManager.Draw();
	//弾描画
	cShotManager.Draw();
	//ボット描画
	cBot.Draw();

	//カメラ情報表示
	cCameraManager.Draw();
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
	//キャラクター初期化
	cCharacterManager.Init();
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
	//キャラクターマネージャー終了処理
	cCharacterManager.Exit();
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
	//キャラクターデータ読み込み
	cCharacterManager.Load();
	//エネミーデータ読み込み
	cEnemyManager.Load();
	//タレットデータ読み込み
	cTurretManager.Load();
	//弾データ読み込み
	cShotManager.Load();
	//ボットデータ読み込み
	cBot.Load();
}


//-----------------------------------
//毎フレーム呼ぶ処理
//-----------------------------------
void CPlayScene::Step()
{
	

	//シーン遷移処理(仮)
	if (CInput::IsKeyPush(KEY_INPUT_RETURN))
	{
		eSceneID = PLAY_SCENE_END;
	}

	//カメラ視点切り替え
	if (cCameraManager.GetCameraID() == CCameraManager::CAMERA_ID_PALY)
	{
		//メインキャラ視点変更
		if (CInput::IsKeyPush(KEY_INPUT_UP))
		{
			cCharacterManager.SetMainID(MainID_ATTACKER);
		}
		else if (CInput::IsKeyPush(KEY_INPUT_DOWN))
		{
			//cCharacterManager.SetMainID(MainID_TANK);
			cCharacterManager.SetMainID(MainID_SUPPORT);
		}

		//オブジェクト更新処理
		cObjectManager.Step();
		//キャラクター更新処理
		cCharacterManager.Step();
		//エネミー更新処理
		cEnemyManager.Step();
		//タレット更新処理
		cTurretManager.Step(cCharacterManager.GetPosition());
		//弾更新処理
		cShotManager.Step(cCharacterManager.GetPosition());
		//ボット更新処理
		cBot.Step(cCharacterManager.GetPosition());
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
	cCameraManager.Step(cCharacterManager.GetPosition(), cCharacterManager.GetRotate());
}

