#include "EnemyManager.h"

//��`
static const char ENEMY_MODEL_PATH[] = { "Data/enemy/enemy.pmx" };
static const int WAIT_TIME = 10;		//�G���ēo�ꂷ��܂ł̎���

//�R���X�g���N�^
CEnemyManager::CEnemyManager()
{
	m_iWaitCnt = 0;
}

//�f�X�g���N�^
CEnemyManager::~CEnemyManager()
{

}

//������
void CEnemyManager::Init()
{
	m_iWaitCnt = WAIT_TIME;
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		cEnemyBace[i].Init();
	}
}

//�f�[�^���[�h
void CEnemyManager::Load()
{
	//�I���W�i���f�[�^�ǂݍ���	
	int iHndl = MV1LoadModel(ENEMY_MODEL_PATH);
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		cEnemyBace[i].Load(iHndl);
	}
}

//�I������
void CEnemyManager::Exit()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		cEnemyBace[i].Exit();
	}
}

//���t���[���Ăԏ���
void CEnemyManager::Step()
{
	int iEnemyCnt = 0;	//�G�̏o����
	//�G�̈ړ�����
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		cEnemyBace[i].Step();
		if (cEnemyBace[i].IsActive())
		{
			iEnemyCnt++;
		}
	}

	//�G�̏o��
	m_iWaitCnt--;
	if (m_iWaitCnt < 0 || iEnemyCnt == 0)
	{
		RequestEnemy();
		m_iWaitCnt = WAIT_TIME;
	}
}

//�`�揈��
void CEnemyManager::Draw()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		cEnemyBace[i].Draw();
	}
}


//�G���N�G�X�g
void CEnemyManager::RequestEnemy()
{
	VECTOR vPos = VGet((float)GetRand(200) - 100.0f, 0, 200.0f);
	VECTOR vSpeed = VGet(0.0f, 0.0f, -0.1f);
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (cEnemyBace[i].RequestEnemy(vPos, vSpeed))
		{
			break;
		}
	}
}