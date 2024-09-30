#include "ShotManager.h"


//��`
static const char PLSHOT_MODEL_PATH[] = { "data/shot/plshot.x" };
static const char TURRETSHOT_MODEL_PATH[] = { "data/shot/plshot.x" };

//------------------------------------
//�R���X�g���N�^
//------------------------------------
CShotManager::CShotManager()
{
	PlayerHndl = -1;
	TurretHndl = -1;
}


//------------------------------------
//�f�X�g���N�^
//------------------------------------
CShotManager::~CShotManager()
{

}


//------------------------------------
//������
//------------------------------------
void CShotManager::Init()
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{
		cPlayerShot[i].Init();
	}

	for (int i = 0; i < TURRET_SHOT_NUM; i++)
	{
		cTurretShot[i].Init();
	}
}


//------------------------------------
//���[�h
//------------------------------------
void CShotManager::Load()
{
	//�I���W�i�����f���̓ǂݍ���
	if (PlayerHndl == -1)
	{
		PlayerHndl = MV1LoadModel(PLSHOT_MODEL_PATH);
	}
	//���f���̕���
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{
		cPlayerShot[i].Load(PlayerHndl);
	}


	//�I���W�i�����f���̓ǂݍ���
	if (TurretHndl == -1)
	{
		TurretHndl = MV1LoadModel(TURRETSHOT_MODEL_PATH);
	}
	//���f���̕���
	for (int i = 0; i < TURRET_SHOT_NUM; i++)
	{
		cTurretShot[i].Load(TurretHndl);
	}
}


//------------------------------------
//�I������
//------------------------------------
void CShotManager::Exit()
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{
		cPlayerShot[i].Exit();
	}

	for (int i = 0; i < TURRET_SHOT_NUM; i++)
	{
		cTurretShot[i].Exit();
	}

	MV1DeleteModel(PlayerHndl);
	PlayerHndl = -1;
	MV1DeleteModel(TurretHndl);
	TurretHndl = -1;
}

//------------------------------------
//���t���[���Ăԏ���
//------------------------------------
void CShotManager::Step(VECTOR Pos)
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{
		cPlayerShot[i].Step(Pos);
	}

	for (int i = 0; i < TURRET_SHOT_NUM; i++)
	{
		cTurretShot[i].Step();
	}
}

//------------------------------------
//�X�V����
//------------------------------------
void CShotManager::Draw()
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{
		cPlayerShot[i].Draw();
	}

	
	for (int i = 0; i < TURRET_SHOT_NUM; i++)
	{
		cTurretShot[i].Draw();
	}
}


//------------------------------------
//�v���C���[�̃V���b�g���N�G�X�g
//------------------------------------
void CShotManager::RequestPlayerShot(const VECTOR& vPos, const VECTOR& vSpeed)
{
	for (int i = 0; i < PL_SHOT_NUM; i++)
	{
		if (cPlayerShot[i].RequestShot(vPos, vSpeed))
		{
			//CSoundManager::Play(CSoundManager::SOUNDID_SE_PLSHOT);
			break;
		}
	}
}


//�^���b�g�̃V���b�g���N�G�X�g
void CShotManager::RequestTurretShot(const VECTOR& vPos, const VECTOR& vSpeed)
{
	for (int i = 0; i < TURRET_SHOT_NUM; i++)
	{
		if (cTurretShot[i].RequestShot(vPos, vSpeed))
		{
			break;
		}
	}
}
