#pragma once
#include "../Wave/Wave.h"

//UIマネージャー
class CUIManager
{
private:
	static CUIManager* cInstance;		//インスタンス

	//コンストラクタ・デストラクタ
	CUIManager();
	~CUIManager();

	int hnd;

public:

	static void Create();				//インスタンスの生成

	static void Destroy();				//インスタンスの削除

	static CUIManager* GetInstance();	//インスタンスの取得

	//描画
	void Draw();
};
