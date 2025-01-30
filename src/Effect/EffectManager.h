#pragma once
#include "../Common.h"
#include "effekseer.h"

enum EffectID
{
	EFFECTORID_EXPLOSION = 0,

	EFFECTID_NUM,			//�G�t�F�N�g����
};

class CEffectManager
{

private:
	//�R���X�g���N�^�E�f�X�g���N�^
	CEffectManager();
	~CEffectManager();

	static CEffectManager* cInstance;		//�C���X�^���X

	static int m_iHndl[EFFECTID_NUM];		//�T�E���h�n���h��

	VECTOR vRot;
	VECTOR vEyePos;
	float fNear;
	float fFar;
	float fPars;

	int Hndl;

public:
	static void Create();				//�C���X�^���X�̐���

	static void Destroy();				//�C���X�^���X�̍폜

	static CEffectManager* GetInstance();		//�C���X�^���X�̎擾

	void Init();

	void UpData(VECTOR vForcus, VECTOR fRot, VECTOR vUp);

	bool Load();

	void Reqest(int ID, VECTOR EffectPos, bool IsLoop);

	void Draw();
};


