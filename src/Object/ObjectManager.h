#pragma once
#include "../Object/Sky/Sky.h"
#include "../Object/Ground/Ground.h"


//オブジェクトマネージャークラス
class CObjectManager
{
private:
	CSky cSky;			//天球クラス
	CGround cGround;	//マップクラス

public:
	//コンストラクタ・デストラクタ
	CObjectManager();
	~CObjectManager();

	//初期化
	void Init();

	//読み込み関連
	void Load();

	//描画
	void Draw();

	//毎フレーム行う処理
	void Step();

	//更新処理
	void Update();

	//後処理
	void Exit();
};
