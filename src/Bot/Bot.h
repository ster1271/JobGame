#pragma once 
#include "DxLib.h"
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

	BOT_STATE State_Id;
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

};
