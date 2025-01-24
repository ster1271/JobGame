#pragma once
#include <math.h>
#include "../MyLibrary/MyLibrary.h"
#include "../Object/Object.h"
#include "../Shot/ShotManager.h"
#include "../Enemy/EnemyManager.h"


//�^���b�g�x�[�X�N���X
class CTurretBase
{
protected:
	int Org_Hndl;		//���f���n���h��(�R�s�[��)
	int iHndl;			//���f���n���h��(�R�s�[�p)

	FILE* fp;			//�t�@�C������ϐ�

	VECTOR cPos;		//���W
	VECTOR cRotate;		//��]�l
	VECTOR cSize;		//�g�k�l
	float ShotRenge;	//�˒�����
	float Dir;			//�i�s�����p�ϐ�


	float Hp;			//�^���b�g��HP
	int Power_Up_Count;	//������

	bool IsActive;		//�����t���O

	vector<VECTOR> SetTurretPoint;

public:
	CTurretBase();
	~CTurretBase();
	
	//������
	void Init();

	//���f���ǂݍ���
	virtual void Load(int Hndl) = 0;
	
	//�`��
	virtual void Draw() = 0;

	//���t���[���s������
	virtual void Step(CShotManager& cShotManager, CEnemyManager& cEnemyManager) = 0;

	//���X�V
	void Update();

	//�㏈��
	void Exit();

	//���W�擾
	VECTOR GetPos() { return cPos; }

	//�T�C�Y�擾
	VECTOR GetSize() { return cSize; }

	//��]�n�擾
	VECTOR GetRotate() { return cRotate; }

	//�t���O�擾
	bool GetIsActive() { return IsActive; }

	//�^���b�g�ݒu����
	virtual void TurretSpawn(const VECTOR &vPos) = 0;

	//�^���b�g����
	virtual void Turret_Power_Up();

	//�^���b�g��]����
	virtual void Turret_Rotate(VECTOR vPos);

	//�^���b�g�̐ݒu�ʒu�ǂݍ���
	void Load_TurretPoint();

};

