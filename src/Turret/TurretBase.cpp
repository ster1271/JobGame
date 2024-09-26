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

//���t���[���s������
void Step(const VECTOR vPos, CShotManager& cShotManager) {};

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
void CTurretBase::Turret_Rotate(const VECTOR vPos)
{
	//�^���b�g�ƑΏۂ̃x�N�g�����v�Z
	VECTOR Vtmp;
	Vtmp.x = vPos.x - cPos.x;
	Vtmp.y = 0.0f;
	Vtmp.z = vPos.z - cPos.z;

	//�^���b�g�̉��̈ړ��x�N�g�����v�Z
	VECTOR Turret_Vec;
	Turret_Vec.x = sinf(cRotate.y) * 1.0f;
	Turret_Vec.y = 0.0f;
	Turret_Vec.z = cosf(cRotate.y) * 1.0f;

	//�O�όv�Z
	float Dir = Vtmp.x * Turret_Vec.z - Vtmp.z * Turret_Vec.x;

	//��]����p�x�����߂�
	if (Dir >= 0.0f)
	{
		cRotate.y += 0.01f;
	}
	else if (Dir < 0.0f)
	{
		cRotate.y -= 0.01f;
	}
}


