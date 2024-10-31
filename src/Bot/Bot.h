#pragma once 
#include "../Common.h"
#include "../Object/Object.h"
#include "../Object/ObjectManager.h"
#include "../Check_Point/Check_Point.h"
#include "../RouteSearch/RouteSearch.h"
#include "../CollisionManager/CollisionManager.h"
#include "../Map/MapManager.h"



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
	CRoute_Search cRoute;
	BOT_STATE State_Id;

	float tmp_dir;
	float tmp_Range;
	int tmp;
	int NUM;
	bool IsCalcu;
	float NextRotY;

	vector<VECTOR> Route_List;
	bool IsFinish;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CBot();
	~CBot();

	//������
	void Init();

	//�㏈��
	void Exit();

	//�ǂݍ���
	bool Load();

	//�`��
	void Draw();

	//�t���O�擾
	bool GetFinish() { return IsFinish; }

	//���t���[���s������
	void Step(CMapManager& cMapManager);

	//�w��̏ꏊ�ɓ�������
	void Move_Bot(vector<VECTOR> List);

};
