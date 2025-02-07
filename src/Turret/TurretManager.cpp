#include "TurretManager.h"
#include "../Debug/DebugString.h"

const int TURRET_MAX_NUM = 10;		//�^���b�g�̍ő�ݒu��
const char TURRET_NORMAL_PATH[] = { "data/Turret/Turret_Normal.x" };	//�^���b�g�̃��f���p�X
const VECTOR TURRET_SIZE = VGet(30.0f, 30.0f, 30.0f);					//�^���b�g�̃T�C�Y
const VECTOR SPAWN_PLACE_SIZE = VGet(30.0f, 10.0f, 30.0f);				//�ݒu�ꏊ�̃T�C�Y


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
	PlaceList.clear();
}

//�f�[�^���[�h
void CTurretManager::Load()
{
	//�I���W�i���n���h���Ƀ��[�h
	if (Turret_Normal_Hndl == -1)
	{
		Turret_Normal_Hndl = MV1LoadModel(TURRET_NORMAL_PATH);
	}

	LoadTurretSpawn();
}

//�I������
void CTurretManager::Exit()
{
	for (int TurretIndex = 0; TurretIndex < Turret_List.size(); TurretIndex++)
	{
		Turret_List[TurretIndex]->Exit();
	}

	Turret_List.clear();

	for (int Index = 0; Index < PlaceList.size(); Index++)
	{
		//�R�s�[���f���̍폜
		MV1DeleteModel(PlaceList[Index].iHndl);
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

	for (int Index = 0; Index < PlaceList.size(); Index++)
	{
		MV1SetPosition(PlaceList[Index].iHndl, PlaceList[Index].vPos);		//���W�̍X�V
		MV1SetScale(PlaceList[Index].iHndl, PlaceList[Index].vSize);		//�T�C�Y�̍X�V
		MV1SetRotationXYZ(PlaceList[Index].iHndl, VGet(0.0f, 0.0f, 0.0f));	//��]�l�̍X�V
	}

	//CDebugString::GetInstance()->AddFormatString(500, 500, "���X�g�̌��F%d", Turret_List.size());
	//CDebugString::GetInstance()->AddFormatString(500, 525, "�ݒu�ł��鐔�c��F%d", TURRET_MAX_NUM - Turret_List.size());

}

//�`�揈��
void CTurretManager::Draw()
{
	for (int TurretIndex = 0; TurretIndex < Turret_List.size(); TurretIndex++)
	{
		Turret_List[TurretIndex]->Draw();
	}

	for (int Index = 0; Index < PlaceList.size(); Index++)
	{
		MV1DrawModel(PlaceList[Index].iHndl);
	}
}

//�^���b�g�ݒu����
void CTurretManager::TurretSpawn(const VECTOR& vPos)
{

	for (int SpawnIndex = 0; SpawnIndex < PlaceList.size(); SpawnIndex++)
	{
		//�v���C���[�Ɛݒu�ʒu�Ƃ̓����蔻����Ƃ�
		if (CCollision::CheckHitBoxToBox(vPos, VGet(15.0f, 30.0f, 15.0f), PlaceList[SpawnIndex].vPos, SPAWN_PLACE_SIZE))
		{
			//�ݒu�t���O��false�Ȃ�ݒu����
			if (PlaceList[SpawnIndex].IsInstall)
				continue;

			//�ϐ�����p�N���X
			CTurretBase* cTurretBase = new CTurret_Normal;
			//��{�����i�[����
			cTurretBase->Init();
			cTurretBase->Load(Turret_Normal_Hndl);
			cTurretBase->TurretSpawn(PlaceList[SpawnIndex].vPos);

			//���X�g�ɒǉ�
			Turret_List.push_back(cTurretBase);
			PlaceList[SpawnIndex].IsInstall = true;
		}
	}
}


//�^���b�g�ݒu�ꏊ�ǂݍ��ݏ���
void CTurretManager::LoadTurretSpawn()
{
	FILE* fp;
	int Pos[3];
	TurretPlaceInfo tmpInfo;

	int Hndl = MV1LoadModel("data/Turret/TS_Place.x");

	fopen_s(&fp, TURRETPLACEPATH[0], "r");		//�t�@�C���ǂݍ���

	//���@1
	if (fp != nullptr)
	{

		while (fscanf_s(fp, "%d,%d,%d",&Pos[0], &Pos[1], &Pos[2]) != EOF)
		{
			tmpInfo.vPos = VGet(Pos[0], Pos[1], Pos[2]);
			tmpInfo.vSize = VGet(0.1f, 0.1f, 0.1f);
			tmpInfo.IsInstall = false;
			tmpInfo.iHndl = MV1DuplicateModel(Hndl);

			PlaceList.push_back(tmpInfo);
		}
	}

	for (int Index = 0; Index < PlaceList.size(); Index++)
	{
		MV1SetPosition(PlaceList[Index].iHndl, PlaceList[Index].vPos);		//���W�̍X�V
		MV1SetScale(PlaceList[Index].iHndl, PlaceList[Index].vSize);		//�T�C�Y�̍X�V
		MV1SetRotationXYZ(PlaceList[Index].iHndl, VGet(0.0f, 0.0f, 0.0f));	//��]�l�̍X�V
	}

	fclose(fp);
}
