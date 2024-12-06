#include "TurretManager.h"
#include "../Debug/DebugString.h"

const int TURRET_MAX_NUM = 1;		//�^���b�g�̍ő�ݒu��
const char TURRET_NORMAL_PATH[] = { "data/Turret/Turret_Normal.x" };	//�^���b�g�̃��f���p�X
const VECTOR TURRET_SIZE = VGet(30.0f, 30.0f, 30.0f);					//�^���b�g�̃T�C�Y


//�R���X�g���N�^
CTurretManager::CTurretManager()
{
	Turret_Normal_Hndl = -1;
}

//�f�X�g���N�^
CTurretManager::~CTurretManager()
{
}


//������
void CTurretManager::Init()
{
	Turret_List.clear();
}

//�f�[�^���[�h
void CTurretManager::Load()
{
	//�I���W�i���n���h���Ƀ��[�h
	if (Turret_Normal_Hndl == -1)
	{
		Turret_Normal_Hndl = MV1LoadModel(TURRET_NORMAL_PATH);
	}
}

//�I������
void CTurretManager::Exit()
{
	for (int TurretIndex = 0; TurretIndex < Turret_List.size(); TurretIndex++)
	{
		Turret_List[TurretIndex]->Exit();
	}

	Turret_List.clear();
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
	CDebugString::GetInstance()->AddFormatString(500, 525, "�ݒu�ł��鐔�c��F%d", TURRET_MAX_NUM - Turret_List.size());

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
	
	int NotHitCnt = 0;

	//�^���b�g�̐ݒu����0����Ȃ���
	if (Turret_List.size() != 0)
	{
		//�ő吔�ȏ�͐������Ȃ�
		if (Turret_List.size() >= TURRET_MAX_NUM)
			return;

		//�������ĂȂ��Ƃ��ɃJ�E���g���v���X����
		for (int Turret_Index = 0; Turret_Index < Turret_List.size(); Turret_Index++)
		{
			if (!CCollision::CheckHitBoxToBox(vPos, TURRET_SIZE, Turret_List[Turret_Index]->GetPos(), TURRET_SIZE))
			{
				NotHitCnt++;
			}		
		}

		//�J�E���g�����X�g�̃T�C�Y�Ɠ���(�N�Ƃ��������ĂȂ��ꍇ)�Ȃ琶������
		if (NotHitCnt == Turret_List.size())
		{
			//�ϐ�����p�N���X
			CTurretBase* cTurretBase = new CTurret_Normal;
			//��{�����i�[����
			cTurretBase->Init();
			cTurretBase->Load(Turret_Normal_Hndl);
			cTurretBase->TurretSpawn(vPos);

			//���X�g�ɒǉ�
			Turret_List.push_back(cTurretBase);
		}
	}
	//�^���b�g�̐ݒu����0�̎�
	else if(Turret_List.size() == 0)
	{
		//�ϐ�����p�N���X
		CTurretBase* cTurretBase = new CTurret_Normal;
		cTurretBase->Init();
		cTurretBase->Load(Turret_Normal_Hndl);
		cTurretBase->TurretSpawn(vPos);

		//���X�g�ɒǉ�
		Turret_List.push_back(cTurretBase);
	}
}
