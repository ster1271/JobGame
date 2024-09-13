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
	Attack = 0.0f;
	Exit();
}

//������
void CTurret_Normal::Init()
{
	TurretBase::Init();
	cRotate = VGet(0.0f, DX_PI_F / 2, DX_PI_F / 2);
	cSize = VGet(0.1f, 0.1f, 0.1f);
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
	TurretBase::Exit();
	Attack = 0.0f;
}

//�^���b�g�ݒu����
bool CTurret_Normal::TurretSpawn(const VECTOR &vPos)
{
	//���łɐ�������Ă���
	if (IsActive) return false;


	cPos = vPos;
	

	ShotRenge = VGet(0.0f, 0.0f, 0.0f);
	Hp = MAX_LIFE;
	Power_Up_Count = 0;
	Attack = ATTACK;

	IsActive = true;

	return true;
}