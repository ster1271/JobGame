#pragma once 
#include "DxLib.h"
#include "../Input/Input.h"
#include "../Object/Object.h"

//ボットクラス
class CBot :public CObject
{
private:
	bool IsMove;
	float tmp_dir;
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
	void Step(VECTOR Set_Point);

	//指定の場所に動く処理
	void Move_Bot(VECTOR Set_point);

};
