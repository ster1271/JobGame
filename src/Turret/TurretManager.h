#pragma once
#include <DxLib.h>

//タレットマネージャークラス
class CTurretManager
{
private:

public:
	//コンストラクタ・デストラクタ
	CTurretManager();
	~CTurretManager();


	//初期化
	void Init();
	//データロード
	void Load();
	//終了処理
	void Exit();
	//繰り返し行う処理
	void Step(VECTOR Pos);
	//更新処理
	void Update();
	//描画処理
	void Draw();

};