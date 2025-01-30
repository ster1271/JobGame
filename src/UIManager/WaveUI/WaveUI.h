#pragma once
#include "../UIBase/BaseUI.h"
#include "../../DrawFont/DrawNumberFont.h"
#include "../../Wave/Wave.h"


class CWaveUI : public CUIBase
{
private:
	int BgHndl;
	int StartHndl;
	int ClearHndl;
	int num;
	int ChangeCount;

public:
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

