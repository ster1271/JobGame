#include "TurretShot.h"

#define RADIUS	(3.0f)


//�R���X�g���N�^�E�f�X�g���N�^
CTurretShot::CTurretShot()
{
}

CTurretShot::~CTurretShot()
{
}

//������
void CTurretShot::Init()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cSpeed, 0, sizeof(VECTOR));

	iHndl = -1;
	Radius = 0.0f;
	IsActive = false;
}

//�ǂݍ���
void CTurretShot::Load(int iMdlHndl)
{
	iHndl = MV1DuplicateModel(iMdlHndl);
}

//�`��
void CTurretShot::Draw()
{
	if (IsActive)
	{
		MV1DrawModel(iHndl);
		DrawFormatString(500, 0, GetColor(255, 0, 0), "�^���b�g�eX���W�F%f", cPos.x);
		DrawFormatString(500, 15, GetColor(255, 0, 0), "�^���b�g�eY���W�F%f", cPos.y);
		DrawFormatString(500, 30, GetColor(255, 0, 0), "�^���b�g�eZ���W�F%f", cPos.z);

		//DrawSphere3D(cPos, RADIUS, 16, GetColor(255, 255, 255), GetColor(255, 255, 255), FALSE);


	}

	
}

//���t���[���s������
void CTurretShot::Step(VECTOR TurretPos)
{
	if (!IsActive) return;

	//���W�ɑ��x�����Z
	cPos = VAdd(cPos, cSpeed);


	//���͈͂𒴂��������
	float fLength = 100;

	/*if (cPos.x > TurretPos.x + fLength || cPos.x < TurretPos.x - fLength
		|| cPos.z > TurretPos.z + fLength || cPos.z < TurretPos.z - fLength)
	{
		IsActive = false;
	}*/

	//���̍X�V
	UpDate();
}

//���N�G�X�g
bool CTurretShot::RequestShot(const VECTOR& vPos, const VECTOR& vSpeed)
{
	//���łɔ��˂���Ă���
	if (IsActive) return false;

	cPos = vPos;
	cSize = VGet(0.0005f, 0.0005f, 0.0005f);
	cSpeed = vSpeed;
	IsActive = true;

	return true;
}
