#pragma once
#include "../Object.h"

class CRoute_Point :public CObject
{
private:


public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CRoute_Point();
	~CRoute_Point();

	//������
	void Init();

	//���f���ǂݍ���
	void Load();

	//�ݒu����
	void Set_Point(const VECTOR& vPos);

};
