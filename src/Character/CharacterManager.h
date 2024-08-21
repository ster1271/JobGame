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

	//メインキャラID設定
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
			return /*cAttacker.GetPos()*/ VGet(100.0f, 100.0f, 100.0f);
		else if (MainID == MainID_SUPPORT)
			return/*cAttacker.GetPos()*/VGet(200.0f, 200.0f, 200.0f);
	}

};
