#pragma once
#include "../object.h"

#define MAX_NUM		(10)

class CGround :public CObject
{
private:
	int tmp[MAX_NUM][MAX_NUM];
	

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CGround();
	~CGround();
	

	//������
	void Init();

	//���f���ǂݍ���
	void Load();

	//�`��
	void Draw();

	//�n���h���擾
	int GetHndl() { return iHndl; }

};
