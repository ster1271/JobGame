#pragma once


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

public:
	static void Create();				//�C���X�^���X�̐���

	static void Destroy();				//�C���X�^���X�̍폜

	static CEffectManager* GetInstance();		//�C���X�^���X�̎擾


};


