#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "EnemyBase.h"

using namespace std;

#define ENEMY_NUM	(5)

class CEnemyManager
{
private:
	//���f���̃R�s�[��
	int Org_Hndl;

	//CEnemyBase�^��List�z��
	vector<CEnemyBase*> Enemy_List;

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
