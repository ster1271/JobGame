#include "RouteSearch.h"

const int MAX_COST = 999;
const int CALC_DIS = 50;
const int MOVE_BLOKE = 1;
const float MOVE_SPEED = 0.2f;
const float RADIUS = 5.0f;

//�C���X�^���X�̏�����
CRoute_Search* CRoute_Search::cInstance = nullptr;


//�R���X�g���N�^
CRoute_Search::CRoute_Search()
{
	List.clear();
	ListCnt = 0;
	IsFinish = false;
}

//�f�X�g���N�^
CRoute_Search::~CRoute_Search(){}



//�C���X�^���X�̐���
void CRoute_Search::Create()
{
	//�C���X�^���X�ɂ���������Ă��Ȃ�������
	if (cInstance == nullptr)
	{
		//�V����new����
		cInstance = new CRoute_Search();
	}
}


//�C���X�^���X�̍폜
void CRoute_Search::Destroy()
{
	//�C���X�^���X����������Ă�����
	if (cInstance != nullptr)
	{
		//delete����nullptr������
		delete cInstance;
		cInstance = nullptr;
	}
}


//�C���X�^���X�̎擾
CRoute_Search* CRoute_Search::GetInstance()
{
	if (cInstance == nullptr)
	{
		//�C���X�^���X����������Ă��Ȃ������琶������
		Create();
		return cInstance;
	}
	else
	{
		return cInstance;
	}
}

//������
void CRoute_Search::Init()
{
	List.clear();
	ListCnt = 0;
	IsFinish = false;
}

//�㏈��
void CRoute_Search::Exit()
{
	List.clear();
	ListCnt = 0;
	IsFinish = false;
}

//�`��
void CRoute_Search::Draw(unsigned int Color)
{
	for (int a = 0; a < List.size(); a++)
	{
		CDraw3D::DrawBox3D(List[a].Pos, VGet(25.0f, 80.0f, 25.0f), Color);
	}
}


//�o�H�T��
vector<VECTOR> CRoute_Search::Route_Search(VECTOR StartPos, VECTOR GoalPos, CMapManager& cMapManager)
{
	
	List.clear();			//�O�̂���
	List.shrink_to_fit();	//�O�̂���

	m_StartPos.x = (int)StartPos.x;
	m_StartPos.y = (int)StartPos.y;
	m_StartPos.z = (int)StartPos.z;

	m_GoalPos.x = (int)GoalPos.x;
	m_GoalPos.y = (int)GoalPos.y;
	m_GoalPos.z = (int)GoalPos.z;

	//X���W��50�Ŋ���؂�Ȃ��Ƃ�
	int Result = Remain((int)m_StartPos.x, CALC_DIS);
	if (Result != 0)
	{
		//�v�Z���ʂ��K��l��菬�����Ƃ�
		if (Result <= 25)
		{
			m_StartPos.x -= Result;
		}
		else
		{
			Result = CALC_DIS - Result;
			m_StartPos.x += Result;
		}
	}

	Result = Remain((int)m_StartPos.z, CALC_DIS);
	if (Result != 0)
	{
		//�v�Z���ʂ��K��l��菬�����Ƃ�
		if (Result < 25)
		{
			m_StartPos.z -= Result;
		}
		else
		{
			Result = CALC_DIS - Result;
			m_StartPos.z += Result;
		}
	}

	Info tmp;
	memset(&tmp, -1, sizeof(Info));
	tmp.Pos = m_StartPos;
	tmp.Renge_form_Start = 0;


	bool IsFinish = false;		//�T���I���t���O


	int SaveCnt = 0;			//�O��̃��[�v�ő������z��̌�
	int CurrentCnt = Evaluat_Calc(tmp, -1, cMapManager);	//����̃��[�v�ő������z��̌�(�X�^�[�g�n�_�̐e�ԍ���-1�Ƃ���)
	
	int LoopCount = 0;

	//�t���O��false�Ȃ�v�Z���s��
	while (!IsFinish)
	{
		int TotalMinCost = MAX_COST;	//�ŏ��]���R�X�g
		int vectorSize = List.size();	//���X�g�i�[�T�C�Y

		SaveCnt = CurrentCnt;
		CurrentCnt = 0;

		//�]���l����ԒႢ���̂����߂�
		for (int i = vectorSize - 1; i > vectorSize - 1 - SaveCnt; i--)
		{
			if (List[i].Total_Cost < TotalMinCost)
			{
				TotalMinCost = List[i].Total_Cost;
			}
		}


		//�]���l����ԒႢ���̂�V���Ɍv�Z����
		for (int i = vectorSize - 1; i > vectorSize - 1 - SaveCnt; i--)
		{
			if (List[i].Total_Cost == TotalMinCost)
			{
				CurrentCnt += Evaluat_Calc(List[i], i, cMapManager);
			}
		}

		//�����Ȃ������烊�X�g�̒��Ō��ʂ������̂��v�Z����
		if (CurrentCnt == 0)
		{
			TotalMinCost = MAX_COST;	//�ŏ��]���R�X�g�Đݒ�
			//�]�������ׂĕ��񂾎�
			for (int i = vectorSize - 1; i > vectorSize - 1 - SaveCnt; i--)
			{
				if (List[i].Total_Cost < TotalMinCost)
				{
					TotalMinCost = List[i].Total_Cost;
				}
			}

			//�]���l����ԒႢ���̂�V���Ɍv�Z����
			for (int i = vectorSize - 1; i > vectorSize - 1 - SaveCnt; i--)
			{
				if (List[i].Total_Cost == TotalMinCost)
				{
					CurrentCnt += Evaluat_Calc(List[i], i, cMapManager);
				}
			}
		}
		
		//�S�[�����肷��
		for (int i = List.size() - 1; i > List.size() - 1 - CurrentCnt; i--)
		{
			if (List[i].Renge_To_Goal == 0)
			{
				//���[�v�𔲂���
				IsFinish = true;
				break;
			}
		}
	}


	//�S�[������X�^�[�g�܂ł̋O�Ղ����ǂ�
	for (int i = List.size() - 1; i >= 0; i--)
	{

		//�܂��S�[���Ɠ����W��������
		if (List[i].Renge_To_Goal == 0)
		{
			List[i].IsFast = true;
		}

		//�ŏ��Ɍ������z��̐e�ԍ������ǂ��Ă���
		if (List[i].IsFast == true)
		{
			List[List[i].Source_Num].IsFast = true;

			//�e�ԍ���-1(�X�^�[�g�ԍ�)�ɂȂ����炱�̏�������߂�
			if (List[List[i].Source_Num].Source_Num == -1)
			{
				break;
			}
		}
	}

	//�t���O��false�̔z��ԍ����폜����
	for (int i = List.size() - 1; i >= 0; i--)
	{
		if (List[i].IsFast == false)
		{
			List.erase(List.begin() + i);
		}
	}

	vector<VECTOR>Pos_List;
	Pos_List.clear();
	//���W�̂݊i�[����
	for (int i = 0; i < List.size(); i++)
	{
		Pos_List.push_back(List[i].Pos);
	}

	//���X�g���폜����
	List.clear();

	return Pos_List;
}


