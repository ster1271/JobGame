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
	for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index] = new CTurret_Normal;
		cTurretBase[Turret_Index]->Init();
	}
}

//�f�[�^���[�h
void CTurretManager::Load()
{
	for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Load();
	}
}

//�I������
void CTurretManager::Exit()
{
	for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Exit();
	}
}

//�J��Ԃ��s������
void CTurretManager::Step(VECTOR Pos)
{
	for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Step();
	}

	Update();
}

//�X�V����
void CTurretManager::Update()
{
	for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Update();
	}
}

//�`�揈��
void CTurretManager::Draw()
{
	for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Draw();
	}
}

//�^���b�g�ݒu����
void CTurretManager::TurretSpawn(const VECTOR& vPos)
{
	for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->TurretSpawn(vPos);
	}
}