#include "TurretManager.h"
#include "../Debug/DebugString.h"

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


	CDebugString::GetInstance()->AddFormatString(500, 500, "���X�g�̌��F%d", Turret_List.size());

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
	VECTOR vSize = VGet(30.0f, 30.0f, 30.0f);
	bool IsPossible = false;
	int size = 0;

	//�^���b�g�̐ݒu����0����Ȃ��Ƃ�
	if (Turret_List.size() != 0)
	{

		for (int Turret_Index = 0; Turret_Index < Turret_List.size(); Turret_Index++)
		{
			if (!CCollision::CheckHitBoxToBox(vPos, vSize, Turret_List[Turret_Index]->GetPos(), vSize))
			{
				size++;
				IsPossible = true;	//�ݒu�\�t���O��true�ɂ���
			}
			
			if (IsPossible)
			{
				

				//���݂̃T�C�Y���i�[
				int cnt = Turret_List.size();

				//�ϐ�����p�N���X
				CTurretBase* cTurretBase = new CTurret_Normal;
				cTurretBase->Init();
				cTurretBase->Load(TurretN_Hndl);
				cTurretBase->TurretSpawn(vPos);

				//���X�g�ɒǉ�
				Turret_List.push_back(cTurretBase);

				if (cnt != Turret_List.size())
				{
					return;
				}
			}
		}
	}
	//�^���b�g�̐ݒu����0�̎�
	else if(Turret_List.size() == 0)
	{
		//�ϐ�����p�N���X
		CTurretBase* cTurretBase = new CTurret_Normal;
		cTurretBase->Init();
		cTurretBase->Load(TurretN_Hndl);
		cTurretBase->TurretSpawn(vPos);

		//���X�g�ɒǉ�
		Turret_List.push_back(cTurretBase);
	}


	/*
	//�ϐ�����p�N���X
	CTurretBase* cTurretBase = new CTurret_Normal;
	cTurretBase->Init();
	cTurretBase->Load(TurretN_Hndl);
	cTurretBase->TurretSpawn(vPos);

	//���X�g�ɒǉ�
	Turret_List.push_back(cTurretBase);
	*/
}
