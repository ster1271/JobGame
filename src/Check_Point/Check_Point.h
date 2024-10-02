#pragma once
#include <DxLib.h>
#include "BaseCheck.h"

class CCheck_Point : public CBase_Check
{
private:
	int tmp_Hndl;

public:
	//コンストラクタ・デストラクタ
	CCheck_Point();
	~CCheck_Point();

	//初期化
	void Init();

	//モデル読み込み
	void Load();

	//描画
	void Draw();

	//毎フレーム行う処理
	void Step();

	//後処理
	void Exit();

	//設置処理
	void Set_Point(const VECTOR vPos);

};
