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

}

//�`��
void CTurret_Normal::Draw()
{

}

//���t���[���s������
void CTurret_Normal::Step()
{

}

//�㏈��
void CTurret_Normal::Exit()
{
	TurretBase::Exit();
	Attack = 0.0f;
}