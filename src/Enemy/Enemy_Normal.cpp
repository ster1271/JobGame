#include "Enemy_Normal.h"

const float SPEED = 5.0f;		//�ړ����x
const int RESEARCH_TIME = 1000;	//�o�H�T������������

//�R���X�g���N�^
CEnemy_Normal::CEnemy_Normal()
{
	memset(&Respown_Pos, 0, sizeof(VECTOR));
}
//�f�X�g���N�^
CEnemy_Normal::~CEnemy_Normal() {}

//������
void CEnemy_Normal::Init()
{
	//�ЂƂ܂�������
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cNextPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cScale, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cSpeed, 0, sizeof(VECTOR));

	Life = 0;;			//���C�t
	iHndl = -1;			//�n���h��

	IsActive = false;	//�����t���O

	List.clear();
	ReSeachTime = 0;
	ListCnt = 0;
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
	if (!IsActive)
		return;

	MV1DrawModel(iHndl);

	if (IS_DEBUG)
	{
		CRoute_Search::GetInstance()->Draw(GetColor(0, 0, 255));
	}
}

//���t���[���s������
void CEnemy_Normal::Step(CBot& cBot, CMapManager& cMapManager)
{
	if (!IsActive)
		return;

	float Range = 0.0f;

	switch (State_Id)
	{
	case CEnemyBase::STATE_SEARCH:
		List = CRoute_Search::GetInstance()->Route_Search(cPos, cBot.GetPos(), cMapManager);
		
		State_Id = STATE_MOVE;
		break;

	case CEnemyBase::STATE_MOVE:

		//�v���C���[�Ƃ̋������v�Z
		VECTOR v_tmp;
		v_tmp.x = cBot.GetPos().x - cPos.x;
		v_tmp.y = 0.0f;
		v_tmp.z = cBot.GetPos().z - cPos.z;

		Range = VSize(v_tmp);

		if (Range >= 50.0f)
		{
			ReSeachTime++;

			//���Ԍo�߂Ōo�H�T��������
			/*if (ReSeachTime >= RESEARCH_TIME)
			{
				List.clear();
				ReSeachTime = 0;
				ListCnt = 0;
				State_Id = STATE_SEARCH;

				break;
			}*/

			//�o�H�ړ�����
			Enemy_Move(List, ListCnt);
		}
		else
		{
			//�ǔ��ړ�
			Out_Move(cBot.GetPos());
		}


		break;
	case CEnemyBase::STATE_ATTACK:
		


		break;
	
	default:
		break;
	}

	//�����ݒ�
	SetDir();

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
	cNextPos = cPos;
	Respown_Pos = vPos;
	cScale = VGet(0.1f, 0.1f, 0.1f);
	cSize = ENEMY_NORMAL_SIZE;
	cRotate = VGet(0.0f, DX_PI_F / 2, 0.0f);
	cSpeed = vSpeed;
	Life = ENEMY_MAX_LIFE;

	//�����X�V����
	Update();

	List.clear();
	ListCnt = 0;

	State_Id = STATE_SEARCH;
	IsActive = true;

	return true;
}

