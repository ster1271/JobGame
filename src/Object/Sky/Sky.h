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

	//�ʏ폈��
	void Step(VECTOR vForcus, float fRot);

	//�ړ�����
	void SetSkyPos(VECTOR vF, VECTOR dir);
};
