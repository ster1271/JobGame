#pragma once
#include "../Common.h"

class CMiniMap
{
private:
	VECTOR cPos;
	int iHndl;

public:
	//コンストラクタ・デストラクタ
	CMiniMap();
	~CMiniMap();

	//初期化
	void Init();
	
	//読み込み
	void Load();

	//毎フレーム行う処理
	void Step();

	//情報更新
	void UpData();

	//後処理
	void Exit();
};