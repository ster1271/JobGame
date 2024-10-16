#include "RouteSearch.h"

const float MAX_COST = 999.9f;


//�{�b�g�̌o�H�T��
void CRoute_Search::Bot_Route_Search(VECTOR StartPos, VECTOR GoalPos)
{
	m_StartPos = StartPos;
	m_GoalPos = GoalPos;


}


//�]���v�Z
void CRoute_Search::KEISANN(Info info)
{
	//�̂���push_back������info�ɂȂ�
	Info tmp[DIR_NUM];
	
	for (int i = 0; i < DIR_NUM; i++)
	{
		tmp[i].Renge_form_Start = info.Renge_form_Start + 10.0f;
		tmp[i].Pos = info.Pos;
	}
	
	
	//�㉺���E�Ɍv�Z����
	tmp[DIR_UP].Pos.z += 10.0f;
	tmp[DIR_DOWN].Pos.z -= 10.0f;
	tmp[DIR_LEFT].Pos.x += 10.0f;
	tmp[DIR_RIGHT].Pos.x -= 10.0f;

	//���������߂�
	for (int i = 0; i < DIR_NUM; i++)
	{
		//�O�̍��W�Ɠ����̂�������v�Z���Ȃ�
		if (tmp[i].Pos.x == info.Pos.x &&
			tmp[i].Pos.y == info.Pos.y &&
			tmp[i].Pos.z == info.Pos.z)
		{
			continue;
		}
		
		//�e��10��BOX�ƃ}�b�v�̓����蔻����Ƃ�
	/*	if ()
			continue;*/

		float _X = fabs(m_GoalPos.x - tmp[i].Pos.x);
		float _Z = fabs(m_GoalPos.z - tmp[i].Pos.z);
		tmp[i].Renge_To_Goal = _X + _Z;

		//���v�R�X�g�����߂�
		float Total_Min_Cost = MAX_COST;
		tmp[i].Total_Cost = tmp[i].Renge_form_Start + tmp[i].Renge_To_Goal;
		
		//���v�R�X�g�̍ŏ����i�[����
		if (tmp[i].Total_Cost <= Total_Min_Cost)
		{
			Total_Min_Cost = tmp[i].Total_Cost;
		}


		List.push_back(tmp[i]);
	}

}