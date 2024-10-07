#pragma once
#include <DxLib.h>
#include <iostream>
#include <vector>
#include <math.h>

//チェックポイントベースクラス
class CCheck_Base
{
protected:
	VECTOR cPos;		//座標
	VECTOR cSize;		//サイズ
	VECTOR cRotate;		//回転値

	int iHndl;			//ハンドル

	bool IsActive;		//フラグ

public:
	//コンストラクタ・デストラクタ
	CCheck_Base();
	~CCheck_Base();

	//初期化
	void Init();

	//データ読み込み
	void Load(int Hndl);

	//後処理
	void Exit();

	//情報更新
	void Updata();

	//描画
	virtual void Draw();

	virtual void Step();

};

