#pragma once
#include "../Common.h"

class CMiniMap
{
private:
	VECTOR cPos;
	int iHndl;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CMiniMap();
	~CMiniMap();

	//������
	void Init();
	
	//�ǂݍ���
	void Load();

	//���t���[���s������
	void Step();

	//���X�V
	void UpData();

	//�㏈��
	void Exit();
};