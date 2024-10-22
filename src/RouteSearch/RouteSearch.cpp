#include "RouteSearch.h"

const int MAX_COST = 999;
const int MOVE_BLOKE = 1;
const float RADIUS = 5.0f;


//�`��
void CRoute_Search::Draw()
{
	for (int a = 0; a < List.size(); a++)
	{
		CDraw3D::DrawBox3D(List[a].Pos, VGet(25.0f, 80.0f, 25.0f), GetColor(0, 255, 0));
	}
}


//�{�b�g�̌o�H�T��
bool CRoute_Search::Route_Search(VECTOR StartPos, VECTOR GoalPos, CMap& cMap)
{
	
	List.clear();	//�O�̂���

	m_StartPos = StartPos;
	m_GoalPos = GoalPos;

	Info tmp;
	memset(&tmp, -1, sizeof(Info));
	tmp.Pos = m_StartPos;
	tmp.Renge_form_Start = 0;


	bool IsFinish = false;		//�T���I���t���O


	int SaveCnt = 0;					//�O��̃��[�v�ő������z��̌�
	int CurrentCnt = Evaluat_Calc(tmp, -1, cMap);	//����̃��[�v�ő������z��̌�(�X�^�[�g�n�_�̐e�ԍ���-1�Ƃ���)
	
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

		//�]���l����ԒႢ���̂Ōv�Z����
		for (int i = vectorSize - 1; i > vectorSize - 1 - SaveCnt; i--)
		{
			if (List[i].Total_Cost == TotalMinCost)
			{
				CurrentCnt += Evaluat_Calc(List[i], i, cMap);
			}
		}

		/*
		//�����J�E���g���������Ȃ�����
		if (CurrentCnt == 0)
		{
			//��Ԗڂ̕]���l���Z�o����
			for (int i = 0; i < List.size() - 1; i++)
			{
				
			}
		}
		*/
		
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

		LoopCount++;
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

	//���W�̂݊i�[����
	for (int i = 0; i < List.size(); i++)
	{
		Pos_List.push_back(List[i].Pos);
	}

	return true;
}


//�]���v�Z
int CRoute_Search::Evaluat_Calc(Info info, int Info_Index, CMap& cMap)
{
	//�̂���push_back������info�ɂȂ�
	Info tmp[DIR_NUM];

	//pushback�����񐔕ۑ�
	int cnt = 0;
	
	for (int i = 0; i < DIR_NUM; i++)
	{
		tmp[i].Renge_form_Start = info.Renge_form_Start + 1;
		tmp[i].Pos = info.Pos;

		//�z��̐e�ԍ����i�[����
		tmp[i].Source_Num = Info_Index;
	}
	
	
	//�㉺���E�Ɍv�Z����
	tmp[DIR_UP].Pos.z += 50.0f;
	tmp[DIR_DOWN].Pos.z -= 50.0f;
	tmp[DIR_LEFT].Pos.x += 50.0f;
	tmp[DIR_RIGHT].Pos.x -= 50.0f;

	
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
				//tmp[Index].Pos.y == List[i].Pos.y &&
				tmp[Index].Pos.z == List[i].Pos.z)
			{
				IsMatch = true;
				break;
			}
		}
		if (IsMatch)
			continue;

		//�I�u�W�F�N�g�Ɠ������Ă��邩���肷��
		bool IsHit = false;
		for (int i = 0; i < cMap.GetMapInfo().size(); i++)
		{
			if (tmp[Index].Pos.x == cMap.GetMapInfo()[i].vPos.x &&
				//tmp[Index].Pos.y == cMap.GetMapInfo()[i].vPos.y &&
				tmp[Index].Pos.z == cMap.GetMapInfo()[i].vPos.z)
			{
				if (cMap.GetMapInfo()[i].IsMap == true)
				{
					IsHit = true;
					break;
				}
			}
		}
		if (IsHit)
			continue;

		//�ړ��R�X�g�����߂�
		int _X = (int)fabs((m_GoalPos.x / 50.0f) - (tmp[Index].Pos.x / 50.0f));
		int _Z = (int)fabs((m_GoalPos.z / 50.0f) - (tmp[Index].Pos.z / 50.0f));
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

