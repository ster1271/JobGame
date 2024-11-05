#include "TurretManager.h"

static const char TURRET_NORMAL_PATH[] = { "data/Turret/Turret_Normal.x" };

//�R���X�g���N�^
CTurretManager::CTurretManager()
{
	TurretN_Hndl = -1;
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
	if (TurretN_Hndl == -1)
	{
		TurretN_Hndl = MV1LoadModel(TURRET_NORMAL_PATH);
	}
}

//�I������
void CTurretManager::Exit()
{
	for (int TurretIndex = 0; TurretIndex < Turret_List.size(); TurretIndex++)
	{
		Turret_List[TurretIndex]->Exit();
	}
}

//�J��Ԃ��s������
void CTurretManager::Step(CShotManager& cShotManager, CEnemyManager& cEnemyManager)
{
	for (int TurretIndex = 0; TurretIndex < Turret_List.size(); TurretIndex++)
	{
		Turret_List[TurretIndex]->Step(cShotManager, cEnemyManager);
	}

	Update();

}

//�X�V����
void CTurretManager::Update()
{
	for (int TurretIndex = 0; TurretIndex < Turret_List.size(); TurretIndex++)
	{
		Turret_List[TurretIndex]->Update();
	}
}

//�`�揈��
void CTurretManager::Draw()
{
	for (int TurretIndex = 0; TurretIndex < Turret_List.size(); TurretIndex++)
	{
		Turret_List[TurretIndex]->Draw();
	}
}

//�^���b�g�ݒu����
void CTurretManager::TurretSpawn(const VECTOR& vPos)
{
	//�ϐ�����p�N���X
	CTurretBase* cTurretBase =  new CTurret_Normal;
	cTurretBase->Init();
	cTurretBase->Load(TurretN_Hndl);
	cTurretBase->TurretSpawn(vPos);
	
	//���X�g�ɒǉ�
	Turret_List.push_back(cTurretBase);

}
