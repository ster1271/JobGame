#include "EnemyManager.h"

//��`
static const char ENEMY_MODEL_PATH[] = { "data/enemy/enemy.pmx" };
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

}

//�I������
void CEnemyManager::Exit()
{

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
	
	//�G�̈ړ�����
	for (int Enemy_Index = 0; Enemy_Index < Enemy_List.size(); Enemy_Index++)
	{
		Enemy_List[Enemy_Index]->Step();
	}

	//�G�̏o��
	if (Enemy_List.size() < ENEMY_NUM)
	{
		RequestEnemy();
	}

	//for (int Enemy_Index = 0; Enemy_Index < Enemy_List.size(); Enemy_Index++)
	//{
	//	if (!Enemy_List[Enemy_Index]->GetActive())
	//	{
	//		//�ė��p�̂��ߏ��������Ă���
	//		Enemy_List[Enemy_Index]->Init();
	//	}	
	//}
}

//�`�揈��
void CEnemyManager::Draw()
{
	for (int Enemy_Index = 0; Enemy_Index < Enemy_List.size(); Enemy_Index++)
	{
		Enemy_List[Enemy_Index]->Draw();
	}

}


//�G���N�G�X�g
void CEnemyManager::RequestEnemy()
{
	VECTOR vPos = VGet(0.0f, 5.0f , GetRand(200.0f)+ 100.0f);
	VECTOR vSpeed = VGet(0.0f, 0.0f, 1.0f);

	//�ϐ�����p�N���X
	CEnemyBase* cEnemyBase = new CEnemy_Normal;
	cEnemyBase->Init();
	cEnemyBase->Load(Org_Hndl);
	cEnemyBase->RequestEnemy(vPos, vSpeed);

	
	
	//���X�g�ɒǉ�
	Enemy_List.push_back(cEnemyBase);

}