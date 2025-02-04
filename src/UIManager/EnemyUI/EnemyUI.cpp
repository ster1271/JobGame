#include "EnemyUI.h"
#include "../../Enemy/Enemy_Normal.h"

const char ENEMY_LIFE_PATH[] = { "data/UI/enemy/EnemyLife.png" };
const char ENEMY_MAXLIFE_PATH[] = { "data/UI/enemy/EnemyMaxLife.png" };


//�R���X�g���N�^�E�f�X�g���N�^
CEnemyUI::CEnemyUI(){}
CEnemyUI::~CEnemyUI(){}

//������
void CEnemyUI::Init()
{
	MaxLifeHndl = -1;
	LifeHndl = -1;
}

//�ǂݍ���
void CEnemyUI::Load()
{
	MaxLifeHndl = LoadGraph(ENEMY_MAXLIFE_PATH);
	LifeHndl = LoadGraph(ENEMY_LIFE_PATH);
}

//���t���[���s������
void CEnemyUI::Step(CEnemyManager& cEnemyManager)
{
	for (int EnemyIndex = 0; EnemyIndex < ENEMY_MAXNUM; EnemyIndex++)
	{
		cEnemy[EnemyIndex] = cEnemyManager.GetEnemy(EnemyIndex);
	}
}

//�`��
void CEnemyUI::Draw()
{
	for (int EnemyIndex = 0; EnemyIndex < ENEMY_MAXNUM; EnemyIndex++)
	{
		if (!cEnemy[EnemyIndex].GetActive())
			continue;

		DrawRectGraph(cEnemy[EnemyIndex].GetPosition().x / 2, cEnemy[EnemyIndex].GetPosition().z,
			0, 0, ENEMY_MAX_LIFE, 30, MaxLifeHndl, true, false);
		DrawRectGraph(cEnemy[EnemyIndex].GetPosition().x / 2, cEnemy[EnemyIndex].GetPosition().z,
			0, 0, cEnemy[EnemyIndex].GetLife(), 30, LifeHndl, true, false);

	}

}

//�㏈��
void CEnemyUI::Exit()
{
	MaxLifeHndl = -1;
	LifeHndl = -1;
}