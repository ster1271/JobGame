#include "DxLib.h"
#include "TitleScene.h"
#include "../Input/Input.h"



//-------------------------------------
//コンストラクタ
//-------------------------------------
CTitleScene::CTitleScene()
{
	//とりあえず初期化に移動させる
	eSceneID = TITLE_SCENE_INIT;
}
//-------------------------------------
//デストラクタ
//-------------------------------------
CTitleScene::~CTitleScene()
{
	Exit();
}

//-------------------------------------
//初期化
//-------------------------------------
void CTitleScene::Init()
{
	
}

//-------------------------------------
//ロード
//-------------------------------------
void CTitleScene::Load()
{
	
}


//-------------------------------------
//ループする処理
//-------------------------------------
int CTitleScene::Loop()
{
	int iRet = 0;
	switch (eSceneID)
	{
	case TITLE_SCENE_INIT:
		Init();
		eSceneID = TITLE_SCENE_LAOD;
		break;

	case TITLE_SCENE_LAOD:
		Load();
		eSceneID = TITLE_SCENE_LOOP;
		break;

	case TITLE_SCENE_LOOP:
		Step();

		break;

	case TITLE_SCENE_END:
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
void CTitleScene::Step()
{
	//シーン遷移処理(仮)
	if (CInput::IsKeyPush(KEY_INPUT_RETURN))
	{
		eSceneID = TITLE_SCENE_END;
	}
}

//-------------------------------------
//描画処理
//-------------------------------------
void CTitleScene::Draw()
{
	DrawString(0, 0, "タイトル画面です", GetColor(255, 255, 255));
	DrawString(0, 15, "Enterでシーン移動", GetColor(255, 255, 255));
}

//-------------------------------------
//後処理1
//-------------------------------------
void CTitleScene::Exit()
{
	//シーンIDをINITに戻す
	eSceneID = TITLE_SCENE_INIT;
}
