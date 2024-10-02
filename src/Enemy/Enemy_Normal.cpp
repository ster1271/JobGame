#include "Enemy_Normal.h"

const int MAX_LIFE (3);		//�ő�̗�

//�R���X�g���N�^
CEnemy_Normal::CEnemy_Normal()
{
	memset(&Respown_Pos, 0, sizeof(VECTOR));
}
//�f�X�g���N�^
CEnemy_Normal::~CEnemy_Normal()
{
}

//������
void CEnemy_Normal::Init()
{
	CEnemyBase::Init();

	cPos = VGet(0.0f, 5.0f, GetRand(200.0f) + 100.0f);
	cSize = VGet(0.1f, 0.1f, 0.1f);
	cSpeed = VGet(0.0f, 0.0f, 0.5f);
	IsActive = true;
	Respown_Pos = cPos;
}

//�f�[�^���[�h
void CEnemy_Normal::Load(int Hndl)
{
	iHndl = MV1DuplicateModel(Hndl);
}

//�`��
void CEnemy_Normal::Draw()
{
	if (IsActive == false)
		return;

	MV1DrawModel(iHndl);
}

//���t���[���s������
void CEnemy_Normal::Step()
{
	if (!IsActive)
	{
		return;
	}

	//���W�ɑ��x�����Z
	cPos = VAdd(cPos, cSpeed);
	//���͈͂𒴂��������
	float fLength = 100.0f;
	if (cPos.x > Respown_Pos.x + fLength || cPos.x < Respown_Pos.x -fLength
		|| cPos.z > Respown_Pos.z + fLength || cPos.z < Respown_Pos .z -fLength)
	{
		IsActive = false;
	}

	//�X�V����
	Update();
}

//�㏈��
void CEnemy_Normal::Exit()
{
	CEnemyBase::Exit();
	memset(&Respown_Pos, 0, sizeof(VECTOR));

}

//���N�G�X�g
bool CEnemy_Normal::RequestEnemy(const VECTOR& vPos, const VECTOR& vSpeed)
{
	//���łɏo�����Ă���
	if (IsActive)
	{
		return false;
	}

	cPos = vPos;
	cSpeed = vSpeed;
	Life = MAX_LIFE;
	IsActive = true;

	return true;
}