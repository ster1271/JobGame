#pragma once
#include "../Enemy/EnemyBase.h"

class CEnemy_Normal: public CEnemyBase
{
private:

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CEnemy_Normal();
	~CEnemy_Normal();

	//������
	void Init();

	//�f�[�^���[�h
	void Load(int Hndl);

	//�`��
	void Draw();

	//���t���[���s������
	/*void Step(const VECTOR vPos);*/

	//�㏈��
	void Exit();

	//���N�G�X�g
	virtual bool RequestEnemy(const VECTOR& vPos, const VECTOR& vSpeed);
};
