#include "Enemy_Normal.h"

const int MAX_LIFE = 3;		//�ő�̗�
const float SPEED = 5.0f;

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
	State_Id = STATE_SEARCH;
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
void CEnemy_Normal::Step(CBot& cBot, CMap& cMap)
{
	if (!IsActive)
		return;

	float Range = 0.0f;

	switch (State_Id)
	{
	case CEnemyBase::STATE_SEARCH:

		
		State_Id = STATE_MOVE;
		break;

	case CEnemyBase::STATE_MOVE:
		
		break;

	case CEnemyBase::STATE_ATTACK:
		 
		break;
	
	default:
		break;
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
	Respown_Pos = vPos;
	cSize = VGet(0.1f, 0.1f, 0.1f);
	cRotate = VGet(0.0f, DX_PI_F / 2, 0.0f);
	cSpeed = vSpeed;
	Life = MAX_LIFE;
	IsActive = true;

	return true;
}