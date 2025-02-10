#include "EnemyManager.h"

//��`
static const char ENEMY_MODEL_PATH01[] = { "data/enemy/Enemy01.x" };
static const char Enemy_MODEL_PATH02[] = { "data/enemy/Enemy02.x" };
static const int COOL_MAX_TIME = 200;		//�G���ēo�ꂷ��܂ł̎���
static const int RESPAWN_MAX_NUM = 20;	//�ʏ�E�F�[�u�ő�o����

//�R���X�g���N�^
CEnemyManager::CEnemyManager()
{
	OrgHndl = -1;
}

//�f�X�g���N�^
CEnemyManager::~CEnemyManager(){}

//������
void CEnemyManager::Init()
{
	CoolTime = COOL_MAX_TIME;
	ReqestCount = RESPAWN_MAX_NUM;
	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		cEnemy_Normal[Enemy_Index].Init();
	}

	tmpList.clear();
}

//�f�[�^���[�h
void CEnemyManager::Load()
{
	//�I���W�i���f�[�^�ǂݍ���
	if (OrgHndl == -1)
	{
		OrgHndl = MV1LoadModel(ENEMY_MODEL_PATH01);
	}

	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		cEnemy_Normal[Enemy_Index].Load(OrgHndl);
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
	}

	if (OrgHndl != -1)
	{
		MV1DeleteModel(OrgHndl);
		OrgHndl = -1;
	}
}

//���t���[���Ăԏ���
void CEnemyManager::Step(VECTOR vPos, CMapManager cMapManager)
{
	//�E�F�[�u���̂ݏ������s��
	if (CWave::GetInstance()->GetIsWave() == true)
	{
		if (DeathCount >= RESPAWN_MAX_NUM)
		{
			CWave::GetInstance()->WaveStateChange(STATE_WAVE_END);
			DeathCount = 0;
			ReqestCount = RESPAWN_MAX_NUM;
			CoolTime = COOL_MAX_TIME;
		}


		switch (CWave::GetInstance()->GetWaveState())
		{
		case STATE_WAVE_NORMAL:
			if (tmpList.empty() == true)
			{
				tmpList = CRoute_Search::GetInstance()->Route_Search(VGet(50.0f, 5.0f, 700.0f), vPos, cMapManager);
			}
			break;

		case STATE_WAVE_BOTMOVE:

			break;

		default:
			break;
		}

		int iEnemyCnt = 0;	//�G�̏o����
		for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
		{
			if (cEnemy_Normal[Enemy_Index].GetActive())
			{
				iEnemyCnt++;
			}
			cEnemy_Normal[Enemy_Index].Step(vPos, cMapManager, tmpList);
			cEnemy_Normal[Enemy_Index].Update();
		}

		//�G�̏o��
		CoolTime--;

		//�����ԏo�����Ă��Ȃ����A��������0�̎����N�G�X�g������
		if (CoolTime < 0 || iEnemyCnt == 0)
		{
			if (CWave::GetInstance()->GetWaveState() == STATE_WAVE_NORMAL)
			{
				//��萔���������炻��ȏ㏈�����Ȃ�
				if (ReqestCount <= 0)
					return;

				RequestEnemy();
				CoolTime = COOL_MAX_TIME;
			}
			else
			{
				RequestEnemy();
				CoolTime = COOL_MAX_TIME;
			}
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

	CDebugString::GetInstance()->AddFormatString(0, 400, "�����ł��鐔�F%d", ReqestCount);
	
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
			ReqestCount--;
			break;
		}
	}
}