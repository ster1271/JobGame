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
		//キャラクター描画
		cCharacterManager.Draw();
		//エネミー描画
		//cEnemyManager.Draw();
		//タレット描画
		//cTurretManager.Draw();
		//弾描画
		//cShotManager.Draw();
		//ボット描画
		cBot.Draw();
		//チェックポイント描画
		cCheck_Manager.Draw();

		cRoute_Search.Draw();
	}
	else if (cCameraManager.GetCameraID() == CCameraManager::CAMERA_ID_DEBUG)
	{
		//オブジェクト描画
		cObjectManager.Draw();
		//デバック時描画
		cCheck_Manager.DebugDraw();

		cGame_Pointer.Draw(cCheck_Manager.GetID());
	}

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
	//チェックポイント初期化
	cCheck_Manager.Init();

	cGame_Pointer.Init();

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
	//チェックポイント終了処理
	cCheck_Manager.Exit();

	cGame_Pointer.Exit();

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
	//チェックポイントデータ読み込み
	cCheck_Manager.Load();

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

	//更新処理
	//プレイ時処理
	if (cCameraManager.GetCameraID() == CCameraManager::CAMERA_ID_PALY)
	{
		//メインキャラ視点変更
		if (CInput::IsKeyPush(KEY_INPUT_UP))
		{
			//メインキャラへ変更
			cCharacterManager.SetMainID(MainID_ATTACKER);
		}
		//else if (CInput::IsKeyPush(KEY_INPUT_DOWN))
		//{
		//	//CPUキャラへ変更
		//	//cCharacterManager.SetMainID(MainID_TANK);
		//	cCharacterManager.SetMainID(MainID_SUPPORT);
		//}

		//オブジェクト更新処理
		cObjectManager.Step();
		//キャラクター更新処理
		cCharacterManager.Step(cShotManager, cTurretManager);
		//エネミー更新処理
		cEnemyManager.Step();
		//タレット更新処理
		cTurretManager.Step(cShotManager, cCharacterManager.GetPosition());
		//弾更新処理
		cShotManager.Step(cCharacterManager.GetPosition());
		//ボット更新処理
		cBot.Step(cRoute_Search);
		//チェックポイント更新処理
		cCheck_Manager.Step();
	}

	//デバック時処理
	if (cCameraManager.GetCameraID() == CCameraManager::CAMERA_ID_DEBUG)
	{
		cGame_Pointer.Step(cCheck_Manager.GetID());

		//デバック時更新処理
		cCheck_Manager.DebugStep(cGame_Pointer.GetPos());
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
	cCameraManager.Step(cCharacterManager.GetPosition(), cCharacterManager.GetRotate(), cGame_Pointer.GetPos());
}

