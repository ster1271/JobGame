#pragma once
#include "Enemy_Normal.h"
#include "../Wave/Wave.h"

const int ENEMY_MAXNUM = 20;

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
	CEnemy_Normal cEnemy_Normal[ENEMY_MAXNUM];

	//���f���̃R�s�[��
	int OrgHndl;
	int CoolTime;
	int ReqestCount;		//���N�G�X�g������
	int DeathCount;			//�|���ꂽ��

	void RequestEnemy();	//�G���N�G�X�g


public:
	void SetCnt(int i = 1) { DeathCount += i; }

	//�R���X�g���N�^�E�f�X�g���N�^
	CEnemyManager();
	~CEnemyManager();

	//������
	void Init();

	//�f�[�^���[�h
	void Load();

	//�I������
	void Exit();

	//���t���[���s������
	void Step(VECTOR vPos, CMapManager cMapManager);

	//�`�揈��
	void Draw();

	//�G�̏��擾
	CEnemy_Normal& GetEnemy(int id) { return cEnemy_Normal[id]; }
};
