#include "Sky.h"
#include <math.h>

//�R���X�g���N�^
CSky::CSky()
{
}

//�f�X�g���N�^
CSky::~CSky()
{
}

//������
void CSky::Init()
{
	cPos = VGet(0.0f, 0.0f, 0.0f);
	cSize = VGet(2.0f, 2.0f, 2.0f);
	cRotate = VGet(0.0f, 0.0f, 0.0f);
}


//�ʏ폈��
void CSky::Step(VECTOR vForcus, float fRot)
{
	cRotate.y += 0.0005f;

	VECTOR vDir;
	vDir.x = sinf(fRot) * 30.0f;
	vDir.z = cosf(fRot) * 30.0f;

	//���_�̍����͌Œ�
	vDir.y = 10.0f;

	SetSkyPos(vForcus, vDir);
}

//�ړ�����
void CSky::SetSkyPos(VECTOR vF, VECTOR dir)
{
	cPos = VAdd(vF, dir);
}