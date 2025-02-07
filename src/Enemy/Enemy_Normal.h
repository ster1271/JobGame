#pragma once
#include "EnemyBase.h"
#include "../Bot/Bot.h"

const int ENEMY_MAX_LIFE = 20;		//�ő�̗�

//�G�̃T�C�Y
const VECTOR ENEMY_NORMAL_SIZE = VGet(0.0f, 0.0f, 0.0f);

class CEnemy_Normal:public CEnemyBase
{
private:
	VECTOR Respown_Pos;
	int ReSeachTime;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CEnemy_Normal();
	~CEnemy_Normal();
	
	//������
	void Init();

	//�f�[�^���[�h
	void Load(int Hndl);

	//�`��
	void Draw();

	//���t���[���s������
	void Step(CBot& cBot, CMapManager& cMapManager);

	//�㏈��
	void Exit();

	//���N�G�X�g
	virtual bool RequestEnemy(const VECTOR& vPos, const VECTOR& vSpeed);

};
