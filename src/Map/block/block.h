#pragma once
#include "../../Common.h"
#include "../../Object/Object.h"

//ブロッククラス
class CBlock :public CObject
{
private:

public:
	//コンストラクタ・デストラクタ
	CBlock();
	~CBlock();

	//初期化
	void Init();

	//毎フレーム行う
	void Step();

	//後処理
	void Exit();
};