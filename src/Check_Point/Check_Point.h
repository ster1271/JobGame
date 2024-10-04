#pragma once
#include <DxLib.h>
#include <iostream>
#include <vector>

#define  MAX_NUM	(5)

using namespace std;

class CCheck_Point
{
private:
	VECTOR cPos[MAX_NUM];		//���W
	VECTOR cSize[MAX_NUM];		//�T�C�Y
	VECTOR cRotate[MAX_NUM];	//��]�l

	int iHndl[MAX_NUM];			//�n���h��

	bool IsActive[MAX_NUM];		//�t���O

	vector<VECTOR> Point_info_List;
	int tmp_Hndl;
	int tmp;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CCheck_Point();
	~CCheck_Point();

	//������
	void Init();

	//���f���ǂݍ���
	void Load();

	//�`��
	void Draw();

	//���X�V
	void UpData();

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
	void Set_Point(int Index, const VECTOR vPos);


	//�t�@�C���ǂݍ���
	void LoadFile();
};
