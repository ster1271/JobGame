#include "Enemy_Normal.h"

const int MAX_LIFE = 20;		//�ő�̗�
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
	if (IsActive == false)	return;

	MV1DrawModel(iHndl);
	DrawSphere3D(cPos, Radius, 16, GetColor(255, 255, 255), GetColor(255, 255, 255), FALSE);

	if (IS_DEBUG)
	{
		cRoute_Search.Draw(GetColor(0, 0, 255));
		DrawString(200, 200, "�`�撆", GetColor(0, 0, 255));
		DrawFormatString(200, 215, GetColor(0, 0, 255), "X���W:%f", cPos.x);
		DrawFormatString(200, 230, GetColor(0, 0, 255), "Y���W:%f", cPos.y);
		DrawFormatString(200, 245, GetColor(0, 0, 255), "Z���W:%f", cPos.z);
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
		List = cRoute_Search.Route_Search(cPos, cBot.GetPos(), cMapManager);
		
		State_Id = STATE_MOVE;
		break;

	case CEnemyBase::STATE_MOVE:
		Enemy_Move(List, ListCnt);
		
		break;

	case CEnemyBase::STATE_ATTACK:
		if (ListCnt == List.size())
		{
			ListCnt = 0;
			State_Id = STATE_SEARCH;
		}
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
	State_Id = STATE_SEARCH;
	List.clear();
	ListCnt = 0;
	IsActive = true;

	return true;
}