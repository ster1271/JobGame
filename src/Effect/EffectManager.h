#pragma once
#include "effekseer.h"

class CEffectManager
{
public:
	enum EffectID
	{
		EFFECTORID_NONE = 0,

		EFFECTID_NUM,			//�G�t�F�N�g����
	};

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

public:
	static void Create();				//�C���X�^���X�̐���

	static void Destroy();				//�C���X�^���X�̍폜

	static CEffectManager* GetInstance();		//�C���X�^���X�̎擾

	void Init();

	void UpData();

	bool Load();

	void Draw();
};


