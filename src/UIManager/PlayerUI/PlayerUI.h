#pragma once
#include "../UIBase/BaseUI.h"

class CPlayerUI :public CUIBase
{
private:
	int HPHndl;
	 

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
};
