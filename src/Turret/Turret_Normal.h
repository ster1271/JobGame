#pragma once
#include "TurretBase.h"
#include "../Debug/DebugString.h"


//�^���b�g�N���X(�ʏ�)
class CTurret_Normal: public CTurretBase
{
private:
	float Attack;
	int CoolTime;

	float TotalMinLenge;
	VECTOR EnemyPos;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CTurret_Normal();
	~CTurret_Normal();

	//������
	void Init();

	//�f�[�^���[�h
	void Load(int Hndl);

	//�`��
	void Draw();

	//���t���[���s������
	void Step(CShotManager& cShotManager, CEnemyManager& cEnemyManager);

	//�㏈��
	void Exit();

	//�^���b�g�ݒu����
	void TurretSpawn(const VECTOR &vPos);

	//�e�̔��˃��N�G�X�g
	void TurretShot(CShotManager& cShotManager);

	//�^���b�g����
	void Turret_Power_Up();

};
