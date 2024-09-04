#pragma once
#include "EnemyBase.h"

#define ENEMY_NUM	(5)

class CEnemyManager
{
private:
	CEnemyBase cEnemyBace[ENEMY_NUM];

	int m_iWaitCnt;		//�G�����������܂ł̎���

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CEnemyManager();
	~CEnemyManager();

	//������
	void Init();

	//�f�[�^���[�h
	void Load();

	//�I������
	void Exit();

	//���t���[���Ăԏ���
	void Step();

	//�`�揈��
	void Draw();

	//�G���擾
	inline CEnemyBase& GetEnemy(int iID) { return cEnemyBace[iID]; }

private:
	//�G���N�G�X�g
	void RequestEnemy();
};
