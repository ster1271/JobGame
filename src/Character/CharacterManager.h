#pragma once

#include "../Character/Attacker.h"
#include "../Character/Tank.h"
#include "../Character/Support.h"

//自分が操作しているキャラID
enum MainPlayerID
{
	MainID_ATTACKER,
	MainID_TANK,
	MainID_SUPPORT,

	ID_NUM
};

class CCharacterManager
{
private:
	MainPlayerID MainID;

	CAttacker cAttacker;			//アタッカークラス
	CTank cTank;					//タンククラス
	CSupport cSupport;				//サポートクラス



public:
	//コンストラクタ・デストラクタ
	CCharacterManager();
	~CCharacterManager();

	//初期化
	void Init();

	//データロード
	void Load();

	//終了処理
	void Exit();

	//毎フレーム呼ぶ処理
	void Step(CShotManager& cShotManager,  CTurretManager& cTurretManager);

	//描画処理
	void Draw();

	//メインキャラID設定(未変更)
	void SetMainID(MainPlayerID Id)
	{
		MainID = Id;
	}


	//操作キャラの座標取得
	VECTOR GetPosition()
	{
		if (MainID == MainID_ATTACKER)
			return cAttacker.GetPos();
		else if (MainID == MainID_TANK)
			return cTank.GetPos();
		else if (MainID == MainID_SUPPORT)
			return cSupport.GetPos();
	}

	//操作キャラの角度取得
	VECTOR GetRotate()
	{
		if (MainID == MainID_ATTACKER)
			return cAttacker.GetRotate();
		else if (MainID == MainID_TANK)
			return cTank.GetRotate();
		else if (MainID == MainID_SUPPORT)
			return cSupport.GetRotate();
	}

};
