#pragma once
#include <DxLib.h>

class CBase_Check
{
protected:
	VECTOR cPos;		//座標
	VECTOR cSize;		//サイズ
	VECTOR cRotate;		//回転値

	int iHndl;			//ハンドル

	bool IsActive;		//フラグ
public:
	//コンストラクタ・デストラクタ
	CBase_Check();
	~CBase_Check();

	//初期化
	void Init();

	//読み込み
	void Load();

	//描画
	virtual void Draw() = 0;

	//毎フレーム行う処理
	virtual void Step() = 0;

	//情報更新
	void UpData();

	//後処理
	void Exit();
};
