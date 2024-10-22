#pragma once
#include "../Common.h"
#include "EnemyBase.h"
#include "Enemy_Normal.h"
#include "EnemyBoss.h"
#include "../RouteSearch/RouteSearch.h"
#include "../Bot/Bot.h"
#include "../Map/Map.h"


using namespace std;

#define ENEMY_NUM	(3)

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
	CEnemy_Normal cEnemy_Normal[ENEMY_NUM];
	CEnemyBoss cEnemyBoss[ENEMY_NUM];

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
	void Step(CBot& cBot, CRoute_Search& cRoute_Search, CMap& cMap);

	//�`�揈��
	void Draw();

private:
	//�G���N�G�X�g
	void RequestEnemy();
};
