#pragma once
#include "EnemyBase.h"

class CEnemyBoss :public CEnemyBase
{
private:
	VECTOR Respown_Pos;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CEnemyBoss();
	~CEnemyBoss();

	//������
	void Init();

	//�f�[�^���[�h
	void Load(int Hndl);

	//�`��
	void Draw();

	//���t���[���s������
	void Step();

	//�㏈��
	void Exit();

	//���N�G�X�g
	virtual bool RequestEnemy(const VECTOR& vPos, const VECTOR& vSpeed);
};
