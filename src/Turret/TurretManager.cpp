#include "TurretManager.h"



//�R���X�g���N�^
CTurretManager::CTurretManager()
{
}

//�f�X�g���N�^
CTurretManager::~CTurretManager()
{
}


//������
void CTurretManager::Init()
{
	cTurret_Normal.Init();
}

//�f�[�^���[�h
void CTurretManager::Load()
{
	cTurret_Normal.Load();
}

//�I������
void CTurretManager::Exit()
{
	cTurret_Normal.Exit();
}

//�J��Ԃ��s������
void CTurretManager::Step(VECTOR Pos)
{

	cTurret_Normal.Step();

	//�X�V����
	Update();
}

//�X�V����
void CTurretManager::Update()
{
	cTurret_Normal.Update();
}

//�`�揈��
void CTurretManager::Draw()
{
	cTurret_Normal.Draw();
}

//�^���b�g�ݒu����
void CTurretManager::TurretSpawn(const VECTOR& vPos)
{
	cTurret_Normal.TurretSpawn(vPos);
}