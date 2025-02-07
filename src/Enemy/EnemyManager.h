#pragma once
#include "Enemy_Normal.h"
#include "EnemyBoss.h"
#include "../Bot/Bot.h"
#include "../Map/MapManager.h"
#include "../RouteSearch/RouteSearch.h"
#include "../Wave/Wave.h"

const int ENEMY_MAXNUM = 10;

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
	static CEnemyManager* cInstance;		//�C���X�^���X

	//���f���̃R�s�[��
	int Org_Hndl;
	TYPE_ENEMY type_id;
	CEnemy_Normal cEnemy_Normal[ENEMY_MAXNUM];
	CEnemyBoss cEnemyBoss[ENEMY_MAXNUM];
	int CoolTime;
	int ReqestCount;		//���N�G�X�g������
	int DeathCount;			//�|���ꂽ��

	//�R���X�g���N�^�E�f�X�g���N�^
	CEnemyManager();
	~CEnemyManager();

public:
	static void Create();				//�C���X�^���X�̐���

	static void Destroy();				//�C���X�^���X�̍폜

	static CEnemyManager* GetInstance();		//�C���X�^���X�̎擾
	

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
	void RequestEnemy();
};
