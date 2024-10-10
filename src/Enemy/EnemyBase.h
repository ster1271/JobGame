#pragma once
#include <DxLib.h>
#include <math.h>
#include "../SoundManager/SoundManager.h"

class CEnemyBase
{
protected:
	enum ENEMY_STATE
	{
		STATE_MOVE = 0,	//�ړ�
		STATE_ATTACK,	//�U��

		STATE_NUM,
	};

	VECTOR cPos;		//���W
	VECTOR cSize;		//�T�C�Y
	VECTOR cRotate;		//��]�l
	VECTOR cSpeed;		//�ړ����x
	float Radius;		//���a
	int iHndl;			//�n���h��

	float Life;			//���C�t
	int HitCount;		//�e�̓���������
	bool IsActive;		//�����t���O

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CEnemyBase();
	~CEnemyBase();

	//������
	void Init();

	//�f�[�^���[�h
	void Load(int iMdlHndl);

	//�I������
	void Exit();

	//���t���[���Ăԏ���
	virtual void Step();

	//�X�V����
	void Update();

	//�`�揈��
	virtual void Draw();

	//���N�G�X�g
	virtual bool RequestEnemy(const VECTOR& vPos, const VECTOR& vSpeed);

	//��������
	bool GetActive() { return IsActive; }

	//���W�擾
	VECTOR GetPosition() { return cPos; }

	//���f���̔��a�擾
	float GetRadius()
	{
		return Radius;
	}

	//�����蔻��̏���
	virtual void HitCalc()
	{
		CSoundManager::Play(CSoundManager::SOUNDID_SE_EXPLORE);
		Life -= 1;
		cPos.z += 2.0f;
		HitCount++;

		//���C�t���Ȃ��Ȃ�����t���O������
		if (Life <= 0)
		{
			HitCount = 0;
			IsActive = false;
		}
	}

};