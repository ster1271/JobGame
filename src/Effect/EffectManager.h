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



};


