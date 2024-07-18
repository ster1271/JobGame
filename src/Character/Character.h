#pragma once
#include <DxLib.h>


class CCharacter
{
public:
	//コンストラクタ・デストラクタ
	CCharacter();
	~CCharacter();

	//初期化
	void Init();

	//読み込み関連
	virtual void Load() = 0;

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
