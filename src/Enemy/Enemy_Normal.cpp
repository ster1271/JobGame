#include "Enemy_Normal.h"

const int MAX_LIFE (3);		//�ő�̗�

//�R���X�g���N�^
CEnemy_Normal::CEnemy_Normal()
{
}
//�f�X�g���N�^
CEnemy_Normal::~CEnemy_Normal()
{
}

//������
void CEnemy_Normal::Init()
{
	CEnemyBase::Init();

}

//�f�[�^���[�h
void CEnemy_Normal::Load(int Hndl)
{
	iHndl = MV1DuplicateModel(Hndl);
}

//�`��
void CEnemy_Normal::Draw()
{
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
	float fLength = 1000.0f;
	if (cPos.x > fLength || cPos.x < -fLength
		|| cPos.z > fLength || cPos.z < -fLength)
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