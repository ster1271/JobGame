#pragma once
#include "EnemyBase.h"
#include "../Wave/Wave.h"

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
	void Step(VECTOR vPos, CMapManager& cMapManager);

	//�㏈��
	void Exit();

	//���N�G�X�g
	bool RequestEnemy(VECTOR vPos, VECTOR vSpeed);

};
