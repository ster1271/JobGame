#pragma once
#include <DxLib.h>

class CGameData
{
public:
	int MaxScore;		//最大スコア
	int CurrentScore;	//現在スコア	

	//プレイヤーデータ
	struct PlayerData
	{
		int MaxHp;		//プレイヤーの最大ライフ
		int CurrentHp;	//プレイヤーの現在ライフ
	};

	
	//階層データ
	struct FloarData
	{
		int MaxFloar;		//最大階層
		int CurrentFloar;	//現在階層
	};


private:
	//CDataクラスのポインタ変数
	static CGameData* cInstance;

	PlayerData cPlayerData;		//プレイヤーデータ
	FloarData cFloarData;		//階層データ


	//最大スコア取得・設定
	int GetMaxScore() { return MaxScore; }
	void SetMaxScore(int Score) { MaxScore = Score; }

	//現在スコア取得・設定
	int GetCurrentScore() { return CurrentScore; }
	void SetCurrentScore(int Score) { CurrentScore = Score; }

	//プレイヤーデータ取得
	PlayerData GetPlayerData() { return cPlayerData; }

	//階層データ取得
	FloarData GetFloarData() { return cFloarData; }


public:
	//コンストラクタ・デストラクタ
	CGameData();
	~CGameData();

	//CGameDataを取得
	static CGameData* GetInstance();

	//CGameDataを削除
	static void DeleteInstance();

};