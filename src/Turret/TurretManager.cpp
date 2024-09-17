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
	//�x�[�X�N���X�̃|�C���^�z��֑��
	CTurretBase* cTurretBase = new CTurret_Normal;
	cTurretBase->Init();
	//���X�g�ɒǉ�
	Turret_List.push_back(cTurretBase);
}

//�f�[�^���[�h
void CTurretManager::Load()
{
	for (auto itr = Turret_List.begin(); itr != Turret_List.end(); itr++)
	{
		(*itr)->Load();
	}
}

//�I������
void CTurretManager::Exit()
{
	for (auto itr = Turret_List.begin(); itr != Turret_List.end(); itr++)
	{
		(*itr)->Exit();
	}
}

//�J��Ԃ��s������
void CTurretManager::Step(VECTOR Pos)
{
	for (auto itr = Turret_List.begin(); itr != Turret_List.end(); itr++)
	{
		(*itr)->Step();
	}

	Update();
}

//�X�V����
void CTurretManager::Update()
{
	for (auto itr = Turret_List.begin(); itr != Turret_List.end(); itr++)
	{
		(*itr)->Update();
	}
}

//�`�揈��
void CTurretManager::Draw()
{
	for (auto itr = Turret_List.begin(); itr != Turret_List.end(); itr++)
	{
		(*itr)->Draw();
	}
}

//�^���b�g�ݒu����
void CTurretManager::TurretSpawn(const VECTOR& vPos)
{
	//�ϐ�����p�N���X
	CTurretBase* cTurretBase =  new CTurret_Normal;
	cTurretBase->Init();
	cTurretBase->Load();
	cTurretBase->TurretSpawn(vPos);
	//���X�g�ɒǉ�
	Turret_List.push_back(cTurretBase);

}