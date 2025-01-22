#pragma once
#include "../UIBase/BaseUI.h"
#include "../../Player/Player.h"

class CPlayerUI :public CUIBase
{
private:
	int LifeHndl;
	int BgHndl;
	float CurrentLife;	//現在ライフ格納
	float PreLife;		//過去ライフ格納
	int Alpha;			//透明度
	int Count;		

public:
	//コンストラクタ・デストラクタ
	CPlayerUI();
	~CPlayerUI();

	//初期化
	void Init();

	//読み込み
	void Load();

	//毎フレーム行う処理
	void Step();

	//描画
	void Draw();

	//後処理
	void Exit();

	//透明度変更
	void Alpha_Change();
};
