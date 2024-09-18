#pragma once
#include <math.h>
#include "../Object/Object.h"



//�^���b�g�x�[�X�N���X
class CTurretBase
{
protected:
	int Org_Hndl;		//���f���n���h��(�R�s�[��)
	int iHndl;			//���f���n���h��(�R�s�[�p)

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
	virtual void Load(int Hndl) = 0;
	
	//�`��
	virtual void Draw() = 0;

	//���t���[���s������
	virtual void Step(const VECTOR vPos) = 0;

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

	//�^���b�g���ˏ���
	virtual void Turret_Rotate(const VECTOR vPos);

};

