#pragma once
#include "../Enemy/EnemyBase.h"

class CEnemy_Normal: public CEnemyBase
{
private:

public:
	//コンストラクタ・デストラクタ
	CEnemy_Normal();
	~CEnemy_Normal();

	//初期化
	void Init();

	//データロード
	void Load(int Hndl);

	//描画
	void Draw();

	//毎フレーム行う処理
	/*void Step(const VECTOR vPos);*/

	//後処理
	void Exit();

	//リクエスト
	virtual bool RequestEnemy(const VECTOR& vPos, const VECTOR& vSpeed);
};
