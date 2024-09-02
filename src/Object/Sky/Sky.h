#pragma once
#include "../object.h"

class CSky :public CObject
{
private:
	VECTOR m_Scale;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CSky();
	~CSky();

	//������
	void Init();

	//�`��
	void Draw();

	//�ʏ폈��
	void Step(VECTOR vForcus, float fRot);

	//���[�v����
	void Loop();

	//�ړ�����
	void SetSkyPos(VECTOR vF, VECTOR dir);
};
