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
	cCharacterManager.Draw();

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
	//キャラクター初期化
	cCharacterManager.Init();
}


//-----------------------------------
//終了処理
//-----------------------------------
void CPlayScene::Exit()
{
	//カメラマネージャー終了処理
	cCameraManager.Exit();
	//キャラクターマネージャー終了処理
	cCharacterManager.Exit();
}


//-----------------------------------
//データロード
//-----------------------------------
void CPlayScene::Load()
{
	cCharacterManager.Load();
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

	if (cCameraManager.GetCameraID() == CCameraManager::CAMERA_ID_PALY)
	{
		if (CInput::IsKeyPush(KEY_INPUT_LEFT))
		{
			
		}
		else if (CInput::IsKeyPush(KEY_INPUT_RIGHT))
		{

		}
		cCharacterManager.Step();
	}

	//カメラの切り替え処理
	if (CInput::IsKeyPush(KEY_INPUT_C))
	{
		cCameraManager.ChangeCamera(CCameraManager::CAMERA_ID_DEBUG);
	}
	else if (CInput::IsKeyPush(KEY_INPUT_V))
	{
		cCameraManager.ChangeCamera(CCameraManager::CAMERA_ID_PALY);
	}



	//カメラ更新処理
	/*cCameraManager.Step(cCharacterManager.GetPosition(), VGet(0.0f, 0.0f, 0.0f));*/
}
