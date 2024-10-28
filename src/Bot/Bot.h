#pragma once 
#include "../Common.h"
#include "../Object/Object.h"
#include "../Object/ObjectManager.h"
#include "../Check_Point/Check_Point.h"
#include "../RouteSearch/RouteSearch.h"
#include "../CollisionManager/CollisionManager.h"


using namespace std;

//�{�b�g�N���X
class CBot :public CObject
{
private:
	//�{�b�g�̏�ԑJ��
	enum BOT_STATE
	{
		STATE_STOP = 0,	//��~
		STATE_SEARCH,	//�o�H�T��
		STATE_MOVE,		//�ړ�

		STATE_NUM,
	};


	BOT_STATE State_Id;

	float tmp_dir;
	float tmp_Range;
	int tmp;
	int NUM;
	bool IsCalcu;
	float NextRotY;

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
	void Step(CRoute_Search& cRoute_Search, CMap& cMap);

	//�w��̏ꏊ�ɓ�������
	void Move_Bot(vector<VECTOR> List);

};
