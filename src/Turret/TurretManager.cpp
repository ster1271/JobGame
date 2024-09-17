#include "TurretManager.h"

const char TURRET_NORMAL_PATH[] = { "data/Turret/Turret_Normal.x" };

//�R���X�g���N�^
CTurretManager::CTurretManager()
{
	Org_Hndl = -1;
}

//�f�X�g���N�^
CTurretManager::~CTurretManager()
{
}


//������
void CTurretManager::Init()
{
}

//�f�[�^���[�h
void CTurretManager::Load()
{
	//�I���W�i���n���h���Ƀ��[�h
	if (Org_Hndl == -1)
	{
		Org_Hndl = MV1LoadModel(TURRET_NORMAL_PATH);
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
		(*itr)->Step(Pos);
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
	cTurretBase->Load(Org_Hndl);
	cTurretBase->TurretSpawn(vPos);
	
	//���X�g�ɒǉ�
	Turret_List.push_back(cTurretBase);

}