//�]���v�Z
int CRoute_Search::Evaluat_Calc(Info info, int Info_Index, CMapManager& cMapManager)
{
	//�̂���push_back������info�ɂȂ�
	Info tmp[DIR_NUM];

	//pushback�����񐔕ۑ�
	int cnt = 0;
	
	for (int i = 0; i < DIR_NUM; i++)
	{
		//�S�[������X�^�[�g�܂ł̋��������߂�
		tmp[i].Pos = info.Pos;
		//�z��̐e�ԍ����i�[����
		tmp[i].Source_Num = Info_Index;
	}
	
	//�㉺���E�Ɍv�Z����
	tmp[DIR_UP].Pos.z += CALC_DIS;
	tmp[DIR_DOWN].Pos.z -= CALC_DIS;
	tmp[DIR_LEFT].Pos.x += CALC_DIS;
	tmp[DIR_RIGHT].Pos.x -= CALC_DIS;

	for (int i = 0; i < DIR_NUM; i++)
	{
		//�X�^�[�g����̋���
		tmp[i].Renge_form_Start = (int)fabs((tmp[i].Pos.x - m_StartPos.x) / CALC_DIS) + (int)fabs((tmp[i].Pos.z - m_StartPos.z) / CALC_DIS)/* = info.Renge_form_Start + 1*/;
	}
	
	for (int Index = 0; Index < DIR_NUM; Index++)
	{
		//�X�^�[�g�n�_�̍��W�������Ȃ�v�Z���Ȃ�
		if (tmp[Index].Pos.x == m_StartPos.x &&
			//tmp[Index].Pos.y == m_StartPos.y &&
			tmp[Index].Pos.z == m_StartPos.z)
		{
			continue;
		}

		bool IsMatch = false;
		//List�ɕۑ����ꂽ���W�Ɠ����Ȃ�v�Z���Ȃ�
		for (int i = 0; i < List.size(); i++)
		{
			if (tmp[Index].Pos.x == List[i].Pos.x &&
				tmp[Index].Pos.z == List[i].Pos.z)
			{
				IsMatch = true;
				break;
			}
		}
		//true�Ȃ炱��ȍ~�v�Z����for������
		if (IsMatch)
			continue;

		//�I�u�W�F�N�g�Ɠ������Ă��邩���肷��
		bool IsHit = false;
		for (int i = 0; i < cMapManager.GetMap().GetWallList().size(); i++)
		{
			if (tmp[Index].Pos.x == cMapManager.GetMap().GetWallList()[i].vPos.x &&
				//tmp[Index].Pos.y == cMap.GetMapInfo()[i].vPos.y &&
				tmp[Index].Pos.z == cMapManager.GetMap().GetWallList()[i].vPos.z)
			{
				if (cMapManager.GetMap().GetWallList()[i].IsMap == true)
				{
					IsHit = true;
					break;
				}
			}
		}
		//true�Ȃ炱��ȍ~�v�Z����for������
		if (IsHit)
			continue;

		//�ړ��R�X�g�����߂�
		int _X = (int)fabs((m_GoalPos.x / CALC_DIS) - (tmp[Index].Pos.x / CALC_DIS));
		int _Z = (int)fabs((m_GoalPos.z / CALC_DIS) - (tmp[Index].Pos.z / CALC_DIS));
		tmp[Index].Renge_To_Goal = _X + _Z;

		//���v�R�X�g�����߂�(���R�X�g + �ړ��R�X�g)
		tmp[Index].Total_Cost = tmp[Index].Renge_form_Start + tmp[Index].Renge_To_Goal;

		//�t���O��false�ɂ���
		tmp[Index].IsFast = false;

		List.push_back(tmp[Index]);

		cnt++;
	}

	return cnt;
}

