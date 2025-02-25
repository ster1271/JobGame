#pragma once
#include "../UIBase/BaseUI.h"
#include "../../Player/Player.h"

//ボタン
enum ButtonID
{
	BUTTONID_A,
	BUTTONID_B,
	BUTTONID_X,
	BUTTONID_Y,

	BUTTONID_NUM
};

const char ButtonFileName[BUTTONID_NUM][128] =
{
	"data/UI/button/Button_A.png",
	"data/UI/button/Button_B.png",
	"data/UI/button/Button_X.png",
	"data/UI/button/Bottun_Y.png",
};

class CButtonUI :public CUIBase
{
private:
	int ButtonHndl[BUTTONID_NUM];
	int GaugeFlameHndl;
	int GaugeHndl;
	int CurrentGaugeVol;

public:
	//コンストラクタ・デストラクタ
	CButtonUI();
	~CButtonUI();

	//初期化
	void Init();

	//読み込み
	bool Load();

	//毎フレーム行う処理
	void Step(const int Count);

	//描画
	void Draw();

	//後処理
	void Exit();
};
