#pragma once
#include "Check_Point.h"

#define MAX_NUM	(5)

class CChecck_Manager
{
private:
	int check_Hndl;
	CCheck_Point cCheck_Point[MAX_NUM];

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CChecck_Manager();
	~CChecck_Manager();

	//������
	void Init();

	//�f�[�^�ǂݍ���
	void Load();

	//�㏈��
	void Exit();

	//���X�V
	void Updata();

	//�`��
	void Draw();

	void Step();

	//���X�g���擾
	vector<VECTOR> Get_List()
	{
		return cCheck_Point->Get_List();
	}
};
