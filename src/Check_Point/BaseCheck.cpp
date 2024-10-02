#include "BaseCheck.h"

//�R���X�g���N�^�E�f�X�g���N�^
CBase_Check::CBase_Check()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));

	iHndl = -1;

	IsActive = false;
}

CBase_Check::~CBase_Check()
{
	Exit();
}

//������
void CBase_Check::Init()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));

	iHndl = -1;

	IsActive = false;
}

//�ǂݍ���
void CBase_Check::Load()
{
}

//���X�V
void CBase_Check::UpData()
{
	MV1SetPosition(iHndl, cPos);		//���W�̍X�V
	MV1SetScale(iHndl, cSize);			//�T�C�Y�̍X�V
	MV1SetRotationXYZ(iHndl, cRotate);	//��]�l�̍X�V
}

//�㏈��
void CBase_Check::Exit()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));

	iHndl = -1;

	IsActive = false;
}