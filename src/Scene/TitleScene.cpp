#include "DxLib.h"
#include "TitleScene.h"
#include "../Input/Input.h"
#include "../HumanBase/HumanBase.h"

static const char CHARACTER_PATH[] = { "data/character/human.x" };
static const char ENEMY_PATH01[] = { "data/enemy/Enemy01.x" };
static const char ENEMY_PATH02[] = { "data/enemy/Enemy02.x" };
static const char TITLE_PATH[] = { "data/Title/Title.x" };

static const char START_PATH[] = { "data/Title/Start.png" };
static const char ENDTEXT_PATH[] = { "data/Title/endText.png" };

const int WIDTH = 300;
const int HEIGHT = 100;


//-------------------------------------
//コンストラクタ
//-------------------------------------
CTitleScene::CTitleScene()
{
	memset(&TitleInfo, -1, sizeof(Info));
	memset(&CharaInfo, -1, sizeof(Info));
	memset(&Enemy1Info, -1, sizeof(Info));
	memset(&Enemy2Info, -1, sizeof(Info));
	memset(&StartInfo, -1, sizeof(Info));
	memset(&EndInfo, -1, sizeof(Info));

	MouseX = MouseY = 0;

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
	//開始ボタン
	StartInfo.Hndl = -1;
	StartInfo.cPos = VGet(640, 450, 0);
	StartInfo.cRotate = VGet(0.0f, 0.0f, 0.0f);
	StartInfo.cSize = VGet(0.0f, 1.0f, 0.0f);

	//終了ボタン
	EndInfo.Hndl = -1;
	EndInfo.cPos = VGet(640, 600, 0);
	EndInfo.cRotate = VGet(0.0f, 0.0f, 0.0f);
	EndInfo.cSize = VGet(0.0f, 1.0f, 0.0f);

	//タイトル文字
	TitleInfo.Hndl = -1;
	TitleInfo.cPos = VGet(640.0f, 450.0f, 0.0f);
	TitleInfo.cRotate = VGet(0.0f, DX_PI_F / 2, 0.0f);
	TitleInfo.cSize = VGet(2.0f, 2.0f, 2.0f);

	//キャラクター
	CharaInfo.Hndl = -1;
	CharaInfo.cPos = VGet(100.0f, 360.0f, 0.0f);
	CharaInfo.cRotate = VGet(0.0f, 0.0f, 0.0f);
	CharaInfo.cSize = VGet(0.05f, 0.05f, 0.05f);

	MouseX = MouseY = 0;

}

//-------------------------------------
//ロード
//-------------------------------------
void CTitleScene::Load()
{
	StartInfo.Hndl = LoadGraph(START_PATH);
	EndInfo.Hndl = LoadGraph(ENDTEXT_PATH);

	TitleInfo.Hndl = MV1LoadModel(TITLE_PATH);
	CharaInfo.Hndl = MV1LoadModel(CHARACTER_PATH);
	Enemy1Info.Hndl = MV1LoadModel(ENEMY_PATH01);
	Enemy2Info.Hndl = MV1LoadModel(ENEMY_PATH02);

	AllUpdata();
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
	//マウスの座標取得
	GetMousePoint(&MouseX, &MouseY);

	if (Within_Range(StartInfo.cPos))
	{
		StartInfo.cSize.y = 1.5f;

		if (CMouse::IsMousePush(MOUSE_INPUT_LEFT))
		{
			eSceneID = TITLE_SCENE_END;
		}
	}
	else
	{
		StartInfo.cSize.y = 1.0f;
	}

	if (Within_Range(EndInfo.cPos))
	{
		EndInfo.cSize.y = 1.5f;

		if (CMouse::IsMousePush(MOUSE_INPUT_LEFT))
		{
			exit(0);
		}
	}
	else
	{
		EndInfo.cSize.y = 1.0f;
	}

	

	AllUpdata();
}

//情報更新
void CTitleScene::AllUpdata()
{
	Updata(TitleInfo);
	Updata(CharaInfo);
	Updata(Enemy1Info);
	Updata(Enemy2Info);
}

//情報更新
void CTitleScene::Updata(Info info)
{
	MV1SetPosition(info.Hndl, info.cPos);		//座標の更新
	MV1SetScale(info.Hndl, info.cSize);			//サイズの更新
	MV1SetRotationXYZ(info.Hndl, info.cRotate);	//回転値の更新
}

//-------------------------------------
//描画処理
//-------------------------------------
void CTitleScene::Draw()
{
	MV1DrawModel(TitleInfo.Hndl);
	//MV1DrawModel(CharaInfo.Hndl);
	MV1DrawModel(Enemy1Info.Hndl);
	MV1DrawModel(Enemy2Info.Hndl);

	DrawRotaGraph(StartInfo.cPos.x, StartInfo.cPos.y, StartInfo.cSize.y, 0.0f, StartInfo.Hndl, true, false, false);
	DrawRotaGraph(EndInfo.cPos.x, EndInfo.cPos.y, EndInfo.cSize.y, 0.0f, EndInfo.Hndl, true, false, false);
}

//-------------------------------------
//後処理1
//-------------------------------------
void CTitleScene::Exit()
{
	memset(&TitleInfo, -1, sizeof(Info));
	memset(&CharaInfo, -1, sizeof(Info));
	memset(&Enemy1Info, -1, sizeof(Info));
	memset(&Enemy2Info, -1, sizeof(Info));
	memset(&StartInfo, -1, sizeof(Info));
	memset(&EndInfo, -1, sizeof(Info));

	//シーンIDをINITに戻す
	eSceneID = TITLE_SCENE_INIT;
}


//マウス範囲内判定
bool CTitleScene::Within_Range(VECTOR vPos)
{
	if (MouseX < vPos.x + WIDTH / 2 && MouseX > vPos.x - WIDTH / 2)
	{
		if (MouseY < vPos.y + HEIGHT / 2 && MouseY > vPos.y - HEIGHT / 2)
		{
			return true;
		}
	}

	return false;
}

