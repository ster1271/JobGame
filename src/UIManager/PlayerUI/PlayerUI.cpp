#include "PlayerUI.h"

const char PLAYER_HP_PATH[] = { "data/UI/player/PlayerHP.png" };

//コンストラクタ
CPlayerUI::CPlayerUI(){}

//デストラクタ
CPlayerUI::~CPlayerUI(){}

//初期化
void CPlayerUI::Init()
{
	HPHndl = -1;
}

//読み込み
void CPlayerUI::Load()
{
	HPHndl = LoadGraph(PLAYER_HP_PATH);
}

//毎フレーム行う処理
void CPlayerUI::Step()
{
	
}

//描画
void CPlayerUI::Draw()
{
	int DrawX = 590;
	int DrawY = 290;

	//プレイヤーのライフを取得
	float LIFE = CPlayer::GetInstance()->GetPlayerLife();

	SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, 100);
	DrawRectGraph(DrawX, DrawY, 0, 0, LIFE, 30, HPHndl, true, false);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

//後処理
void CPlayerUI::Exit()
{
	HPHndl = -1;
}