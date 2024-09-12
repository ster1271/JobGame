#include "Turret_Normal.h"

//�R���X�g���N�^
CTurret_Normal::CTurret_Normal()
{
	Attack = 0.0f;
}

//�f�X�g���N�^
CTurret_Normal::~CTurret_Normal()
{
	Attack = 0.0f;
}

//������
void CTurret_Normal::Init()
{
	TurretBase::Init();
	Attack = 0.0f;
}

//�f�[�^���[�h
void CTurret_Normal::Load(const char FILEPATH[])
{
	//���f���̓ǂݍ���
	iHndl = MV1LoadModel(FILEPATH);
}

//�`��
void CTurret_Normal::Draw()
{
	if (iHndl != -1)
	{
		MV1DrawModel(iHndl);
	}

}

//���t���[���s������
void CTurret_Normal::Step()
{
	if (!IsActive) return;

	//���W�ɑ��x�����Z

	
}

//�㏈��
void CTurret_Normal::Exit()
{
	TurretBase::Exit();
	Attack = 0.0f;
}