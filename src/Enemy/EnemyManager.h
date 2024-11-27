#pragma once
#include "Enemy_Normal.h"
#include "EnemyBoss.h"
#include "../Bot/Bot.h"
#include "../Map/MapManager.h"
#include "../RouteSearch/RouteSearch.h"
#include "../Wave/Wave.h"

#define ENEMY_MAXNUM	(2)

//�G�̎��
enum TYPE_ENEMY
{
	TYPE_ENEMY01 = 0,

	TYPE_BOSS,
	TYPE_NUM,
};

class CEnemyManager
{
private:
	//���f���̃R�s�[��
	int Org_Hndl;
	TYPE_ENEMY type_id;
	CEnemy_Normal cEnemy_Normal[ENEMY_MAXNUM];
	CEnemyBoss cEnemyBoss[ENEMY_MAXNUM];

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
	void Step(CBot& cBot, CMapManager cMapManager);

	//�`�揈��
	void Draw();

	//�G�̏��擾
	CEnemy_Normal& GetEnemy(int id) { return cEnemy_Normal[id]; }

private:
	//�G���N�G�X�g
	void RequestEnemy(int Index);
};
