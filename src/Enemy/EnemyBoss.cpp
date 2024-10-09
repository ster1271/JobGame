#include "EnemyBoss.h"

const int MAX_LIFE = 5;		//�ő�̗�


//�R���X�g���N�^
CEnemyBoss::CEnemyBoss()
{
	memset(&Respown_Pos, 0, sizeof(VECTOR));
}

//�f�X�g���N�^
CEnemyBoss::~CEnemyBoss()
{
}

//������
void CEnemyBoss::Init()
{
	CEnemyBase::Init();
}

//�f�[�^���[�h
void CEnemyBoss::Load(int Hndl)
{
	iHndl = MV1DuplicateModel(Hndl);
}

//�`��
void CEnemyBoss::Draw()
{
	if (IsActive == false)
		return;

	MV1DrawModel(iHndl);
}

//���t���[���s������
void CEnemyBoss::Step()
{
	if (!IsActive)
	{
		return;
	}

	//���W�ɑ��x�����Z
	cPos = VSub(cPos, cSpeed);
	//���͈͂𒴂��������
	float fLength = 100.0f;
	if (cPos.x > Respown_Pos.x + fLength || cPos.x < Respown_Pos.x - fLength
		|| cPos.z > Respown_Pos.z + fLength || cPos.z < Respown_Pos.z - fLength)
	{
		IsActive = false;
	}

	//�X�V����
	Update();
}

//�㏈��
void CEnemyBoss::Exit()
{
	CEnemyBase::Exit();
	memset(&Respown_Pos, 0, sizeof(VECTOR));
}

//���N�G�X�g
bool CEnemyBoss::RequestEnemy(const VECTOR& vPos, const VECTOR& vSpeed)
{
	//���łɏo�����Ă���
	if (IsActive)
	{
		return false;
	}

	cPos = vPos;
	Respown_Pos = vPos;
	cSize = VGet(0.2f, 0.2f, 0.2f);
	cRotate = VGet(0.0f, DX_PI_F / 2, 0.0f);
	cSpeed = vSpeed;
	Life = MAX_LIFE;
	IsActive = true;
}