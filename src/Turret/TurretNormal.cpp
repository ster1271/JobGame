#include "Turret_Normal.h"
#include "../CollisionManager/Collision/Collision.h"

const float MAX_LIFE = 10.0f;		//�ő�̗�
const float ATTACK = 5.0f;			//�U����
const int MAX_COOL_TIME = 30;		//�e�̔��ˊԊu
const float SET_RANGE = 150.0f;		//�ő咼������

//�R���X�g���N�^
CTurret_Normal::CTurret_Normal()
{
	Attack = 0.0f;
	CoolTime = 0;
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
		CDraw3D::DrawBox3D(cPos, VGet(30.0f, 30.0f, 30.0f));
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
	//�^���b�g����������Ă��Ȃ������珈�����s��Ȃ�
	if (!IsActive)return;

	//HP��0���傫���Ƃ��ɏ������s��
	if (Hp > 0.0f)
	{
		for (int i = 0; i < ENEMY_MAXNUM; i++)
		{
			//����for����Exit���Ă΂�Ă���G���`�悳��Ȃ�
			CEnemy_Normal& cEnemy = cEnemyManager.GetEnemy(i);

			//�G�̃t���O��false�Ȃ�ȍ~�̏��������Ȃ�
			if (!cEnemy.GetActive())
				return;

			VECTOR Reng_Vec = VSub(cEnemy.GetPosition(), cPos);		//�G�ƃ^���b�g�̋��������߂�	
			float Range = CMyLibrary::VecLong(Reng_Vec);

			//�����������ݒ�l�����傫�������牺�̏��������Ȃ�
			TotalMinLenge = SET_RANGE;
			if (Range >= SET_RANGE)
				continue;

			if (Range < TotalMinLenge)
			{
				TotalMinLenge = Range;
			}

			Turret_Rotate(cEnemy.GetPosition());		//�p�x����

			TurretShot(cShotManager);					//�e�̔��˃��N�G�X�g
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
	cPos.y -= 10.0f;
	cRotate = VECTOR_ZERO;
	cSize = VGet(0.1f, 0.1f, 0.1f);

	Hp = MAX_LIFE;
	Power_Up_Count = 0;
	Attack = ATTACK;
	CoolTime = 0;

	IsActive = true;
}

//�e���ˏ���
void CTurret_Normal::TurretShot(CShotManager& cShotManager)
{
	//�e�̈ʒu����
	VECTOR BulletPos = cPos;

	//�e�̃X�s�[�h
	const float SHOT_SPEED = 5.0f;
	VECTOR vSpd = VECTOR_ZERO;

	vSpd.x = sinf(cRotate.y) * -SHOT_SPEED;
	vSpd.z = cosf(cRotate.y) * -SHOT_SPEED;
	vSpd.y = 0.0f;

	CoolTime++;
	if (CoolTime > MAX_COOL_TIME)
	{
		if (Dir > 1.0f)
			return;

		//�^���b�g�̒e���N�G�X�g
		cShotManager.RequestTurretShot(BulletPos, vSpd);
		CoolTime = 0;
	}
}



//�^���b�g����
void CTurret_Normal::Turret_Power_Up()
{

}