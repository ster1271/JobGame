#include "Player.h"
#include "../Debug/DebugString.h"

const char ATTACKER_PATH[] = { "data/character/human.x" };

//�R���X�g���N�^�E�f�X�g���N�^
CPlayer::CPlayer()
{
	IsDir[DIR_NUM] = { false };
	memset(&Id, 0, sizeof(PLAYER_STATE));
}

CPlayer::~CPlayer()
{
}

//������
void CPlayer::Init()
{
	cPos = PLAYER_POS;
	cNextPos = cPos;
	cRotate = VECTOR_ZERO;
	cMoveRotate = VECTOR_ZERO;
	cScale = PLAYER_SCALE;
	cSize = PLAYER_SIZE;
	fSpd = 0.0f;
	ShotCoolCount = 0;

	Life = 100;
}

//�f�[�^�ǂݍ���
void CPlayer::Load()
{
	iHndl = MV1LoadModel(ATTACKER_PATH);
}

void CPlayer::Default()
{
	ReqestLoop(STATE_DEFAULT, 0.8f);
}

void CPlayer::Run()
{
	ReqestLoop(STATE_RUN, 0.7f);
}

void CPlayer::RunShot()
{
	ReqestLoop(STATE_SHOT, 0.1f);
}

//���t���[���s������
void CPlayer::Step(CShotManager& cShotManager, CTurretManager& cTurretManager)
{
	fSpd = 0.0f;

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

	cPos = cNextPos;
	
	//�L�����N�^�[�̈ړ�
	Move_CON();
	
	//�L�����N�^�[�̈ړ��p�x�v�Z
	cMoveRotate.y = CGamePad::StickRot(STICK_LEFT);
	if (CGamePad::Stick(STICK_RX_POS))
	{
		cRotate.y -= 0.03f;
	}
	else if (CGamePad::Stick(STICK_RX_NEG))
	{
		cRotate.y += 0.03f;
	}
	
	//���͂����L�[���ƃv���C���[�̊p�x����A�ړ����x�����߂�
	VECTOR vSpeed = VGet(0.0f, 0.0f, 0.0f);
	vSpeed.x = sin(cMoveRotate.y) * fSpd;
	vSpeed.z = cos(cMoveRotate.y) * fSpd;

	//�ړ����x�����݂̍��W�ɉ��Z����
	cNextPos.x += vSpeed.x;
	cNextPos.z += vSpeed.z;



	//���ˏ���
	ShotCoolCount++;
	if (CInput::IsKeyKeep(KEY_INPUT_SPACE) ||CGamePad::IsKeep_LR(RIGHT))
	{
		Id = STATE_SHOT;

		if (ShotCoolCount < SHOT_COOL_TIME)
			return;

		//�e�̈ʒu����
		VECTOR BulletPos = cPos;

		//�e�̃X�s�[�h
		const float SHOT_SPEED = 5.0f;
		VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);

		vSpd.x = sinf(cRotate.y) * -SHOT_SPEED;
		vSpd.z = cosf(cRotate.y) * -SHOT_SPEED;
		vSpd.y = 0.0f;

		cShotManager.RequestPlayerShot(BulletPos, vSpd);
		ShotCoolCount = 0;
	}

	//�^���b�g��������
	if (CInput::IsKeyPush(KEY_INPUT_P) || CGamePad::IsPadPush(DX_INPUT_PAD1, BUTTON_A))
	{
		cTurretManager.TurretSpawn(cPos);
	}


	//�����̃`�F�b�N
	SetDir();

	//�ߋ��̃A�j���[�V����ID�Ɍ��݃A�j���[�V��������
	oldId = Id;
}

//�`��
void CPlayer::Draw()
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
		CDebugString::GetInstance()->AddFormatString(300, 300, "�v���C���[Y���F%f", cRotate.y);
		CDebugString::GetInstance()->Draw();
	}
}

//�I������
void CPlayer::Exit()
{
	CHumanBase::Exit();
}



//�R���g���[���[����
void CPlayer::Move_CON()
{
	if (CGamePad::Stick(STICK_LY_NEG))
	{
		//�ˌ����Ɉړ�
		if (CGamePad::IsKeep_LR(RIGHT))
		{
			Id = STATE_SHOT;
			fSpd = -0.5f;
		}
		else
		{
			Id = STATE_RUN;
			fSpd = -MOVESPEED;
			cRotate.y = cMoveRotate.y;
		}
	}
	else if (CGamePad::Stick(STICK_LY_POS))
	{
		//�ˌ����Ɉړ�
		if (CGamePad::IsKeep_LR(RIGHT))
		{
			Id = STATE_SHOT;
			fSpd = -0.5f;
		}
		else
		{
			Id = STATE_RUN;
			fSpd = -MOVESPEED;
			cRotate.y = cMoveRotate.y;
		}
	}
	else if (CGamePad::Stick(STICK_LX_NEG))
	{
		//�ˌ����Ɉړ�
		if (CGamePad::IsKeep_LR(RIGHT))
		{
			Id = STATE_SHOT;
			fSpd = -0.5f;
		}
		else
		{
			Id = STATE_RUN;
			fSpd = -MOVESPEED;
			cRotate.y = cMoveRotate.y;
		}
	}
	else if (CGamePad::Stick(STICK_LX_POS))
	{
		//�ˌ����Ɉړ�
		if (CGamePad::IsKeep_LR(RIGHT))
		{
			Id = STATE_SHOT;
			fSpd = -0.5f;
		}
		else
		{
			Id = STATE_RUN;
			fSpd = -MOVESPEED;
			cRotate.y = cMoveRotate.y;
		}
	}
	else
	{
		Id = STATE_DEFAULT;
	}
	
}

