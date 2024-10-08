#include "DxLib.h"
#include "ResultScene.h"
#include "../Input/Input.h"

//-------------------------------------
//コンストラクタ
//-------------------------------------
CResultScene::CResultScene()
{
	//とりあえず初期化に移動させる
	eSceneID = RESULT_SCENE_INIT;
}
//-------------------------------------
//デストラクタ
//-------------------------------------
CResultScene::~CResultScene()
{
	Exit();
}

//-------------------------------------
//初期化
//-------------------------------------
void CResultScene::Init()
{

}

//-------------------------------------
//ロード
//-------------------------------------
void CResultScene::Load()
{
	
}


//-------------------------------------
//ループする処理
//-------------------------------------
int CResultScene::Loop()
{
	int iRet = 0;
	switch (eSceneID)
	{
	case RESULT_SCENE_INIT:
		Init();
		eSceneID = RESULT_SCENE_LAOD;
		break;

	case RESULT_SCENE_LAOD:
		Load();
		eSceneID = RESULT_SCENE_LOOP;
		break;

	case RESULT_SCENE_LOOP:
		Step();
		break;

	case RESULT_SCENE_END:
		Exit();
		iRet = 1;
		break;


	default:
		break;
	}

	return iRet;
}


//-------------------------------------
//中身の処理
//-------------------------------------
void CResultScene::Step()
{
	//シーン遷移処理(仮)
	if (CInput::IsKeyPush(KEY_INPUT_RETURN))
	{
		eSceneID = RESULT_SCENE_END;
	}
}

//-------------------------------------
//描画処理
//-------------------------------------
void CResultScene::Draw()
{
	DrawString(0, 0, "リザルト画面です", GetColor(255, 255, 255));
	DrawString(0, 15, "Enterでシーン移動", GetColor(255, 255, 255));

}

//-------------------------------------
//後処理1
//-------------------------------------
void CResultScene::Exit()
{
	//シーンIDをINITに戻す
	eSceneID = RESULT_SCENE_INIT;
}
