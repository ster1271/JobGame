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
	preLife[ENEMY_MAXNUM] = { 0 };
	CurrentLife[ENEMY_MAXNUM] = { 0 };
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
		preLife[EnemyIndex] = CurrentLife[EnemyIndex];

		CurrentLife[EnemyIndex] = cEnemy[EnemyIndex].GetLife();
	}
}

//�`��
void CEnemyUI::Draw()
{
	for (int EnemyIndex = 0; EnemyIndex < ENEMY_MAXNUM; EnemyIndex++)
	{
		if (!cEnemy[EnemyIndex].GetActive())
			continue;

		VECTOR  DrawPos = cEnemy[EnemyIndex].GetPosition();
		DrawPos.y = 20.0f;
		
		//float a = preLife[EnemyIndex] - CurrentLife[EnemyIndex];
		//DrawPos.x = DrawPos.x + a * 5;
		
		DrawBillboard3D(DrawPos, 0.5f, 0.5f, 25, 0.0f, MaxLifeHndl, true);
		DrawBillboard3D(DrawPos, 0.5f, 0.5f, cEnemy[EnemyIndex].GetLife(), 0.0f, LifeHndl, true);
	}


}

//�㏈��
void CEnemyUI::Exit()
{
	MaxLifeHndl = -1;
	LifeHndl = -1;
}