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
void CEnemy_Normal::Step(const VECTOR vPos)
{

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
	Life = MAX_LIFE;
	IsActive = true;

	return true;
}