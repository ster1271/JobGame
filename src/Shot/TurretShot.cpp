#include "TurretShot.h"


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
	if (iHndl == -1)
	{
		iHndl = MV1DuplicateModel(iMdlHndl);
	}
}

//�`��
void CTurretShot::Draw()
{
	if (IsActive)
	{
		MV1DrawModel(iHndl);

		/*DrawFormatString(500, 0, GetColor(255, 0, 0), "X���W�F%f", cPos.x);
		DrawFormatString(500, 15, GetColor(255, 0, 0), "Y���W�F%f", cPos.y);
		DrawFormatString(500, 30, GetColor(255, 0, 0), "Z���W�F%f", cPos.z);*/
		/*DrawSphere3D(vPos, m_Radius, 16, GetColor(255, 255, 255), GetColor(255, 255, 255), FALSE);*/

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

}

//���N�G�X�g
bool CTurretShot::RequestShot(const VECTOR& vPos, const VECTOR& vSpeed)
{
	//���łɔ��˂���Ă���
	if (IsActive) return false;

	cPos = vPos;
	cSize = VGet(0.05f, 0.05f, 0.05f);
	cSpeed = vSpeed;
	IsActive = true;

	return true;
}
