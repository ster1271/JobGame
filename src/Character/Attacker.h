#pragma once
#include "../Base/Base.h"

enum ANIME_STATE
{
	ANIMEID_DEFAULT = 0,//デフォルト(今はTポーズ)
	ANIMEID_WALK,		//歩き
	ANIMEID_RUNSHOT,	//走り撃ち


	ANIME_NUM,			//アニメーションの総数
};

//アタッカークラス
class CAttacker : public CBase
{
private:
	int ID;
	void Default() {};
	void Walk() {};
	void RunShot() {};
public:
	//コンストラクタ・デストラクタ
	CAttacker();
	~CAttacker();

	//初期化
	void Init();

	//データ読み込み
	void Load();

	//毎フレーム行う処理
	void Step(CShotManager& cShotManager, CTurretManager& cTurretManager);

	//描画
	void Draw();

	//終了処理
	void Exit();
};
