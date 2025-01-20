#pragma once
#include "../Wave/Wave.h"
#include "WaveUI/WaveUI.h"

//UIマネージャー
class CUIManager
{
private:
	

	CWaveUI cWaveUI;

public:
	//コンストラクタ・デストラクタ
	CUIManager();
	~CUIManager();

	//読み込み
	void Load();

	//描画
	void Draw();
};
