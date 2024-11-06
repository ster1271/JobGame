#include "Turret_Normal.h"

const float MAX_LIFE = 50.0f;
const float ATTACK = 5.0f;
const int MAX_COOL_TIME = 30;

//�R���X�g���N�^
CTurret_Normal::CTurret_Normal()
{
	Attack = 0.0f;
}

//�f�X�g���N�^
CTurret_Normal::~CTurret_Normal()
{
}

//������
void CTurret_Normal::Init()
{
	CTurretBase::Init();
	Attack = 0.0f;
	CoolTime = 0;
}

//�f�[�^���[�h
void CTurret_Normal::Load(int Hndl)
{
	//�R�s�[���f�������[�h
	iHndl = MV1DuplicateModel(Hndl);
}

//�`��
void CTurret_Normal::Draw()
{
	if (IsActive)
	{
		MV1DrawModel(iHndl);
	}

	if (IS_DEBUG)
	{
		DrawFormatString(0, 500, GetColor(255, 255, 0), "�^���b�gX���W:%f", cPos.x);
		DrawFormatString(0, 515, GetColor(255, 255, 0), "�^���b�gY���W:%f", cPos.y);
		DrawFormatString(0, 530, GetColor(255, 255, 0), "�^���b�gZ���W:%f", cPos.z);
		DrawFormatString(0, 550, GetColor(255, 255, 0), "�^���b�gY��:%f", cRotate.y);
	}
}

//���t���[���s������
void CTurret_Normal::Step(CShotManager& cShotManager, CEnemyManager& cEnemyManager)
{
	
	if (!IsActive)return;

	//�p�x�v�Z
	float MIN_RANGE = 999.9f;
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		//����for����Exit���Ă΂�Ă���G���`�悳��Ȃ�
		CEnemy_Normal cEnemy = cEnemyManager.GetEnemy(i);

		if (CCollision::IsHitCircle(cPos.x, cPos.z, 50.0f, cEnemy.GetPosition().x, cEnemy.GetPosition().z, 50.0f))
		{
			float Range = (cEnemy.GetPosition().x - cPos.x) * (cEnemy.GetPosition().x - cPos.x) + (cEnemy.GetPosition().z - cPos.z) * (cEnemy.GetPosition().z - cPos.z);
			Range = sqrt(Range);
			if (Range < MIN_RANGE)
			{
				MIN_RANGE = Range;
			}
			else
				continue;

			Turret_Rotate(cEnemy.GetPosition());

			//�e�̈ʒu����
			VECTOR BulletPos = cPos;

			//�e�̃X�s�[�h
			const float SHOT_SPEED = 5.0f;
			VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);

			vSpd.x = sinf(cRotate.y) * -SHOT_SPEED;
			vSpd.z = cosf(cRotate.y) * -SHOT_SPEED;
			vSpd.y = 0.0f;

			CoolTime++;
			if (CoolTime > MAX_COOL_TIME)
			{
				//�^���b�g�̒e���N�G�X�g
				cShotManager.RequestTurretShot(BulletPos, vSpd);
				CoolTime = 0;
			}
		}
	}
}

//�㏈��
void CTurret_Normal::Exit()
{
	CTurretBase::Exit();
	Attack = 0.0f;
	CoolTime = 0;
}

//�^���b�g�ݒu����
void CTurret_Normal::TurretSpawn(const VECTOR &vPos)
{
	//���łɐ�������Ă���
	if (IsActive) return;

	cPos = vPos;
	cRotate = VGet(0.0, 0.0f, 0.0f);
	cSize = VGet(0.1f, 0.1f, 0.1f);

	ShotRenge = 0.0f;
	Hp = MAX_LIFE;
	Power_Up_Count = 0;
	Attack = ATTACK;
	CoolTime = 0;

	IsActive = true;
}


//�^���b�g����
void CTurret_Normal::Turret_Power_Up()
{

}