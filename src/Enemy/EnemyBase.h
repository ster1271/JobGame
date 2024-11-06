#pragma once
#include "../Common.h"
#include "../CollisionManager/Collision/Collision.h"
#include "../Bot/Bot.h"
#include "../RouteSearch/RouteSearch.h"
#include "../SoundManager/SoundManager.h"

const float ENEMY_RADIUS	(10.0f);		//���f���̔��a


class CEnemyBase
{
protected:
	enum ENEMY_STATE
	{
		STATE_SEARCH = 0,	//�o�H�T��
		STATE_MOVE,			//�ړ�
		STATE_ATTACK,		//�U��

		STATE_NUM,
	};

	ENEMY_STATE State_Id;

	VECTOR cPos;		//���W
	VECTOR cSize;		//�T�C�Y
	VECTOR cRotate;		//��]�l
	VECTOR cSpeed;		//�ړ����x
	float Radius;		//���a
	int iHndl;			//�n���h��

	float Life;			//���C�t
	int HitCount;		//�e�̓���������
	bool IsActive;		//�����t���O

	vector<VECTOR>List;	//���W�i�[�p
	int ListCnt;

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
	float GetRadius() {	return ENEMY_RADIUS;}

	//�����蔻��̏���
	void HitCalc()
	{
		CSoundManager::Play(CSoundManager::SOUNDID_SE_EXPLORE);
		Life--;
		HitCount++;

		//���C�t���Ȃ��Ȃ�����t���O������
		if (Life <= 0)
		{
			HitCount = 0;
			State_Id = STATE_SEARCH;
			List.clear();
			IsActive = false;
		}
	}

	//�ړ�����
	void Enemy_Move(vector<VECTOR> List, int& Cnt);

};