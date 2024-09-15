#pragma once
#include "../Object/Object.h"



//�^���b�g�x�[�X�N���X
class CTurretBase
{
protected:
	int iHndl;			//���f���n���h��

	VECTOR cPos;		//���W
	VECTOR cRotate;		//��]�l
	VECTOR cSize;		//�g�k�l
	VECTOR ShotRenge;	//�˒�����

	float Hp;			//�^���b�g��HP
	int Power_Up_Count;	//������

	bool IsActive;		//�����t���O

public:
	CTurretBase();
	~CTurretBase();
	
	//������
	void Init();

	//���f���ǂݍ���
	virtual void Load() = 0;
	
	//�`��
	virtual void Draw() = 0;

	//���t���[���s������
	virtual void Step() = 0;

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
	virtual void Turret_Power_Up() = 0;

};

