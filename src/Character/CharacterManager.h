#pragma once
#include "../Character/Attacker.h"

class CCharacterManager
{
private:
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

};
