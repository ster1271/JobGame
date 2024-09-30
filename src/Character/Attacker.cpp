#include "Attacker.h"


const char ATTACKER_PATH[] = { "data/character/il/�������邽��.pmx" };

const float SPERE_R = 3.0f;
#define MOVESPEED	(0.3f)
#define ROT_SPEED	(0.05f)	

//�R���X�g���N�^�E�f�X�g���N�^
CAttacker::CAttacker()
{
}

CAttacker::~CAttacker()
{
}

//������
void CAttacker::Init()
{
	CBase::Init();
	cPos = VGet(0.0f, 0.0f, 0.0f);
	cSize = VGet(1.0f, 1.0f, 1.0f);
	cRotate = VGet(0.0f, DX_PI_F, 0.0f);

	Life = 100;
}

//�f�[�^�ǂݍ���
void CAttacker::Load()
{
	iHndl = MV1LoadModel(ATTACKER_PATH);
}

//���t���[���s������
void CAttacker::Step(CShotManager& cShotManager, CTurretManager& cTurretManager)
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

	if (CInput::IsKeyKeep(KEY_INPUT_LEFT))
	{
		cRotate.y -= 0.05f;
	}
	if (CInput::IsKeyKeep(KEY_INPUT_RIGHT))
	{
		cRotate.y += 0.05f;
	}

	//���ˏ���
	if (CInput::IsKeyPush(KEY_INPUT_SPACE))
	{
		//�e�̈ʒu����
		VECTOR BulletPos = cPos;

		//�e�̃X�s�[�h
		const float SHOT_SPEED = 5.0f;
		VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);

		vSpd.x = sinf(cRotate.y) * -SHOT_SPEED;
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
void CAttacker::Draw()
{

	//��������true�Ȃ烂�f����false�Ȃ狅��\��
	if (iHndl != -1)
	{
		MV1DrawModel(iHndl);
	}
	else
	{
		DrawSphere3D(cPos, SPERE_R, 32, GetColor(255, 0, 0), GetColor(255, 0, 0), TRUE);
	}

	DrawFormatString(0, 100, GetColor(255, 0, 0), "�A�^�b�J�[X���W:%f", cPos.x);
	DrawFormatString(0, 115, GetColor(255, 0, 0), "�A�^�b�J�[Y���W:%f", cPos.y);
	DrawFormatString(0, 130, GetColor(255, 0, 0), "�A�^�b�J�[Z���W:%f", cPos.z);

}

//�I������
void CAttacker::Exit()
{
	CBase::Exit();
}
