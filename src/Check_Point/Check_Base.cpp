#include "Check_Base.h"

//�R���X�g���N�^
CCheck_Base::CCheck_Base()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));

	iHndl = -1;
	IsActive = false;
}

//�f�X�g���N�^
CCheck_Base:: ~CCheck_Base() {};

//������
void CCheck_Base::Init()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));

	iHndl = -1;
	IsActive = false;
}

//�f�[�^�ǂݍ���
void CCheck_Base::Load(int Hndl)
{
	//�R�s�[���f���̓ǂݍ���
	iHndl = MV1DuplicateModel(Hndl);
}

//�㏈��
void CCheck_Base::Exit()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));

	iHndl = -1;
	IsActive = false;
}

//���X�V
void CCheck_Base::Updata()
{
	MV1SetPosition(iHndl, cPos);		//���W�̍X�V
	MV1SetScale(iHndl, cSize);			//�T�C�Y�̍X�V
	MV1SetRotationXYZ(iHndl, cRotate);	//��]�l�̍X�V
}

//�`��
void CCheck_Base::Draw() {};

//���t���[���s������
void CCheck_Base::Step() {};