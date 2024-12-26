#pragma once
#include "../Common.h"

//ミニマップクラス
class CMiniMap
{
private:


public:
	//コンストラクタ・デストラクタ
	CMiniMap();
	~CMiniMap();

	//初期化
	void Init();

	//データ読み込み
	void Load();

	//描画
	void Draw();

	//毎フレーム行う処理
	void Step();

	//情報更新
	void UpData();

	//後処理
	void Exit();
};

