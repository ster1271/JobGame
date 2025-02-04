#pragma once
#include "../Wave/Wave.h"
#include "WaveUI/WaveUI.h"
#include "PlayerUI/PlayerUI.h"
#include "EnemyUI/EnemyUI.h"

//UIマネージャー
class CUIManager
{
private:
	CPlayerUI cPlayerUI;
	CWaveUI cWaveUI;
	CEnemyUI cEnemyUI;

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

	//毎フレーム行う処理
	void Step(CEnemyManager& cEnemyManager);
};
