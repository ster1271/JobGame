#include "ResultScene.h"


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
	if (CInput::IsKeyPush(KEY_INPUT_RETURN) || CGamePad::IsPadPush(DX_INPUT_PAD1, BUTTON_Y))
	{
		eSceneID = RESULT_SCENE_END;
	}
}

//-------------------------------------
//描画処理
//-------------------------------------
void CResultScene::Draw()
{
	CDrawFont::Draw(500, 100, FONT_ID_CP_40, "リザルト画面です");
	CDrawFont::Draw(500, 150, FONT_ID_CP_20, "EnterまたはYボタンでシーン移動");
}

//-------------------------------------
//後処理1
//-------------------------------------
void CResultScene::Exit()
{
	//シーンIDをINITに戻す
	eSceneID = RESULT_SCENE_INIT;
}
