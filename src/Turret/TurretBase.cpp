#include "TurretBase.h"

//�R���X�g���N�^
TurretBase::TurretBase()
{
	memset(&ShotRenge, 0, sizeof(VECTOR));
	Life = 0.0f;
	IsActive = false;		
}

//�f�X�g���N�^
TurretBase::~TurretBase()
{
	memset(&ShotRenge, 0, sizeof(VECTOR));

	Life = 0.0f;
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

//�^���b�g�ݒu����
bool TurretBase::TurretSpawn(const VECTOR& vPos)
{
	//���łɔ��˂���Ă���
	if (IsActive) return false;

	cPos = vPos;
	cSize = VGet(1.0f, 1.0f, 1.0f);
	cRotate = VGet(0.0f, 0.0f, 0.0f);
	IsActive = true;

	return true;
}


//�^���b�g����
void TurretBase::Turret_Power_Up()
{
	
}