#pragma once
#include "EnemyBase.h"

//�G�̃T�C�Y
const VECTOR ENEMY_BOSS_SIZE = VGet(0.0f, 0.0f, 0.0f);

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
	void Step(CBot& cBot, CMapManager& cMapManager);

	//�㏈��
	void Exit();

	//���N�G�X�g
	virtual bool RequestEnemy(const VECTOR& vPos, const VECTOR& vSpeed);
};
