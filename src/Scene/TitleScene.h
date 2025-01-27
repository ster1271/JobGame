#pragma once
#include "../Common.h"
#include "../Mouse/Mouse.h"

enum tagTITLE_SCENE
{
	TITLE_SCENE_INIT,
	TITLE_SCENE_LAOD,
	TITLE_SCENE_LOOP,
	TITLE_SCENE_END,

	TITLE_SCENE_NUM
};

class CTitleScene
{
private:
	tagTITLE_SCENE eSceneID;

	struct Info
	{
		int Hndl;			//ハンドル
		VECTOR cPos;		//座標
		VECTOR cRotate;		//回転値
		VECTOR cSize;		//拡大率
	};

	Info TitleInfo;
	Info CharaInfo;
	Info Enemy1Info;
	Info Enemy2Info;
	Info StartInfo;
	Info EndInfo;

	int MouseX, MouseY;

public:
	//コンストラクタ・デストラクタ
	CTitleScene();
	~CTitleScene();

	//初期化
	void Init();

	//読み込み
	void Load();

	//ループ処理
	int Loop();

	//中身の処理
	void Step();

	//情報更新
	void AllUpdata();

	//情報更新
	void Updata(Info info);

	//描画処理
	void Draw();

	//後処理
	void Exit();

	//マウス範囲内判定
	bool Within_Range(VECTOR vPos);
};
