#pragma once
#include "../Base/Base.h"
#include "../Input/Input.h"

//タンククラス
class CTank : public CBase
{
private:

public:
	//コンストラクタ・デストラクタ
	CTank();
	~CTank();

	//初期化
	void Init();

	//データ読み込み
	void Load();

	//毎フレーム行う処理
	void Step();

	//更新処理
	void Update();

	//描画
	void Draw();

	//終了処理
	void Exit();
};