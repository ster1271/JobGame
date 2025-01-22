#include "PlayerUI.h"

const char PLAYER_LIFE_PATH[] = { "data/UI/player/PlayerLife.png" };
const char PLAYER_LIFEBACK_PATH[] = { "data/UI/player/LifeBack.png" };

const int DRAW_X = 590;
const int DRAW_Y = 290;

//コンストラクタ
CPlayerUI::CPlayerUI(){}

//デストラクタ
CPlayerUI::~CPlayerUI(){}

//初期化
void CPlayerUI::Init()
{
	LifeHndl = -1;
	BgHndl = -1;
	CurrentLife = 0;
	PreLife = 0;
	Alpha = 0;
	Count = 0;
}

//読み込み
void CPlayerUI::Load()
{
	LifeHndl = LoadGraph(PLAYER_LIFE_PATH);
	BgHndl = LoadGraph(PLAYER_LIFEBACK_PATH);
}

//毎フレーム行う処理
void CPlayerUI::Step()
{
	//過去ライフに格納
	PreLife = CurrentLife;
	//プレイヤーの現在ライフを取得
	CurrentLife = CPlayer::GetInstance()->GetPlayerLife();

	//透明度変更
	Alpha_Change();
}

//描画
void CPlayerUI::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, Alpha);
	DrawRectGraph(DRAW_X, DRAW_Y, 0, 0, PLAYER_MAX_LIFE, 30, BgHndl, true, false);
	DrawRectGraph(DRAW_X, DRAW_Y, 0, 0, CurrentLife, 30, LifeHndl, true, false);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

//後処理
void CPlayerUI::Exit()
{
	LifeHndl = -1;
	CurrentLife = 0;
	PreLife = 0;
	Alpha = 0;
	Count = 0;
}


//透明度変更
void CPlayerUI::Alpha_Change()
{
	//ライフが同じなら
	if (CurrentLife == PreLife)
	{
		//カウント増加
		Count++;
	}
	else
	{
		Alpha = 200;
		Count = 0;
	}

	if (Count > 100)
	{
		//透明度を下げる
		Alpha -= 2;
		if (Alpha < 0)
		{
			Alpha = 0;
			Count = 0;
		}
	}
}