#pragma once
#include <DxLib.h>
#include "math.h"
#include "../Input/Input.h"
#include "../Shot/ShotManager.h"
#include "../Turret/TurretManager.h"

//ヒューマンベースクラス
class CBase
{
protected:
	VECTOR cPos;		//座標
	VECTOR cSize;		//サイズ
	VECTOR cRotate;		//回転値

	float Life;			//ライフ
	int iHndl;			//ハンドル

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
	virtual void Step(CShotManager& cShotManager, CTurretManager& cTurretManager) = 0;

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
