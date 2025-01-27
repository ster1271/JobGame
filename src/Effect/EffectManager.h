#pragma once


class CEffectManager
{
public:
	enum EffectID
	{
		EFFECTORID_NONE = 0,

		EFFECTID_NUM,			//エフェクト総数
	};

private:
	//コンストラクタ・デストラクタ
	CEffectManager();
	~CEffectManager();

	static CEffectManager* cInstance;		//インスタンス

public:
	static void Create();				//インスタンスの生成

	static void Destroy();				//インスタンスの削除

	static CEffectManager* GetInstance();		//インスタンスの取得


};


