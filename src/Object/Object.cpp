#include "Object.h"

//�R���X�g���N�^
CObject::CObject()
{
	//�n���h���̏�����
	Org_Hndl = -1;
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));

	IsActive = false;
}

//�f�X�g���N�^
CObject::~CObject()
{
	//�n���h���̏�����
	Org_Hndl = -1;
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));

	IsActive = false;
}

//������
void CObject::Init()
{
	//�n���h���̏�����
	Org_Hndl = -1;
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));

	IsActive = false;
}

//�ǂݍ��݊֘A
void CObject::Load(int Org_Hndl)
{
	//���f���̓ǂݍ���
	iHndl = MV1DuplicateModel(Org_Hndl);
}

//�`��
void CObject::Draw()
{
	//���f���̕`��
	MV1DrawModel(iHndl);
}

//���t���[���s������
void CObject::Step() {};

//�X�V����
void CObject::Update()
{
	MV1SetPosition(iHndl, cPos);		//���W�̍X�V
	MV1SetScale(iHndl, cSize);			//�T�C�Y�̍X�V
	MV1SetRotationXYZ(iHndl, cRotate);	//��]�l�̍X�V
}

//�㏈��
void CObject::Exit()
{
	//�n���h���̍폜
	if (iHndl != -1)
	{
		MV1DeleteModel(iHndl);
		iHndl = -1;
	}

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
}

//�ݒu����
void CObject::Set_Point(const VECTOR& vPos) {};
