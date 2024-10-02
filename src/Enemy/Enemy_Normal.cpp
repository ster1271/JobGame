#include "Enemy_Normal.h"

const int MAX_LIFE (3);		//�ő�̗�

//�R���X�g���N�^
CEnemy_Normal::CEnemy_Normal()
{
	memset(&Respown_Pos, 0, sizeof(VECTOR));
}
//�f�X�g���N�^
CEnemy_Normal::~CEnemy_Normal()
{
}

//������
void CEnemy_Normal::Init()
{
	CEnemyBase::Init();
}

//�f�[�^���[�h
void CEnemy_Normal::Load(int Hndl)
{
	iHndl = MV1DuplicateModel(Hndl);
}

//�`��
void CEnemy_Normal::Draw()
{
	if (IsActive == false)
		return;

	MV1DrawModel(iHndl);
}

//���t���[���s������
void CEnemy_Normal::Step()
{
	if (!IsActive)
	{
		return;
	}

	//���W�ɑ��x�����Z
	cPos = VSub(cPos, cSpeed);
	//���͈͂𒴂��������
	float fLength = 100.0f;
	if (cPos.x > Respown_Pos.x + fLength || cPos.x < Respown_Pos.x -fLength
		|| cPos.z > Respown_Pos.z + fLength || cPos.z < Respown_Pos .z -fLength)
	{
		IsActive = false;
	}

	/*
	//�{�b�g����w��̒n�_�֍s���x�N�g�����v�Z
	VECTOR Vtmp;
	Vtmp.x = Set_Point.x - cPos.x;
	Vtmp.y = 0.0f;
	Vtmp.z = Set_Point.z - cPos.z;

	//�i�s�����̂ǂ��瑤�ɂ���̂��𒲂ׂ�
	float Dir = 0.0f;

	VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);	//�{�b�g�̈ړ��x�N�g��
	vSpd.x = sinf(cRotate.y) * -1.0f;
	vSpd.y = 0.0f;
	vSpd.z = cosf(cRotate.y) * -1.0f;

	//�O�όv�Z
	Dir = Vtmp.x * vSpd.z - vSpd.x * Vtmp.z;
	//�m�F�p
	tmp_dir = Dir;

	//��]����p�x�����߂�
	if (Dir >= 0.0f)
	{
		cRotate.y += 0.05f;
	}
	else if (Dir < 0.0f)
	{
		cRotate.y -= 0.05f;
	}

	//���W�ɑ��x�����Z����
	cPos.x += sinf(cRotate.y) * -0.1f;
	cPos.z += cosf(cRotate.y) * -0.1f;
	*/

	//�X�V����
	Update();
}

//�㏈��
void CEnemy_Normal::Exit()
{
	CEnemyBase::Exit();
	memset(&Respown_Pos, 0, sizeof(VECTOR));

}

//���N�G�X�g
bool CEnemy_Normal::RequestEnemy(const VECTOR& vPos, const VECTOR& vSpeed)
{
	//���łɏo�����Ă���
	if (IsActive)
	{
		return false;
	}

	cPos = vPos;
	Respown_Pos = cPos;
	cSize = VGet(0.1f, 0.1f, 0.1f);
	cRotate = VGet(0.0f, -DX_PI_F / 2, 0.0f);
	cSpeed = vSpeed;
	Life = MAX_LIFE;
	IsActive = true;

	return true;
}