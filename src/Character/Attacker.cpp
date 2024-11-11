#include "Attacker.h"


const char ATTACKER_PATH[] = { "data/character/human.x" };

const float SPERE_R = 3.0f;
#define MOVESPEED	(1.0f)
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
	cSize = VGet(0.05f, 0.05f, 0.05f);
	cRotate = VGet(0.0f, 0.0f, 0.0f);

	Life = 100;


}

//�f�[�^�ǂݍ���
void CAttacker::Load()
{
	iHndl = MV1LoadModel(ATTACKER_PATH);
}

void CAttacker::Default()
{
	ReqestLoop(STATE_DEFAULT, 0.8f);
}

void CAttacker::Run()
{
	ReqestLoop(STATE_RUN, 0.7f);
}

void CAttacker::RunShot()
{
	ReqestLoop(STATE_SHOT, 0.1f);
}

//���t���[���s������
void CAttacker::Step(CShotManager& cShotManager, CTurretManager& cTurretManager)
{
	GetJoypadDirectInputState(DX_INPUT_PAD1, &pad);

	switch (Id)
	{
	case STATE_DEFAULT:
		Default();
		break;

	case STATE_RUN:
		Run();
		break;

	case STATE_SHOT:
		RunShot();
		break;

	default:
		break;
	}

	//�L�����N�^�[�̈ړ�
	float fSpd = 0.0f;
	if (CInput::IsKeyKeep(KEY_INPUT_W) || pad.Y == -1000)
	{
		Id = STATE_RUN;
		fSpd = -MOVESPEED;
	}
	else if (CInput::IsKeyKeep(KEY_INPUT_S) || pad.Y == 1000)
	{
		Id = STATE_RUN;
		fSpd = MOVESPEED;
	}
	else
	{
		Id = STATE_DEFAULT;
	}

	//���͂����L�[���ƃv���C���[�̊p�x����A�ړ����x�����߂�
	VECTOR vSpeed = VGet(0.0f, 0.0f, 0.0f);
	vSpeed.x = sin(cRotate.y) * fSpd;
	vSpeed.z = cos(cRotate.y) * fSpd;

	//�ړ����x�����݂̍��W�ɉ��Z����
	cPos.x += vSpeed.x;
	cPos.z += vSpeed.z;

	if (CInput::IsKeyKeep(KEY_INPUT_A)/* || pad.Rx == -1000*/)
	{
		cRotate.y -= 0.05f;
	}
	if (CInput::IsKeyKeep(KEY_INPUT_D)/* || pad.Rx == 1000*/)
	{
		cRotate.y += 0.05f;
	}

	//���ˏ���
	if (CInput::IsKeyPush(KEY_INPUT_SPACE) ||CGamePad::IsPush_LR(RIGHT))
	{
		Id = STATE_SHOT;
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
	if (CInput::IsKeyPush(KEY_INPUT_P) || CGamePad::IsPadPush(DX_INPUT_PAD1, BUTTON_A))
	{

		cTurretManager.TurretSpawn(cPos);
	}

	oldId = Id;
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

	if (IS_DEBUG)
	{
		DrawFormatString(0, 100, GetColor(255, 0, 0), "�A�^�b�J�[X���W:%f", cPos.x);
		DrawFormatString(0, 115, GetColor(255, 0, 0), "�A�^�b�J�[Y���W:%f", cPos.y);
		DrawFormatString(0, 130, GetColor(255, 0, 0), "�A�^�b�J�[Z���W:%f", cPos.z);

		//DrawFormatString(0, 0, GetColor(255, 0, 0), "�A�^�b�J�[Y��:%f", cRotate.y);
		//DrawFormatString(0, 0, GetColor(255, 0, 0), "�R���g���[���[�̐ڑ���:%d",	PadNum);

		// ��ʂɍ\���̂̒��g��`��
		int Color = GetColor(0, 0, 0);
		DrawFormatString(0, 0, Color, "X:%d Y:%d Z:%d",
			pad.X, pad.Y, pad.Z);
		DrawFormatString(0, 16, Color, "Rx:%d Ry:%d Rz:%d",
			pad.Rx, pad.Ry, pad.Rz);
		DrawFormatString(0, 32, Color, "Slider 0:%d 1:%d",
			pad.Slider[0], pad.Slider[1]);
		DrawFormatString(0, 48, Color, "POV 0:%d 1:%d 2:%d 3:%d",
			pad.POV[0], pad.POV[1],
			pad.POV[2], pad.POV[3]);
		DrawString(0, 64, "Button", Color);
		for (int i = 0; i < 32; i++)
		{
			DrawFormatString(64 + i % 8 * 64, 64 + i / 8 * 16, Color,
				"%2d:%d", i, pad.Buttons[i]);
		}
	}
}

//�I������
void CAttacker::Exit()
{
	CBase::Exit();
}
