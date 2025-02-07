#pragma once
#include <DxLib.h>
#include <iostream>
#include <vector>
#include <list>
#include "../CollisionManager/Collision/Collision.h"
#include "../Turret/TurretBase.h"
#include "../Turret/Turret_Normal.h"

#include "../Wave/Wave.h"

using namespace std;

const char TURRETPLACEPATH[3][128]
{
	"data/Turret/TurretPlace.txt",
};


//タレットマネージャークラス
class CTurretManager
{
private:
	
	//タレット設置場所情報
	struct TurretPlaceInfo
	{
		VECTOR vPos;		//座標
		VECTOR vSize;		//サイズ
		int iHndl;			//モデルハンドル(コピー)
		bool IsInstall;		//設置できるかどうか
	};

	int Turret_Normal_Hndl;				//ノーマルタレットモデルのコピー元
	
	vector<CTurretBase*> Turret_List;	//CTurretBase型のList配列
	vector<TurretPlaceInfo> PlaceList;


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
	void Step(CShotManager& cShotManager, CEnemyManager& cEnemyManager);
	//更新処理
	void Update();
	//描画処理
	void Draw();

	//タレット設置処理
	void TurretSpawn(VECTOR vPos);

	//タレット設置場所読み込み処理
	void LoadTurretSpawn();
};