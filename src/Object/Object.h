#pragma once
#include "../Common.h"

//オブジェクトクラス
class CObject
{
protected:
	VECTOR cPos;		//座標
	VECTOR cSize;		//サイズ(縦幅、横幅、奥行)
	VECTOR cRotate;		//回転値
	VECTOR cScale;		//倍率
	
	int Org_Hndl;		
	int iHndl;			//ハンドル

	bool IsActive;		//フラグ

public:
	//コンストラクタ・デストラクタ
	CObject();
	~CObject();

	//初期化
	void Init();

	//読み込み関連
	void Load(int Org_Hndl);

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

	//設置処理
	virtual void Set_Point(const VECTOR& vPos);
};
