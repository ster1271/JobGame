#pragma once
#include "../Common.h"
#include "../MyLibrary/MyLibrary.h"
#include "../Map/Map.h"

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
		int Renge_form_Start;	//�ړ��R�X�g(�X�^�[�g�n�_���痣�ꂽ����)
		int Renge_To_Goal;		//����R�X�g(�S�[���܂ł̋���)
		int Total_Cost;			//���v�R�X�g
		VECTOR Pos;				//���̈ړ�����W
		int Source_Num;			//�e�ԍ�
		bool IsFast;			//�ŒZ�������ǂ���
	};

	vector<Info> List;			//�i�[�p
	vector<VECTOR> Pos_List;	//���W�����n���p


	VECTOR m_StartPos;	//�ۑ��p
	VECTOR m_GoalPos;	//�ۑ��p


public:
	//�o�H�T���̌��ʂ̃��X�g�擾
	vector<VECTOR> GetSearch_List() { return Pos_List; }

	//�{�b�g�̌o�H�T��
	bool Route_Search(VECTOR StartPos, VECTOR GoalPos, CMap& cMap);

	//�]���v�Z
	int Evaluat_Calc(Info info, int Info_Index, CMap& cMap);

	void Draw();
	
};


