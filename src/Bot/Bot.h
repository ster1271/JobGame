#pragma once 
#include "DxLib.h"
#include "../Base/Base.h"

//ボットクラス
class CBot :public CBase
{
private:

public:
	//コンストラクタ・デストラクタ
	CBot();
	~CBot();

	//初期化
	void Init();

	//読み込み
	bool Load();

	//描画
	void Draw();

	//毎フレーム行う処理
	void Step();
};
