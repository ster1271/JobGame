#pragma once
#include <DxLib.h>

//オブジェクトクラス
class CObject
{

public:
	//コンストラクタ・デストラクタ
	CObject();
	~CObject();

	//初期化
	void Init();

	//読み込み関連
	void Load(const char FILEPATH[]);

	//毎フレーム行う処理()
	virtual void Step() = 0;

	//更新処理
	void Updata();

	//後処理
	void Exit();

protected:
	VECTOR cPos;		//座標
	VECTOR cSize;		//サイズ
	VECTOR cRotate;		//回転値

	int iHndl;			//ハンドル
};
