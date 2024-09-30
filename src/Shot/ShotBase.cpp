#include "ShotBase.h"

//�R���X�g���N�^�E�f�X�g���N�^
CShotBase::CShotBase()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cSpeed, 0, sizeof(VECTOR));

	iHndl = -1;
	Radius = 0.0f;
	IsActive = false;
}

CShotBase::~CShotBase()
{
	Exit();
}

//�`�揈��
void CShotBase::Draw()
{
}

//���X�V
void CShotBase::UpDate()
{
	MV1SetPosition(iHndl, cPos);
	MV1SetScale(iHndl, cSize);
	MV1SetRotationXYZ(iHndl, cRotate);
}

//�㏈��
void CShotBase::Exit()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cSpeed, 0, sizeof(VECTOR));

	iHndl = -1;
	Radius = 0.0f;
	IsActive = false;
}


//���N�G�X�g
bool CShotBase::RequestShot(const VECTOR& vPos, const VECTOR& vSpeed)
{
	//���łɔ��˂���Ă���
	if (IsActive) return false;

	cPos = vPos;
	cSpeed = vSpeed;
	IsActive = true;

	return true;

}