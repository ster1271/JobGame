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
	//ボット描画
	cBot.Draw();

	DrawString(0, 0, "プレイ画面です", GetColor(255, 255, 255));
	DrawString(0, 15, "Enterでシーン移動", GetColor(255, 255, 255));
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

		//視点位置変更(アングルを変更する)
		if (CInput::IsKeyKeep(KEY_INPUT_LEFT))
		{

		}
		else if (CInput::IsKeyPush(KEY_INPUT_DOWN))
		{

		}

		//オブジェクト更新処理
		cObjectManager.Step();
		//キャラクター更新処理
		cCharacterManager.Step();
		//ボット更新処理
		cBot.Step();
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
	cCameraManager.Step(cCharacterManager.GetPosition(), VGet(0.0f, 0.0f, 0.0f));
}
