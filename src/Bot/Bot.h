#pragma once 
#include "../Common.h"
#include "../RouteSearch/RouteSearch.h"
#include "../Map/MapManager.h"
#include "../Wave/Wave.h"


//�{�b�g�N���X
class CBot
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

	VECTOR cPos;
	VECTOR cRotate;
	VECTOR cSize;

	int iHndl;

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

	//���X�V
	void Updata();

	//���W�擾
	VECTOR GetPos() { return cPos; }

	//�T�C�Y�擾
	VECTOR GetSize() { return cSize; }

	//��]�n�擾
	VECTOR GetRotate() { return cRotate; }

	//�t���O�擾
	bool GetFinish() { return IsFinish; }

	//���t���[���s������
	void Step(CMapManager& cMapManager);

	//�w��̏ꏊ�ɓ�������
	void Move_Bot(vector<VECTOR> List);

};
