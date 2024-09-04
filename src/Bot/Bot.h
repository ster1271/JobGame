#pragma once 
#include "DxLib.h"
#include "../Object/Object.h"

//ボットクラス
class CBot :public CObject
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

	//指定の場所に動く処理
	void Move_Bot();

};
