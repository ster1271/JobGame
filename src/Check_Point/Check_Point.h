#pragma once
#include <DxLib.h>
#include <iostream>
#include <vector>
#include "../Check_Point/Check_Base.h"

#define  MAX_NUM	(10)

using namespace std;

class CCheck_Point: public CCheck_Base
{
private:

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CCheck_Point();
	~CCheck_Point();

	//������
	void Init();

	//���f���ǂݍ���
	void Load(int Hndl);

	//�`��
	void Draw();

	//���t���[���s������
	void Step();

	//�㏈��
	void Exit();

	//�ݒu����
	void Set_Point(const VECTOR vPos);



};

