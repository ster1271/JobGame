#pragma once
#include "../Object.h"

class Check_Point :public CObject
{
private:


public:
	//�R���X�g���N�^�E�f�X�g���N�^
	Check_Point();
	~Check_Point();

	//������
	void Init();

	//���f���ǂݍ���
	void Load(int Hndl);

	//�ݒu����
	void Set_Point(const VECTOR vPos);

};
