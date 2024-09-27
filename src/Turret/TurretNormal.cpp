#include "Turret_Normal.h"

const float MAX_LIFE = 50.0f;
const float ATTACK = 5.0f;

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

	DrawFormatString(0, 500, GetColor(255, 255, 0), "�^���b�gX���W:%f", cPos.x);
	DrawFormatString(0, 515, GetColor(255, 255, 0), "�^���b�gY���W:%f", cPos.y);
	DrawFormatString(0, 530, GetColor(255, 255, 0), "�^���b�gZ���W:%f", cPos.z);


	DrawFormatString(0, 550, GetColor(255, 255, 0), "�^���b�gY��:%f", cRotate.y);

}

//���t���[���s������
void CTurret_Normal::Step(CShotManager& cShotManager, const VECTOR PayerPos)
{
	
	if (!IsActive)return;

	
	//�p�x�v�Z
	Turret_Rotate(PayerPos);


	//�e�̈ʒu����
	VECTOR BulletPos = cPos;

	//�e�̃X�s�[�h
	const float SHOT_SPEED = 5.0f;
	VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);

	vSpd.x = sinf(cRotate.y) * -SHOT_SPEED;
	vSpd.z = cosf(cRotate.y) * -SHOT_SPEED;
	vSpd.y = 0.0f;
	
	if (CInput::IsKeyPush(KEY_INPUT_Q))
	{
		//�^���b�g�̒e���N�G�X�g
		cShotManager.RequestTurretShot(BulletPos, vSpd);
	}
	DrawFormatString(300, 10, GetColor(255, 255, 255), "BulletPos.x%0.2f", BulletPos.x);
	DrawFormatString(300, 25, GetColor(255, 255, 255), "BulletPos.y%0.2f", BulletPos.y);
	DrawFormatString(300, 40, GetColor(255, 255, 255), "BulletPos.z%0.2f", BulletPos.z);
	DrawFormatString(300, 55, GetColor(255, 255, 255), "vSpd.x%0.2f", vSpd.x);
	DrawFormatString(300, 70, GetColor(255, 255, 255), "vSpd.y%0.2f", vSpd.y);
	DrawFormatString(300, 85, GetColor(255, 255, 255), "vSpd.z%0.2f", vSpd.z);

}

//�㏈��
void CTurret_Normal::Exit()
{
	CTurretBase::Exit();
	Attack = 0.0f;
}

//�^���b�g�ݒu����
void CTurret_Normal::TurretSpawn(const VECTOR &vPos)
{
	//���łɐ�������Ă���
	if (IsActive) return;

	cPos = vPos;
	cPos.y += 5.0f;
	cRotate = VGet(0.0, 0.0f, 0.0f);
	cSize = VGet(0.1f, 0.1f, 0.1f);

	ShotRenge = 0.0f;
	Hp = MAX_LIFE;
	Power_Up_Count = 0;
	Attack = ATTACK;

	IsActive = true;
}


//�^���b�g����
void CTurret_Normal::Turret_Power_Up()
{

}