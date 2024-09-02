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
	//������
	memset(&m_vPos, 0, sizeof(VECTOR));
	memset(&m_vSpeed, 0, sizeof(VECTOR));
	Yspeed = 0.0f;
	iHndl = -1;
	isActive = false;
	m_Radius = 0;

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
	memset(&m_vPos, 0, sizeof(VECTOR));
	memset(&m_vSpeed, 0, sizeof(VECTOR));
	Yspeed = 0.0f;
	iHndl = -1;
	isActive = false;
	m_Radius = SHOTRADIUS;

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
	if (isActive)
	{
		MV1DrawModel(iHndl);

		VECTOR vPos = m_vPos;
		

		DrawFormatString(500, 0, GetColor(255, 0, 0), "X���W�F%f", m_vPos.x);
		DrawFormatString(500, 15, GetColor(255, 0, 0), "Y���W�F%f", m_vPos.y);
		DrawFormatString(500, 30, GetColor(255, 0, 0), "Z���W�F%f", m_vPos.z);
		/*DrawSphere3D(vPos, m_Radius, 16, GetColor(255, 255, 255), GetColor(255, 255, 255), FALSE);*/

	}

	
}


//----------------------------------------
//���t���[���Ăԏ���
//----------------------------------------
void CShot::Step(VECTOR Pos)
{
	if (!isActive) return;

	//���W�ɑ��x�����Z
	m_vPos = VAdd(m_vPos, m_vSpeed);
	m_vPos.y += Yspeed;
	Yspeed -= GRAVITY;


	//���͈͂𒴂��������
	float fLength =	600;

	if (m_vPos.x > Pos.x + fLength || m_vPos.x < Pos.x -fLength
		|| m_vPos.z > Pos.z + fLength || m_vPos.z < Pos.z - fLength
		|| m_vPos.y < 0.0f)
	{
		isActive = false;
	}

	//���W�X�V
	MV1SetPosition(iHndl, m_vPos);
	MV1SetScale(iHndl, VGet(0.05f, 0.05f, 0.05f));
}


//----------------------------------------
//���N�G�X�g
//----------------------------------------
bool CShot::RequestShot(const VECTOR &vPos, const VECTOR &vSpeed , const float&YSpeed)
{
	//���łɔ��˂���Ă���
	if (isActive) return false;

	m_vPos = vPos;
	m_vSpeed = vSpeed;
	Yspeed = YSpeed;
	isActive = true;

	return true;
	
}


