#include "EnemyManager.h"

//��`
static const char ENEMY_MODEL_PATH01[] = { "data/enemy/Enemy01.x" };
static const char Enemy_MODEL_PATH02[] = { "data/enemy/Enemy02.x" };
static const int WAIT_TIME = 10;		//�G���ēo�ꂷ��܂ł̎���

//�R���X�g���N�^
CEnemyManager::CEnemyManager()
{
	Org_Hndl = -1;
}

//�f�X�g���N�^
CEnemyManager::~CEnemyManager()
{

}

//������
void CEnemyManager::Init()
{
	cnt = 0;
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

	Org_Hndl = MV1LoadModel(Enemy_MODEL_PATH02);
	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		cEnemyBoss[Enemy_Index].Load(Org_Hndl);
	}

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
	VECTOR PastPos = VGet(0.0f, 0.0f, 0.0f);	//�ߋ����W���i�[����
	VECTOR CurrentPos = cBot.GetPos();			//���ݍ��W���i�[����

	if (CWave::GetInstance()->GetIsWave() == true)
	{

		for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
		{
			cEnemy_Normal[Enemy_Index].Step(cBot, cMapManager);
			cEnemyBoss[Enemy_Index].Step(cBot, cMapManager);
		}

		cnt++;
		for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
		{
			//���N�G�X�g
			RequestEnemy(Enemy_Index);
			cnt = 0;
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
}


//�G���N�G�X�g
void CEnemyManager::RequestEnemy(int Index)
{
	if (cnt > WAIT_TIME)		//�N�[���^�C�����Ȃ珈�����Ȃ�
		return;

	//�G1�̃X�|�[��
	VECTOR vPos = VGet(300.0f, 5.0f, 100.0f);
	VECTOR vSpeed = VGet(0.0f, 0.0f, 0.0f);
	cEnemy_Normal[Index].RequestEnemy(vPos, vSpeed);

	//�G2�̃X�|�[��
	vPos = VGet(300.0f, 5.0f, 100.0f);
	vSpeed = VGet(0.0f, 0.0f, 0.0f);
	cEnemyBoss[Index].RequestEnemy(vPos, vSpeed);
	
	cnt = 0;
}