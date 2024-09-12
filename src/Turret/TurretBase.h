#pragma once
#include "../Object/Object.h"

//�^���b�g�x�[�X�N���X
class TurretBase : public CObject
{
protected:
	VECTOR ShotRenge;	//�˒�����

	float Hp;			//�^���b�g��HP
	int Power_Up_Count;	//������

	bool IsActive;		//�����t���O

public:
	TurretBase();
	~TurretBase();
	
	//������
	void Init();

	//�f�[�^���[�h
	void Load(const char FILEPATH[]);

	//���t���[���s������
	virtual void Step() = 0;

	//�㏈��
	void Exit();

	//�t���O�擾
	bool GetIsActive() { return IsActive; }

	//�^���b�g�ݒu����
	virtual bool TurretSpawn(const VECTOR vPos);

	//�^���b�g����
	void Turret_Power_Up();

};

