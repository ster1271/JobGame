#pragma once
#include "../UIBase/BaseUI.h"
#include "../../Enemy/EnemyManager.h"


class CEnemyUI :public CUIBase
{
private:
	int LifeHndl;
	int MaxLifeHndl;
	
	int Count[ENEMY_MAXNUM];
	int Alpha[ENEMY_MAXNUM];			//�����x
	float PreLife[ENEMY_MAXNUM];
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

	//�����x�ύX
	void Alpha_Change(int Index);
};

