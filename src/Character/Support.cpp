#include "Support.h"


const char SUPPORT_PATH[] = { "" };

const float SPERE_R = 10.0f;
#define MOVESPEED	(0.3f)


//�R���X�g���N�^�E�f�X�g���N�^
CSupport::CSupport()
{
}

CSupport::~CSupport()
{
}

//������
void CSupport::Init()
{
	CBase::Init();
	cPos = VGet(0.0f, 0.0f, 0.0f);
	cSize = VGet(1.0f, 1.0f, 1.0f);
	cRotate = VGet(0.0f, DX_PI_F, 0.0f);
}

//�f�[�^�ǂݍ���
void CSupport::Load()
{
	iHndl = MV1LoadModel(SUPPORT_PATH);
}

//���t���[���s������
void CSupport::Step(CShotManager& cShotManager, CTurretManager& cTurretManager)
{
	if (CInput::IsKeyKeep(KEY_INPUT_W))
	{
		cPos.z += MOVESPEED;
	}
	if (CInput::IsKeyKeep(KEY_INPUT_S))
	{
		cPos.z -= MOVESPEED;
	}
	if (CInput::IsKeyKeep(KEY_INPUT_A))
	{
		cPos.x -= MOVESPEED;
	}
	if (CInput::IsKeyKeep(KEY_INPUT_D))
	{
		cPos.x += MOVESPEED;
	}

	//���ˏ���
	if (CInput::IsKeyPush(KEY_INPUT_SPACE))
	{
		//�e�̈ʒu����
		VECTOR BulletPos = cPos;

		//�e�̃X�s�[�h
		const float SHOT_SPEED = 5.0f;
		VECTOR vSpd;

		vSpd.x = sinf(cPos.y) * -SHOT_SPEED;
		vSpd.z = cosf(cRotate.y) * -SHOT_SPEED;
		vSpd.y = 0.0f;

		cShotManager.RequestPlayerShot(BulletPos, vSpd);
	}

	//�^���b�g��������
	if (CInput::IsKeyPush(KEY_INPUT_P))
	{
		cTurretManager.TurretSpawn(cPos);
	}
}

//�`��
void CSupport::Draw()
{
	//��������true�Ȃ烂�f����false�Ȃ狅��\��
	if (iHndl != -1)
	{
		MV1DrawModel(iHndl);
	}
	else
	{
		DrawSphere3D(cPos, SPERE_R, 32, GetColor(0, 0, 255), GetColor(0, 0, 255), TRUE);
	}

	DrawFormatString(0, 100, GetColor(255, 255, 255), "�T�|�[�gX���W:%f", cPos.x);
	DrawFormatString(0, 115, GetColor(255, 255, 255), "�T�|�[�gY���W:%f", cPos.y);
	DrawFormatString(0, 130, GetColor(255, 255, 255), "�T�|�[�gZ���W:%f", cPos.z);

}

//�I������
void CSupport::Exit()
{
	CBase::Exit();
}
