#pragma once
#include <DxLib.h>
#include <iostream>
#include <vector>
#include <list>
#include "../Turret/TurretBase.h"
#include "../Turret/Turret_Normal.h"

using namespace std;

//タレットマネージャークラス
class CTurretManager
{
private:
	//モデルのコピー元
	int Org_Hndl;
	
	//CTurretBase型のList配列
	vector<CTurretBase*> Turret_List;

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
	void Step(CShotManager& cShotManager ,VECTOR PlayerPos);
	//更新処理
	void Update();
	//描画処理
	void Draw();

	//タレット設置処理
	void TurretSpawn(const VECTOR& vPos);
};