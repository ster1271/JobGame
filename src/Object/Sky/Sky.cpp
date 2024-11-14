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
	cPos = VECTOR_ZERO;
	cScale = VGet(2.0f, 2.0f, 2.0f);
	cRotate = VECTOR_ZERO;
	cSize = VECTOR_ZERO;
}


//���f���ǂݍ���
void CSky::Load()
{
	iHndl = MV1LoadModel("data/Sky/Sky.x");
}


//�ʏ폈��
void CSky::Step()
{
	cRotate.y += 0.0005f;

	/*
	VECTOR vDir;
	vDir.x = sinf(fRot) * 30.0f;
	vDir.z = cosf(fRot) * 30.0f;

	//���_�̍����͌Œ�
	vDir.y = 10.0f;

	SetSkyPos(vForcus, vDir);
	*/
}

//�ړ�����
void CSky::SetSkyPos(VECTOR vF, VECTOR dir)
{
	cPos = VAdd(vF, dir);
}