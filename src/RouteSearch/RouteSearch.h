#pragma once
#include "../Common.h"
#include "../MyLibrary/MyLibrary.h"
#include "../Map/MapManager.h"
#include "../Debug/DebugString.h"


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
	int ListCnt;				//���X�g�J�E���g
	bool IsFinish;				//�T���I���t���O


	VECTOR m_StartPos;	//�ۑ��p
	VECTOR m_GoalPos;	//�ۑ��p

	float tmp;

public:
	//������
	void Init();

	//�㏈��
	void Exit();

	//�t���O�擾
	bool GetIsFinish() { return IsFinish; }

	//�o�H�T��
	vector<VECTOR> Route_Search(VECTOR StartPos, VECTOR GoalPos, CMapManager& cMapManager);

	//�]���v�Z
	int Evaluat_Calc(Info info, int Info_Index, CMapManager& cMapManager);

	//�ړ�����
	void Go_Route(VECTOR& vPos, VECTOR& vRotate, float vSpeed = 5.0f);

	//�`��
	void Draw(unsigned int Color);
	
	//����Z
	int Remain(int A, int B){ return A % B; }

};


