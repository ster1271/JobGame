#pragma once
#include "../Common.h"
#include "../MyLibrary/MyLibrary.h"
#include "../CollisionManager/CollisionManager.h"

//��ԑJ��
enum NODE_STATE
{
	NONE = 0,	//����
	OPEN,		//���蒆
	CLOSE,		//����I��
};

enum DIR
{
	DIR_UP = 0,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT,
	DIR_NUM,
};

class CRoute_Search
{
private:
	NODE_STATE State;

	struct Info
	{
		float Renge_form_Start;	//�ړ��R�X�g(�X�^�[�g�n�_���痣�ꂽ����)
		float Renge_To_Goal;	//����R�X�g(�S�[���܂ł̋���)
		float Total_Cost;		//���v�R�X�g
		VECTOR Pos;				//���̈ړ�����W
		int Source_Num;			//�e�ԍ�
		bool IsFast;			//�ŒZ�������ǂ���
	};

	vector<Info> List;		//�i�[�p


	VECTOR m_StartPos;	//�ۑ��p
	VECTOR m_GoalPos;	//�ۑ��p


public:
	//�{�b�g�̌o�H�T��
	void Bot_Route_Search(VECTOR StartPos, VECTOR GoalPos, int MapHndl);

	//�]���v�Z
	int KEISANN(Info info, int Info_Index ,int MapHndl);

	//�o�H�T�����̃}�b�v�Ƃ̓����蔻��
	bool BoxToMap(VECTOR BoxCenter, int MapHndl);
};


