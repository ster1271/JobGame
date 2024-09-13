#include "TurretBase.h"

#define MAX_POWER_UP_COUNT	(5)	//�ő勭����

//�R���X�g���N�^
TurretBase::TurretBase()
{
	CObject::Init();
	memset(&ShotRenge, 0, sizeof(VECTOR));

	Hp = 0.0f;
	Power_Up_Count = 0;
	IsActive = false;		
}

//�f�X�g���N�^
TurretBase::~TurretBase()
{
}

//������
void TurretBase::Init()
{
	CObject::Init();
	memset(&ShotRenge, 0, sizeof(VECTOR));

	Hp = 0.0f;
	Power_Up_Count = 0;
	IsActive = false;
}

//�f�[�^���[�h
void TurretBase::Load(const char FILEPATH[])
{
	//���f���̓ǂݍ���
	iHndl = MV1LoadModel(FILEPATH);
}

//���t���[���s������
void TurretBase::Step()
{
}

//�㏈��
void TurretBase::Exit()
{
	iHndl = -1;

	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&ShotRenge, 0, sizeof(VECTOR));

	Hp = 0.0f;
	Power_Up_Count = 0;
	/*IsActive = false;*/
}

//�^���b�g�ݒu����
bool TurretBase::TurretSpawn(const VECTOR vPos)
{
	return true;
}


//�^���b�g����
void TurretBase::Turret_Power_Up()
{
}