#pragma once
#include "../UIBase/BaseUI.h"
#include "../../Enemy/EnemyManager.h"


class CEnemyUI :public CUIBase
{
private:
	int LifeHndl;
	int MaxLifeHndl;
	int Alpha;			//�����x
	int Count;

	float preLife[ENEMY_MAXNUM];
	float CurrentLife[ENEMY_MAXNUM];

	CEnemy_Normal cEnemy[ENEMY_MAXNUM];

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CEnemyUI();
	~CEnemyUI();

	//������
	void Init();

	//�ǂݍ���
	void Load();

	//���t���[���s������
	void Step(CEnemyManager &cEnemyManager);

	//�`��
	void Draw();

	//�㏈��
	void Exit();

};

