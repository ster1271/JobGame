#pragma once
#include "effekseer.h"

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

	static int m_iHndl[EFFECTID_NUM];		//サウンドハンドル

	VECTOR vRot;
	VECTOR vEyePos;
	float fNear;
	float fFar;
	float fPars;

public:
	static void Create();				//インスタンスの生成

	static void Destroy();				//インスタンスの削除

	static CEffectManager* GetInstance();		//インスタンスの取得

	void Init();

	void UpData();

	bool Load();

	void Draw();
};


