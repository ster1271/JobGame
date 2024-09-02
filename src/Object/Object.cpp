#include "Object.h"

//�R���X�g���N�^
CObject::CObject()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
}

//�f�X�g���N�^
CObject::~CObject()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
}

//������
void CObject::Init()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
}

//�ǂݍ��݊֘A
bool CObject::Load(const char FILEPATH[])
{
	//���f���̓ǂݍ���
	iHndl = MV1LoadModel(FILEPATH);

	/*�ǂݍ��ݐ��� = true, �ǂݍ��ݎ��s = false*/
	if (iHndl != -1)
		return true;
	else
		return false;
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

