#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "EnemyBase.h"
#include "Enemy_Normal.h"
#include "EnemyBoss.h"

using namespace std;

#define ENEMY_NUM	(3)

class CEnemyManager
{
private:
	//���f���̃R�s�[��
	int Org_Hndl;
	CEnemy_Normal cEnemy_Normal[ENEMY_NUM];
	CEnemyBoss cEnemyBoss[ENEMY_NUM];

	//CEnemyBase�^��List�z��
	/*vector<CEnemyBase*> Enemy_List;

	CEnemyBase cEnemyBace;*/

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
	//inline CEnemyBase& GetEnemy(int iID) { return cEnemyBace; }

private:
	//�G���N�G�X�g
	void RequestEnemy();
};
