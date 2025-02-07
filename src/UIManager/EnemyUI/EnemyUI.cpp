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
	PreLife[ENEMY_MAXNUM] = { 0 };
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
		PreLife[EnemyIndex] = CurrentLife[EnemyIndex];

		CurrentLife[EnemyIndex] = cEnemy[EnemyIndex].GetLife();

		Alpha_Change(EnemyIndex);
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
		DrawPos.x += 10.0f;
		DrawPos.y = 30.0f;

		SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, Alpha[EnemyIndex]);
		DrawModiBillboard3D(DrawPos, 
			0.0f, 5.0f,
			ENEMY_MAX_LIFE, 5.0f,
			ENEMY_MAX_LIFE, 0.0f,
			0.0f, 0.0f,
			MaxLifeHndl, TRUE);
		DrawModiBillboard3D(DrawPos,
			0.0f, 5.0f,
			cEnemy[EnemyIndex].GetLife(), 5.0f,
			cEnemy[EnemyIndex].GetLife(), 0.0f,
			0.0f, 0.0f,
			LifeHndl, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	}


}

//�㏈��
void CEnemyUI::Exit()
{
	MaxLifeHndl = -1;
	LifeHndl = -1;
}


//�����x�ύX
void CEnemyUI::Alpha_Change(int Index)
{
	//���C�t�������Ȃ�
	if (CurrentLife[Index] == PreLife[Index])
	{
		//�J�E���g����
		Count[Index]++;
	}
	else
	{
		Alpha[Index] = 200;
		Count[Index] = 0;
	}

	if (Count[Index] > 100)
	{
		//�����x��������
		Alpha[Index] -= 2;
		if (Alpha[Index] < 0)
		{
			Alpha[Index] = 0;
			Count[Index] = 0;
		}
	}

}
