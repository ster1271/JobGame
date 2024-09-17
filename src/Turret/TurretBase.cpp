#include "TurretBase.h"

#define MAX_POWER_UP_COUNT	(5)	//�ő勭����

//�R���X�g���N�^
CTurretBase::CTurretBase()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&ShotRenge, 0, sizeof(VECTOR));

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
	memset(&ShotRenge, 0, sizeof(VECTOR));

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
	memset(&ShotRenge, 0, sizeof(VECTOR));

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

