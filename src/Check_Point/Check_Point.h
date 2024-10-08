#pragma once
#include <DxLib.h>
#include <iostream>
#include <vector>
#include "../Check_Point/Check_Base.h"

#define  MAX_NUM	(5)

using namespace std;

class CCheck_Point: public CCheck_Base
{
private:
	vector<VECTOR> Point_info_List;
	int tmp_Hndl;
	int tmp;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CCheck_Point();
	~CCheck_Point();

	//������
	void Init(FILE * fp);

	//���f���ǂݍ���
	void Load(int Hndl);

	//�`��
	void Draw();

	//���t���[���s������
	void Step();

	//�㏈��
	void Exit();

	//���X�g����
	vector<VECTOR> Get_List()
	{
		return Point_info_List;
	}

	//�ݒu����
	void Set_Point(const VECTOR vPos);


	//�t�@�C���ǂݍ���
	void LoadFile();
};
