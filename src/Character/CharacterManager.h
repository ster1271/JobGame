#pragma once
#include "../Character/Attacker.h"

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
	CAttacker cAttacker;


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
	void Step();

	//描画処理
	void Draw();


	//操作キャラの座標取得
	VECTOR GetPosition(MainPlayerID id)
	{
		if (id == MainID_ATTACKER)
			return cAttacker.GetPos();
		else if (id == MainID_TANK)
			return cAttacker.GetPos();
		else if (id == MainID_SUPPORT)
			return cAttacker.GetPos();
	}

};
