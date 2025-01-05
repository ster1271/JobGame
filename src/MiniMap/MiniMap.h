#pragma once
#include "../Common.h"
#include "../Player/Player.h"
#include "../Enemy/EnemyManager.h"
#include "../Map/MapManager.h"



//ミニマップクラス
class CMiniMap
{
private:

	VECTOR PlayerPos;
	VECTOR MoveVec;
	VECTOR PlayerRot;
	VECTOR PlayerSpd;
	vector<WallInfo> WallInfoList;
	vector<FloarInfo> FloarInfoList;

	int PlayerHndl;

public:
	//コンストラクタ・デストラクタ
	CMiniMap();
	~CMiniMap();

	//初期化
	void Init();

	//データ読み込み
	void Load();

	//描画
	void Draw();

	//毎フレーム行う処理
	void Step(VECTOR vPos, VECTOR vSpd, VECTOR vRot, CMapManager& cMapManager);

	//情報更新
	void UpData();

	//後処理
	void Exit();
};

