#pragma once
#include "../object.h"

class CSky :public CObject
{
private:

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CSky();
	~CSky();

	//������
	void Init();

	//���f���ǂݍ���
	void Load();

	//�ʏ폈��
	void Step();

	//�ړ�����
	void SetSkyPos(VECTOR vF, VECTOR dir);
};
