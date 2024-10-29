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

class CRoute_Search
{
private:
	enum DIR
	{
		DIR_UP = 0,
		DIR_DOWN,
		DIR_LEFT,
		DIR_RIGHT,
		DIR_NUM,
	};

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
	int ListCnt;				//���X�g�J�E���g
	bool IsFinish;				//�T���I���t���O


	VECTOR m_StartPos;	//�ۑ��p
	VECTOR m_GoalPos;	//�ۑ��p

	float tmp;

public:
	//������
	void Init();

	//�o�H�T���̌��ʂ̃��X�g�擾
	vector<VECTOR> GetSearch_List() { return Pos_List; }

	//�t���O�擾
	bool GetIsFinish() { return IsFinish; }

	//�{�b�g�̌o�H�T��
	bool Route_Search(VECTOR StartPos, VECTOR GoalPos, CMap& cMap);

	//�]���v�Z
	int Evaluat_Calc(Info info, int Info_Index, CMap& cMap);

	//�ړ�����
	void Go_Route(VECTOR& vPos, VECTOR& vRotate, float vSpeed = 5.0f);

	void Draw();
	
};


