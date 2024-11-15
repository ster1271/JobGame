#include "PlayerShot.h"
#include "../Player/Player.h"

//----------------------------------------
//�R���X�g���N�^
//----------------------------------------
CPlayerShot::CPlayerShot()
{
}

//----------------------------------------
//�f�X�g���N�^
//----------------------------------------
CPlayerShot::~CPlayerShot()
{
	//�O�̂���
	Exit();
}

//----------------------------------------
//������
//----------------------------------------
void CPlayerShot::Init()
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
void CPlayerShot::Exit()
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
void CPlayerShot::Load(int iMdlHndl)
{
	if (iHndl == -1)
	{
		iHndl = MV1DuplicateModel(iMdlHndl);
	}
}


//----------------------------------------
//�`�揈��
//----------------------------------------
void CPlayerShot::Draw()
{
	if (IsActive)
	{
		MV1DrawModel(iHndl);

		if (IS_DEBUG)
		{
			DrawFormatString(500, 0, GetColor(255, 0, 0), "�v���C���[�eX���W�F%f", cPos.x);
			DrawFormatString(500, 15, GetColor(255, 0, 0), "�v���C���[�eY���W�F%f", cPos.y);
			DrawFormatString(500, 30, GetColor(255, 0, 0), "�v���C���[�eZ���W�F%f", cPos.z);
			DrawSphere3D(cPos, SHOTRADIUS, 16, GetColor(255, 255, 255), GetColor(255, 255, 255), FALSE);
		}
	}

}


//----------------------------------------
//���t���[���Ăԏ���
//----------------------------------------
void CPlayerShot::Step(VECTOR Pos)
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
bool CPlayerShot::RequestShot(const VECTOR &vPos, const VECTOR &vSpeed)
{
	//���łɔ��˂���Ă���
	if (IsActive) return false;

	cPos = vPos;
	cSize = VGet(0.05f, 0.05f, 0.05f);
	cSpeed = vSpeed;
	IsActive = true;

	return true;
	
}


