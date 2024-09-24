#pragma once
#include "../Shot/ShotBase.h"

const int SHOTRADIUS	(1);
const float GRAVITY		(0.01f);

class CShot:public CShotBase
{
private:

public:
	//コンストラクタ・デストラクタ
	CShot();
	~CShot();

	//初期化
	void Init();

	//データロード
	void Load(int iMdlHndl);

	//終了処理
	void Exit();

	//毎フレーム呼ぶ処理
	void Step(VECTOR Pos);

	//描画処理
	void Draw();

	//リクエスト
	bool RequestShot(const VECTOR& vPos, const VECTOR& vSpeed);

	//当たり判定の処理
	void HitCalc()
	{
		//当たったらフラグをおる
		IsActive = false;
	}
};