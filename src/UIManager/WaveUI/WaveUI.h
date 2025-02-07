#pragma once
#include "../UIBase/BaseUI.h"
#include "../../DrawNumberFont/DrawNumberFont.h"
#include "../../DrawFont/DrawFont.h"
#include "../../Wave/Wave.h"


class CWaveUI : public CUIBase
{
private:
	int BgHndl;
	int Alpha;			//透過値
	int ChangeCount;	//スイッチ分

public:
	//void SetAlpha(int Cnt) { Alpha = Cnt; }	//透過値設定

	//コンストラクタ・デストラクタ
	CWaveUI();
	~CWaveUI();

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

};

