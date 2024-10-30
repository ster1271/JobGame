#include "Shot.h"
#include "../Base/Base.h"
#include "../Character/Attacker.h"
#include "../Character/Tank.h"
#include "../Character/Support.h"

//----------------------------------------
//�R���X�g���N�^
//----------------------------------------
CShot::CShot()
{
}

//----------------------------------------
//�f�X�g���N�^
//----------------------------------------
CShot::~CShot()
{
	//�O�̂���
	Exit();
}

//----------------------------------------
//������
//----------------------------------------
void CShot::Init()
{
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cSpeed, 0, sizeof(VECTOR));

	iHndl = -1;
	Radius = 0.0f;
	IsActive = false;
}


//----------------------------------------
//�I������
//----------------------------------------
void CShot::Exit()
{
	//���f���n���h�����
	if (iHndl != -1)
	{
		MV1DeleteModel(iHndl); 
		iHndl = -1;
	}
}


//----------------------------------------
//�f�[�^���[�h
//----------------------------------------
void CShot::Load(int iMdlHndl)
{
	if (iHndl == -1)
	{
		iHndl = MV1DuplicateModel(iMdlHndl);
	}
}


//----------------------------------------
//�`�揈��
//----------------------------------------
void CShot::Draw()
{
	if (IsActive)
	{
		MV1DrawModel(iHndl);

		DrawFormatString(500, 0, GetColor(255, 0, 0), "X���W�F%f", cPos.x);
		DrawFormatString(500, 15, GetColor(255, 0, 0), "Y���W�F%f", cPos.y);
		DrawFormatString(500, 30, GetColor(255, 0, 0), "Z���W�F%f", cPos.z);
		/*DrawSphere3D(vPos, m_Radius, 16, GetColor(255, 255, 255), GetColor(255, 255, 255), FALSE);*/

	}

}


//----------------------------------------
//���t���[���Ăԏ���
//----------------------------------------
void CShot::Step(VECTOR Pos)
{
	if (!IsActive) return;

	//���W�ɑ��x�����Z
	cPos = VAdd(cPos, cSpeed);


	//���͈͂𒴂��������
	float fLength =	500;

	if (cPos.x > Pos.x + fLength || cPos.x < Pos.x -fLength
		|| cPos.z > Pos.z + fLength || cPos.z < Pos.z - fLength)
	{
		IsActive = false;
	}

	//���X�V
	UpDate();
}


//----------------------------------------
//���N�G�X�g
//----------------------------------------
bool CShot::RequestShot(const VECTOR &vPos, const VECTOR &vSpeed)
{
	//���łɔ��˂���Ă���
	if (IsActive) return false;

	cPos = vPos;
	cSize = VGet(0.05f, 0.05f, 0.05f);
	cSpeed = vSpeed;
	IsActive = true;

	return true;
	
}


