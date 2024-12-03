#pragma once
#include "../../Common.h"

const VECTOR GOAL_SIZE = VGet(70.0f, 50.0f, 50.0f);


class CGoal
{
private:
	VECTOR cPos;		//座標
	VECTOR cRotate;		//回転値
	VECTOR cSize;		//サイズ

	int iHndl;			//モデルハンドル
	bool IsActive;		//フラグ

public:
	//コンストラクタ・デストラクタ
	CGoal();
	~CGoal();

	//初期化
	void Init();

	//読み込み関連
	void Load();

	//描画
	void Draw();

	//毎フレーム行う処理
	virtual void Step();

	//更新処理
	void Update();

	//後処理
	void Exit();

	//座標取得
	VECTOR GetPos() { return cPos; }

	//サイズ取得
	VECTOR GetSize() { return cSize; }

	//回転地取得
	VECTOR GetRotate() { return cRotate; }
};
