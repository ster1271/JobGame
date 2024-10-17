#include "RouteSearch.h"

const float MAX_COST = 999.9f;
const float RADIUS = 5.0f;


//�{�b�g�̌o�H�T��
void CRoute_Search::Bot_Route_Search(VECTOR StartPos, VECTOR GoalPos, int MapHndl)
{
	List.clear();	//�O�̂���

	m_StartPos = StartPos;
	m_GoalPos = GoalPos;

	Info tmp;
	tmp.Pos = m_StartPos;
	tmp.Renge_form_Start = 0.0f;


	bool IsFinish = false;		//�T���I���t���O


	int SaveCnt = 0;							// �O��̃��[�v�ő������z��̌�
	int CurrentCnt = KEISANN(tmp, -1, MapHndl);	// ����̃��[�v�ő������z��̌�	(�X�^�[�g�n�_�̐e�ԍ���-1�Ƃ���)
	

	//�t���O��false�Ȃ�v�Z���s��
	while (!IsFinish)
	{
		float TotalMinCost = MAX_COST;		//�ŏ��]���R�X�g
		float NextTotalMinCost = MAX_COST;
		int vectorSize = List.size();


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
				CurrentCnt += KEISANN(tmp, i, MapHndl); 
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
		
		//�S�[�����肷���
		for (int i = List.size() - 1; i > List.size() - 1 - CurrentCnt; i--)
		{
			if (List[i].Renge_To_Goal == 0.0f)
			{
				//���[�v�𔲂���
				IsFinish = true;
				break;
			}
		}
	}

	//�S�[������X�^�[�g�܂ł̋O�Ղ����ǂ�
	for (int i = List.size() - 1; i > 0; i--)
	{
		//�܂��S�[���Ɠ����W��������
		if (List[i].Renge_To_Goal == 0.0f)
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
	for (int i = List.size() - 1; i > 0; i--)
	{
		if (List[i].IsFast == false)
		{
			List.erase(List.begin() + i);
		}
	}


}


//�]���v�Z
int CRoute_Search::KEISANN(Info info, int Info_Index, int MapHndl)
{
	//�̂���push_back������info�ɂȂ�
	Info tmp[DIR_NUM];

	//pushback�����񐔕ۑ�
	int cnt = 0;
	
	for (int i = 0; i < DIR_NUM; i++)
	{
		tmp[i].Renge_form_Start = info.Renge_form_Start + 10.0f;
		tmp[i].Pos = info.Pos;

		//�z��̐e�ԍ����i�[����
		tmp[i].Source_Num = Info_Index;
	}
	
	
	//�㉺���E�Ɍv�Z����
	tmp[DIR_UP].Pos.z += 10.0f;
	tmp[DIR_DOWN].Pos.z -= 10.0f;
	tmp[DIR_LEFT].Pos.x += 10.0f;
	tmp[DIR_RIGHT].Pos.x -= 10.0f;

	//���������߂�
	for (int i = 0; i < DIR_NUM; i++)
	{
		//�X�^�[�g�n�_�̍��W�������Ȃ�v�Z���Ȃ�
		if (tmp[i].Pos.x == m_StartPos.x &&
			tmp[i].Pos.y == m_StartPos.y &&
			tmp[i].Pos.z == m_StartPos.z)
		{
			continue;
		}

		//List�ɕۑ����ꂽ���W�Ɠ����Ȃ�v�Z���Ȃ�
		for (int i = 0; i < List.size(); i++)
		{
			if (tmp[i].Pos.x == List[i].Pos.x &&
				tmp[i].Pos.y == List[i].Pos.y &&
				tmp[i].Pos.z == List[i].Pos.z)
			{
				continue;
			}
		}


		//�e��10��BOX�ƃ}�b�v�̓����蔻����Ƃ�
		if (BoxToMap(tmp[i].Pos, MapHndl))
			continue;

		float _X = fabs(m_GoalPos.x - tmp[i].Pos.x);
		float _Z = fabs(m_GoalPos.z - tmp[i].Pos.z);
		tmp[i].Renge_To_Goal = _X + _Z;

		//���v�R�X�g�����߂�
		tmp[i].Total_Cost = tmp[i].Renge_form_Start + tmp[i].Renge_To_Goal;

		List.push_back(tmp[i]);

		cnt++;
	}

	return cnt;
}


//�o�H�T�����̃}�b�v�Ƃ̓����蔻��
bool CRoute_Search ::BoxToMap(VECTOR BoxCenter, int MapHndl)
{
	//�����蔻��
	MV1_COLL_RESULT_POLY_DIM result;
	result = MV1CollCheck_Sphere(MapHndl, -1, BoxCenter, RADIUS);

	//����������true��Ԃ�
	if (result.Dim->HitFlag == true)
	{
		return true;
	}

	return false;
}
