#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "Object.h"
#include "Sky/Sky.h"
#include "Ground/Ground.h"

using namespace std;

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

	//ハンドル取得
	int GetHndl() { return cGround.GetHndl(); }

};
