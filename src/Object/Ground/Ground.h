#pragma once
#include "../object.h"

class CGround :public CObject
{
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
