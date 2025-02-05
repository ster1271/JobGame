#include "EnemyManager.h"

//��`
static const char ENEMY_MODEL_PATH01[] = { "data/enemy/Enemy01.x" };
static const char Enemy_MODEL_PATH02[] = { "data/enemy/Enemy02.x" };
static const int WAIT_TIME = 200;		//�G���ēo�ꂷ��܂ł̎���
static const int RESPAWN_MAX_NUM = 15;	//�ʏ�E�F�[�u�ő�o����

//�R���X�g���N�^
CEnemyManager::CEnemyManager()
{
	Org_Hndl = -1;
}

//�f�X�g���N�^
CEnemyManager::~CEnemyManager(){}

//������
void CEnemyManager::Init()
{
	Coolcnt = WAIT_TIME;
	RespawnCount = RESPAWN_MAX_NUM;
	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		cEnemy_Normal[Enemy_Index].Init();
		cEnemyBoss[Enemy_Index].Init();
	}
}

//�f�[�^���[�h
void CEnemyManager::Load()
{
	//�I���W�i���f�[�^�ǂݍ���
	if (Org_Hndl == -1)
	{
		Org_Hndl = MV1LoadModel(ENEMY_MODEL_PATH01);
	}

	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		cEnemy_Normal[Enemy_Index].Load(Org_Hndl);
	}

	/*Org_Hndl = MV1LoadModel(Enemy_MODEL_PATH02);
	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		cEnemyBoss[Enemy_Index].Load(Org_Hndl);
	}*/

}

//�I������
void CEnemyManager::Exit()
{

	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		cEnemy_Normal[Enemy_Index].Exit();
		cEnemyBoss[Enemy_Index].Exit();
	}

	if (Org_Hndl != -1)
	{
		MV1DeleteModel(Org_Hndl);
		Org_Hndl = -1;
	}
}

//���t���[���Ăԏ���
void CEnemyManager::Step(CBot& cBot, CMapManager cMapManager)
{
	//�E�F�[�u���̂ݏ������s��
	if (CWave::GetInstance()->GetIsWave() == true)
	{
		if (DeathCount >= RESPAWN_MAX_NUM)
		{
			CWave::GetInstance()->WaveStateChange(STATE_WAVE_END);
			DeathCount = 0;
			RespawnCount = RESPAWN_MAX_NUM;
			Coolcnt = WAIT_TIME;
		}

		int iEnemyCnt = 0;	//�G�̏o����
		for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
		{
			if (cEnemy_Normal[Enemy_Index].GetActive())
			{
				iEnemyCnt++;
			}
			cEnemy_Normal[Enemy_Index].Step(cBot, cMapManager);
			cEnemy_Normal[Enemy_Index].Update();
		}

		//�G�̏o��
		Coolcnt--;

		//�����ԏo�����Ă��Ȃ����A��������0�̎����N�G�X�g������
		if (Coolcnt < 0 || iEnemyCnt == 0)
		{
			if (CWave::GetInstance()->GetWaveState() == STATE_WAVE_NORMAL)
			{
				//��萔���������炻��ȏ㏈�����Ȃ�
				if (RespawnCount <= 0)
					return;

				RequestEnemy();
				Coolcnt = WAIT_TIME;
			}
			/*else if (CWave::GetInstance()->GetWaveState() == STATE_WAVE_BOTMOVE)
			{
				RequestEnemy();
				Coolcnt = WAIT_TIME;
			}*/
		}
	}
}

//�`�揈��
void CEnemyManager::Draw()
{
	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		cEnemy_Normal[Enemy_Index].Draw();
		//cEnemyBoss[Enemy_Index].Draw();
	}
	
	CDraw3D::DrawBox3D(VGet(50.0f, 5.0f, 700.0f), VGet(50.0f, 50.0f, 50.0f));
}


//�G���N�G�X�g
void CEnemyManager::RequestEnemy()
{
	//�G1�̃X�|�[��(�ǂݍ��݂Őݒ肷��)
	VECTOR vPos = VGet(50.0f, 5.0f, 700.0f);
	VECTOR vSpeed = VGet(0.0f, 0.0f, 0.0f);

	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		if (cEnemy_Normal[Enemy_Index].RequestEnemy(vPos, vSpeed))
		{
			RespawnCount--;
			break;
		}
	}
}