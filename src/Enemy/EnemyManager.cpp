#include "EnemyManager.h"

//��`
static const char ENEMY_MODEL_PATH01[] = { "data/enemy/Enemy01.x" };
static const char Enemy_MODEL_PATH02[] = { "data/enemy/Enemy02.x" };
static const int COOL_MAX_TIME = 200;		//�G���ēo�ꂷ��܂ł̎���
static const int RESPAWN_MAX_NUM = 20;	//�ʏ�E�F�[�u�ő�o����

const VECTOR EnemySpawn[MAP_MAX_NUM][3] =
{
	VGet(50.0f, 5.0f, 700.0f), VGet(800.0f, 5.0f, 50.0f), VGet(500.0f, 5.0f, 900.0f)
};


//�R���X�g���N�^
CEnemyManager::CEnemyManager()
{
	
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
}

//�f�[�^���[�h
void CEnemyManager::Load()
{
	int Hndl = MV1LoadModel(ENEMY_MODEL_PATH01);

	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		cEnemy_Normal[Enemy_Index].Load(Hndl);
	}
}

//�I������
void CEnemyManager::Exit()
{
	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		cEnemy_Normal[Enemy_Index].Exit();
	}
}

//���t���[���Ăԏ���
void CEnemyManager::Step(VECTOR vPos, CMapManager cMapManager)
{
	int iEnemyCnt = 0;	//�G�̏o����
	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		if (cEnemy_Normal[Enemy_Index].GetActive())
		{
			iEnemyCnt++;
		}
		cEnemy_Normal[Enemy_Index].Step(vPos, cMapManager);
		cEnemy_Normal[Enemy_Index].Update();
	}

	//�G�̏o��
	//CoolTime--;

	//�����ԏo�����Ă��Ȃ����A��������0�̎����N�G�X�g������
	if (CoolTime < 0 || iEnemyCnt == 0)
	{
		//RequestEnemy();
		CoolTime = COOL_MAX_TIME;
	}
}


//�`�揈��
void CEnemyManager::Draw()
{
	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		cEnemy_Normal[Enemy_Index].Draw();
	}

	CDebugString::GetInstance()->AddFormatString(0, 400, "�����ł��鐔�F%d", ReqestCount);
	
	for (int i = 0; i < 3; i++)
	{
		CDraw3D::DrawBox3D(EnemySpawn[0][i], VGet(50.0f, 50.0f, 50.0f));
	}
}


//�G���N�G�X�g
void CEnemyManager::RequestEnemy()
{
	//�G1�̃X�|�[��(�ǂݍ��݂Őݒ肷��)
	VECTOR vPos = VGet(50.0f, 5.0f, 700.0f);
	VECTOR vSpeed = VGet(0.0f, 0.0f, 0.0f);

	for (int Enemy_Index = 0; Enemy_Index < ENEMY_MAXNUM; Enemy_Index++)
	{
		if (cEnemy_Normal[Enemy_Index].RequestEnemy(EnemySpawn[0][1], vSpeed))
		{
			ReqestCount--;
			break;
		}
	}
}