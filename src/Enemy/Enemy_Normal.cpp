#include "Enemy_Normal.h"

const float SPEED = 5.0f;		//�ړ����x
const int RESEARCH_MAX_TIME = 3000;	//�o�H�T������������

//�R���X�g���N�^
CEnemy_Normal::CEnemy_Normal()
{
	memset(&Respown_Pos, 0, sizeof(VECTOR));
	ReSeachTime = 0;
}
//�f�X�g���N�^
CEnemy_Normal::~CEnemy_Normal() {}

//������
void CEnemy_Normal::Init()
{
	//�ЂƂ܂�������
	cScale = VGet(0.1f, 0.1f, 0.1f);
	cSize = ENEMY_NORMAL_SIZE;
	cRotate = VGet(0.0f, DX_PI_F / 2, 0.0f);


	Life = 0;			//���C�t
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
void CEnemy_Normal::Step(VECTOR vPos, CMapManager& cMapManager, vector<VECTOR> NormalWaveList)
{
	if (!IsActive)
		return;

	float Range = 0.0f;
	vector <VECTOR> tmp;

	switch (State_Id)
	{
	case CEnemyBase::STATE_SEARCH:
		tmp = CRoute_Search::GetInstance()->Route_Search(cPos, vPos, cMapManager);

		ListCnt = 0;

		State_Id = STATE_MOVE;
		break;

	case CEnemyBase::STATE_MOVE:

		//�v���C���[�Ƃ̋������v�Z
		VECTOR v_tmp;
		v_tmp.x = vPos.x - cPos.x;
		v_tmp.y = 0.0f;
		v_tmp.z = vPos.z - cPos.z;

		Range = VSize(v_tmp);

		//�{�b�g�̈ړ��E�F�[�u���̂݌o�H�T�������Ȃ���
		if (CWave::GetInstance()->GetWaveState() == STATE_WAVE_BOTMOVE)
		{
			ReSeachTime++;

			//���Ԍo�߂Ōo�H�T��������
			if (ReSeachTime >= RESEARCH_MAX_TIME)
			{
				ReSeachTime = 0;
				ListCnt = 0;
				State_Id = STATE_SEARCH;

				return;
			}
		}
		

		if (Range >= 50.0f)
		{
			if (CWave::GetInstance()->GetWaveState() == STATE_WAVE_NORMAL)
			{
				//�o�H�ړ�����
				Enemy_Move(NormalWaveList, ListCnt);
			}
			else
			{
				//�o�H�ړ�����
				Enemy_Move(tmp, ListCnt);
			}
		}
		else
		{
			//�ǔ��ړ�
			Out_Move(vPos);
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
bool CEnemy_Normal::RequestEnemy(VECTOR vPos, VECTOR vSpeed)
{
	//���łɏo�����Ă���
	if (IsActive)
		return false;
	
	cPos = vPos;
	cNextPos = cPos;
	Respown_Pos = vPos;
	cSpeed = vSpeed;
	Life = ENEMY_MAX_LIFE;

	//�����X�V����
	Update();

	State_Id = STATE_SEARCH;
	IsActive = true;

	return true;
}

