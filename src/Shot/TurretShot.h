#pragma once
#include "../Shot/ShotBase.h"

class CTurretShot:public CShotBase
{
private:


public:
	//コンストラクタ・デストラクタ
	CTurretShot();
	~CTurretShot();

	//初期化
	void Init();

	//読み込み
	void Load(int iMdlHndl);

	//描画
	void Draw();

	//毎フレーム行う処理
	void Step(VECTOR TurretPos);

	//リクエスト
	bool RequestShot(const VECTOR& vPos, const VECTOR& vSpeed);
};
