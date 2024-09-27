#include "Base.h"

//�R���X�g���N�^
CBase::CBase()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&Life, 0, sizeof(float));
	
}

//�f�X�g���N�^
CBase::~CBase()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&Life, 0, sizeof(float));

}

//������
void CBase::Init()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&Life, 0, sizeof(float));

}

//�ǂݍ��݊֘A
bool CBase::Load(const char FILEPATH[])
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
void CBase::Draw()
{
	//���f���̕`��
	MV1DrawModel(iHndl);
}

//�X�V����
void CBase::Update()
{
	MV1SetPosition(iHndl, cPos);		//���W�̍X�V
	MV1SetScale(iHndl, cSize);			//�T�C�Y�̍X�V
	MV1SetRotationXYZ(iHndl, cRotate);	//��]�l�̍X�V
}

//�㏈��
void CBase::Exit()
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
	memset(&Life, 0, sizeof(float));
}

