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
	/*for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Init();
	}*/

	//�x�[�X�N���X�̃|�C���^�z��֑��
	CTurretBase* cTurretBase = new CTurret_Normal;
	cTurretBase->Init();
	//���X�g�ɒǉ�
	Turret_List.push_back(cTurretBase);
}

//�f�[�^���[�h
void CTurretManager::Load()
{
	/*for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Load();
	}*/

	for (auto itr = *Turret_List.begin(); itr != *Turret_List.end(); itr++)
	{
		itr->Load();
	}
}

//�I������
void CTurretManager::Exit()
{
	/*for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Exit();
	}*/

	for (auto itr = *Turret_List.begin(); itr != *Turret_List.end(); itr++)
	{
		itr->Exit();
	}
}

//�J��Ԃ��s������
void CTurretManager::Step(VECTOR Pos)
{
	/*for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Step();
	}

	Update();*/

	for (auto itr = *Turret_List.begin(); itr != *Turret_List.end(); itr++)
	{
		itr->Step();
	}

	Update();
}

//�X�V����
void CTurretManager::Update()
{
	/*for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Update();
	}*/

	for (auto itr = *Turret_List.begin(); itr != *Turret_List.end(); itr++)
	{
		itr->Update();
	}
}

//�`�揈��
void CTurretManager::Draw()
{
	/*for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->Draw();
	}*/

	for (auto itr = *Turret_List.begin(); itr != *Turret_List.end(); itr++)
	{
		itr->Draw();
	}
}

//�^���b�g�ݒu����
void CTurretManager::TurretSpawn(const VECTOR& vPos)
{
	/*for (int Turret_Index = 0; Turret_Index < TURRET_MAX; Turret_Index++)
	{
		cTurretBase[Turret_Index]->TurretSpawn(vPos);
	}*/

	//�x�[�X�N���X�̃|�C���^�z��֑��
	CTurretBase* cTurretBase =  new CTurret_Normal;
	cTurretBase->Init();
	cTurretBase->TurretSpawn(vPos);
	//���X�g�ɒǉ�
	Turret_List.push_back(cTurretBase);
	
	//�폜���Ă���
	delete cTurretBase;

}