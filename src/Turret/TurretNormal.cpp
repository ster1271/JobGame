#include "Turret_Normal.h"

const float MAX_LIFE = 50.0f;
const float ATTACK = 5.0f;
const char TURRET_NORMAL_PATH[] = { "data/Turret/Turret_Normal.x" };

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
void CTurret_Normal::Load()
{
	if (iHndl == -1)
	{
		//���f���̓ǂݍ���
		iHndl = MV1LoadModel(TURRET_NORMAL_PATH);
	}
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

}

//���t���[���s������
void CTurret_Normal::Step()
{
	
	if (!IsActive)return;


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
	cRotate = VGet(0.0f, DX_PI_F / 2, DX_PI_F / 2);
	cSize = VGet(0.1f, 0.1f, 0.1f);

	ShotRenge = VGet(0.0f, 0.0f, 0.0f);
	Hp = MAX_LIFE;
	Power_Up_Count = 0;
	Attack = ATTACK;

	IsActive = true;
}


//�^���b�g����
void CTurret_Normal::Turret_Power_Up()
{

}