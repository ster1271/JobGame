#pragma once
#include "../Common.h"
#include "effekseer.h"

enum EffectID
{
	EFFECTORID_EXPLOSION = 0,

	EFFECTID_NUM,			//エフェクト総数
};

class CEffectManager
{

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

	int Hndl;

public:
	static void Create();				//インスタンスの生成

	static void Destroy();				//インスタンスの削除

	static CEffectManager* GetInstance();		//インスタンスの取得

	void Init();

	void UpData(VECTOR vForcus, VECTOR fRot, VECTOR vUp);

	bool Load();

	void Reqest(int ID, VECTOR EffectPos, bool IsLoop);

	void Draw();
};


