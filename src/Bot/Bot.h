#pragma once 
#include "DxLib.h"
#include <math.h>
#include "../MyLibrary/MyLibrary.h"
#include "../Input/Input.h"
#include "../Object/Object.h"
#include "../Object/ObjectManager.h"
#include "../Check_Point/Check_Point.h"

//�{�b�g�N���X
class CBot :public CObject
{
private:
	//�{�b�g�̏�ԑJ��
	enum BOT_STATE
	{
		STATE_STOP = 0,	//��~
		STATE_MOVE,		//�ړ�
		STATE_NUM,
	};

	//�o�H�T���ɕK�v�ȕϐ����
	struct Route_Search_Info
	{
		VECTOR Center_Pos;			//�T�����钆�S�ʒu
		float Range_From_Start[8];	//�X�^�[�g����̋���
		float Renge_To_Goal[8];		//�S�[���܂ł̋���
		float Total_Renge[8];		//���v����	
		float Min_Total_Renge;		//�ŏ�����
		float Distance;
	};

	BOT_STATE State_Id;
	Route_Search_Info Search_info;
	float tmp_dir;
	float tmp_Range;
	int tmp;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CBot();
	~CBot();

	//������
	void Init();

	//�ǂݍ���
	bool Load();

	//�`��
	void Draw();

	//���t���[���s������
	void Step(vector<VECTOR> List);

	//�w��̏ꏊ�ɓ�������
	void Move_Bot(vector<VECTOR> List);

	//�o�H�T��
	void Route_Search(VECTOR GoalPos);

};
