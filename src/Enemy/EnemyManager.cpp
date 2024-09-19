#include "EnemyManager.h"

//��`
static const char ENEMY_MODEL_PATH[] = { "data/enemy/enemy.pmx" };
static const int WAIT_TIME = 10;		//�G���ēo�ꂷ��܂ł̎���

//�R���X�g���N�^
CEnemyManager::CEnemyManager()
{
	Org_Hndl = -1;
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
	/*for (int i = 0; i < ENEMY_NUM; i++)
	{
		cEnemyBace[i].Init();
	}*/
	for (int Enemy_Index = 0; Enemy_Index < Enemy_List.size(); Enemy_Index++)
	{
		Enemy_List[Enemy_Index]->Init();
	}
}

//�f�[�^���[�h
void CEnemyManager::Load()
{
	//�I���W�i���f�[�^�ǂݍ���
	if (Org_Hndl == -1)
	{
		Org_Hndl = MV1LoadModel(ENEMY_MODEL_PATH);
	}

	for (int Enemy_Index = 0; Enemy_Index < Enemy_List.size(); Enemy_Index++)
	{
		Enemy_List[Enemy_Index]->Draw();
	}

	/*for (int i = 0; i < ENEMY_NUM; i++)
	{
		cEnemyBace[i].Load(Org_Hndl);
	}*/
}

//�I������
void CEnemyManager::Exit()
{
	/*for (int i = 0; i < ENEMY_NUM; i++)
	{
		cEnemyBace[i].Exit();
	}*/

	for (int Enemy_Index = 0; Enemy_Index < Enemy_List.size(); Enemy_Index++)
	{
		Enemy_List[Enemy_Index]->Exit();
	}

	if (Org_Hndl != -1)
	{
		MV1DeleteModel(Org_Hndl);
		Org_Hndl = -1;
	}
}

//���t���[���Ăԏ���
void CEnemyManager::Step()
{
	int iEnemyCnt = 0;	//�G�̏o����
	//�G�̈ړ�����
	for (int Enemy_Index = 0; Enemy_Index < Enemy_List.size(); Enemy_Index++)
	{
		Enemy_List[Enemy_Index]->Step();
		if (Enemy_List[Enemy_Index]->GetActive())
		{
			iEnemyCnt++;
			if (iEnemyCnt == 10)
			{
				iEnemyCnt = 10;
			}
		}
	}

	/*for (int i = 0; i < ENEMY_NUM; i++)
	{
		cEnemyBace[i].Step();
		if (cEnemyBace[i].GetActive())
		{
			iEnemyCnt++;
		}
	}*/

	//�G�̏o��
	m_iWaitCnt--;
	if (m_iWaitCnt < 0 || iEnemyCnt == 0)
	{
		/*RequestEnemy();*/
		m_iWaitCnt = WAIT_TIME;
	}

	/*if (m_iWaitCnt < 0 || iEnemyCnt == 0)
	{
		RequestEnemy();
		m_iWaitCnt = WAIT_TIME;
	}*/
}

//�`�揈��
void CEnemyManager::Draw()
{
	for (int Enemy_Index = 0; Enemy_Index < Enemy_List.size(); Enemy_Index++)
	{
		Enemy_List[Enemy_Index]->Draw();
	}

	/*for (int i = 0; i < ENEMY_NUM; i++)
	{
		cEnemyBace[i].Draw();
	}*/
}


//�G���N�G�X�g
void CEnemyManager::RequestEnemy()
{
	VECTOR vPos = VGet((float)GetRand(200) - 100.0f, 5.0f , 200.0f);
	VECTOR vSpeed = VGet(0.0f, 0.0f, -0.1f);

	//�ϐ�����p�N���X
	CEnemyBase* cEnemyBase = new CEnemy_Normal;
	cEnemyBase->Init();
	cEnemyBase->Load(Org_Hndl);
	cEnemyBase->RequestEnemy(vPos, vSpeed);

	//���X�g�ɒǉ�
	Enemy_List.push_back(cEnemyBase);
}