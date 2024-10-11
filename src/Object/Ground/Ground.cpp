#include "Ground.h"

//�R���X�g���N�^
CGround::CGround()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
}

//�f�X�g���N�^
CGround::~CGround()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
}

//������
void CGround::Init()
{
	//�n���h���̏�����
	iHndl = -1;

	//�e�ϐ��̏�����
	cPos = VGet(0.0f, -20.0f, 0.0f);
	cSize = VGet(1.0f, 1.0f, 1.0f);
	cRotate = VGet(0.0f, 0.0f, 0.0f);
}

//���f���ǂݍ���
void CGround::Load()
{
	iHndl = MV1LoadModel("data/Map/field.x");
}