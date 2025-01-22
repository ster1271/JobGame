#pragma once
#include "../Wave/Wave.h"
#include "WaveUI/WaveUI.h"
#include "PlayerUI/PlayerUI.h"

//UIマネージャー
class CUIManager
{
private:
	CPlayerUI cPlayerUI;
	CWaveUI cWaveUI;

public:
	//コンストラクタ・デストラクタ
	CUIManager();
	~CUIManager();

	//初期化
	void Init();

	//読み込み
	void Load();

	//描画
	void Draw();
};
