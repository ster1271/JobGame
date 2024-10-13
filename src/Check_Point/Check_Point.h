#pragma once
#include <DxLib.h>
#include <iostream>
#include <vector>
#include "../Check_Point/Check_Base.h"

#define  MAX_NUM	(10)

using namespace std;

class CCheck_Point: public CCheck_Base
{
private:

public:
	//コンストラクタ・デストラクタ
	CCheck_Point();
	~CCheck_Point();

	//初期化
	void Init();

	//モデル読み込み
	void Load(int Hndl);

	//描画
	void Draw();

	//毎フレーム行う処理
	void Step();

	//後処理
	void Exit();

	//設置処理
	void Set_Point(const VECTOR vPos);



};

