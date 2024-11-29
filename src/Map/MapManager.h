#pragma once
#include "../Common.h"
#include "Map.h"
#include "Goal/Goal.h"

class CMapManager
{
private:
	CMap cMap;
	CGoal cGoal;

public:
	//コンストラクタ・デストラクタ
	CMapManager();
	~CMapManager();

	//初期化
	void Init();

	//読み込み
	void Load();

	//描画
	void Draw();

	//毎フレーム行う処理
	void Step();

	//情報更新
	void Updata();

	//後処理
	void Exit();

	//マップクラス取得
	CMap GetMap() { return cMap; }

	//ゴールクラス取得
	CGoal GetGoal() { return cGoal; }

};
