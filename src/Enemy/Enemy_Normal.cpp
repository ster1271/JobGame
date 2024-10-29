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
		cRoute_Search.Route_Search(cPos, cBot.GetPos(), cMap);
		
		State_Id = STATE_MOVE;
		break;

	case CEnemyBase::STATE_MOVE:
		Range = (cBot.GetPos().x - cPos.x) * (cBot.GetPos().x - cPos.x) + (cBot.GetPos().z - cPos.z) * (cBot.GetPos().z - cPos.z);
		Range = sqrt(Range);

		if (Range < 150.0f)
		{
			//�i�s�����̂ǂ��瑤�ɂ���̂��𒲂ׂ�
			float Dir = 0.0f;

			//�{�b�g����w��̒n�_�֍s���x�N�g�����v�Z
			VECTOR Vtmp;
			Vtmp.x = cBot.GetPos().x - cPos.x;
			Vtmp.y = 0.0f;
			Vtmp.z = cBot.GetPos().z - cPos.z;

			VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);	//�{�b�g�̈ړ��x�N�g��
			vSpd.x = sinf(cRotate.y) * -SPEED;
			vSpd.y = 0.0f;
			vSpd.z = cosf(cRotate.y) * -SPEED;

			//�O�όv�Z
			Dir = (Vtmp.x * vSpd.z) - (vSpd.x * Vtmp.z);

			if (fabsf(Dir) < 1.0f)
			{
				float X = Vtmp.x = cPos.x - cBot.GetPos().x;
				float Z = Vtmp.x = cPos.z - cBot.GetPos().z;

				//�w��̈ʒu�֊p�x��ς���
				float NextRotY = atan2f(X, Z);

				cRotate.y = NextRotY;
			}
			else if (Dir >= 0.0f)//����ȊO�͊p�x��ς���
			{
				cRotate.y += 0.05f;
			}
			else if (Dir < 0.0f)
			{
				cRotate.y -= 0.05f;
			}

			//���W�ɑ��x�����Z����
			cPos.x += sinf(cRotate.y) * -0.2f;
			cPos.z += cosf(cRotate.y) * -0.2f;
		}
		else
		{
			cRoute_Search.Go_Route(cPos, cRotate);
		}

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