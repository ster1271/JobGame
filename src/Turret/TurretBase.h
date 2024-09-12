#pragma once
#include "../Object/Object.h"

//�^���b�g�x�[�X�N���X
class TurretBase : public CObject
{
protected:
	VECTOR ShotRenge;	//�˒�����
	VECTOR ShotSpeed;		//�ˌ��X�s�[�h
	float Life;			//�^���b�g��HP
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

	//�^���b�g�ݒu����
	bool TurretSpawn(const VECTOR& vPos);

	//�^���b�g����
	void Turret_Power_Up();

};

