#pragma once
#include <DxLib.h>

//オブジェクトクラス
class CBase
{

public:
	//コンストラクタ・デストラクタ
	CBase();
	~CBase();

	//初期化
	void Init();

	//読み込み関連
	bool Load(const char FILEPATH[]);

	//描画
	void Draw();

	//毎フレーム行う処理
	virtual void Step() = 0;

	//更新処理
	void Update();

	//後処理
	void Exit();

protected:
	VECTOR cPos;		//座標
	VECTOR cSize;		//サイズ
	VECTOR cRotate;		//回転値

	int iHndl;			//ハンドル
};
