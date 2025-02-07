#include "TurretBase.h"

#define MAX_POWER_UP_COUNT	(5)	//�ő勭����

//�R���X�g���N�^
CTurretBase::CTurretBase()
{
	//�n���h���̏�����
	Org_Hndl = -1;
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	ShotRenge = 0.0f;

	Hp = 0.0f;
	Power_Up_Count = 0;
	IsActive = false;		
}

//�f�X�g���N�^
CTurretBase::~CTurretBase()
{
}

//������
void CTurretBase::Init()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	ShotRenge = 0.0f;
	Dir = 0.0f;
	Hp = 0.0f;
	Power_Up_Count = 0;
	IsActive = false;
}

//�㏈��
void CTurretBase::Exit()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	ShotRenge = 0.0f;

	Hp = 0.0f;
	Power_Up_Count = 0;
	IsActive = false;
}

//���X�V
void CTurretBase::Update()
{
	MV1SetPosition(iHndl, cPos);		//���W�̍X�V
	MV1SetScale(iHndl, cSize);			//�T�C�Y�̍X�V
	MV1SetRotationXYZ(iHndl, cRotate);	//��]�l�̍X�V
}

//�^���b�g����
void CTurretBase::Turret_Power_Up()
{

}


//�^���b�g���ˏ���
void CTurretBase::Turret_Rotate(VECTOR vPos)
{
	//�i�s�����p�ϐ�
	Dir = 0.0f;

	//�^���b�g�ƑΏۂ̃x�N�g�����v�Z
	VECTOR Vtmp;
	Vtmp.x = vPos.x - cPos.x;
	Vtmp.y = 0.0f;
	Vtmp.z = vPos.z - cPos.z;

	//�^���b�g�̉��̈ړ��x�N�g�����v�Z
	VECTOR Turret_Vec = VECTOR_ZERO;
	Turret_Vec.x = sinf(cRotate.y) * 1.0f;
	Turret_Vec.y = 0.0f;
	Turret_Vec.z = cosf(cRotate.y) * 1.0f;

	//�O�όv�Z
	Dir = (Vtmp.x * Turret_Vec.z) - (Turret_Vec.x * Vtmp.z);

	//��Βl��1.0f��菬����������
	if (fabsf(Dir) < 5.0f)
	{
		float X = vPos.x - cPos.x;
		float Z = vPos.z - cPos.z;

		//�����I�Ɋp�x��ς���
		float NextRotY = atan2f(X, Z);

		cRotate.y = NextRotY;
	}
	//��]����p�x�����߂�
	else if (Dir >= 0.0f)
	{
		cRotate.y += 0.1f;
	}
	else if (Dir < 0.0f)
	{
		cRotate.y -= 0.1f;
	}
}



