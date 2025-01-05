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
	StoreRot = 0.0f;
	ShotCoolCount = 0;
	PushCnt = 0;

	Life = PLAYER_MAX_LIFE;
}

//�f�[�^�ǂݍ���
void CPlayer::Load()
{
	iHndl = MV1LoadModel(ATTACKER_PATH);
}

//�f�t�H���g���[�V����
void CPlayer::Default()
{
	ReqestLoop(STATE_DEFAULT, 0.8f);
}

//���胂�[�V����
void CPlayer::Run()
{
	ReqestLoop(STATE_RUN, 0.7f);
}

//�����[�V����
void CPlayer::Shot()
{
	ReqestLoop(STATE_SHOT, 0.1f);
}

//���t���[���s������
void CPlayer::Step(CShotManager& cShotManager, CTurretManager& cTurretManager, CMapManager& cMapManager, VECTOR BotPos)
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
		Shot();
		break;

	default:
		break;
	}

	cPos = cNextPos;
	
	//�L�����N�^�[�̈ړ�
	//Move_CON();

	Move_KEY();

	
	//�e���ˏ���
	ShotCoolCount++;
	if (CInput::IsKeyKeep(KEY_INPUT_SPACE) ||CGamePad::IsKeep_LR(RIGHT))
	{
		Id = STATE_SHOT;						//�A�j���[�V������ύX����
		Player_Rotation();

		if (ShotCoolCount < SHOT_COOL_TIME)		//�N�[���^�C�����Ȃ珈�����Ȃ�
			return;

		PlayerShot(cShotManager);				//���N�G�X�g����
	}

	//�^���b�g��������
	if (CInput::IsKeyPush(KEY_INPUT_E) || CGamePad::IsPadPush(DX_INPUT_PAD1, BUTTON_A))
	{
		cTurretManager.TurretSpawn(cPos);
	}

	//�E�F�[�u�J�n
	if (!CWave::GetInstance()->GetIsWave())
	{
		VECTOR GoalPos = cMapManager.GetGoal().GetPos();
		GoalPos.z -= 10.0f;
		if (CCollision::CheckHitBoxToBox(cPos, PLAYER_SIZE, GoalPos, GOAL_SIZE))
		{
			StartWave();
		}
	}
	//���̃E�F�[�u�J�n����
	StartWave();

	//�{�b�g�̏ꏊ�Ɉړ�
	BackBotPosition(BotPos);

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
		DrawFormatString(0, 0, GetColor(255, 0, 0), "�A�^�b�J�[X���W:%f", cPos.x);
		DrawFormatString(0, 15, GetColor(255, 0, 0), "�A�^�b�J�[Y���W:%f", cPos.y);
		DrawFormatString(0, 30, GetColor(255, 0, 0), "�A�^�b�J�[Z���W:%f", cPos.z);
		DrawFormatString(0, 45, GetColor(255, 0, 0), "�v���C���[Y��:%f", cRotate.y);
	}

	CDebugString::GetInstance()->AddString(0, 300, "A�{�^����E�L�[�Ń^���b�g�ݒu");
	CDebugString::GetInstance()->AddString(0, 315, "B�{�^����Q�L�[�������Ń{�b�g�Ƀ��[�v");
	CDebugString::GetInstance()->AddString(0, 330, "�S�[����LB�{�^����1�L�[�������ŃE�F�[�u�X�^�[�g");
	CDebugString::GetInstance()->AddString(0, 345, "RT�{�^����SPACE�L�[�������Ŏˌ�");
	CDebugString::GetInstance()->AddString(0, 360, "���X�e�B�b�N�ňړ�");
	CDebugString::GetInstance()->AddString(0, 375, "�E�X�e�B�b�N�Ŋp�x�ύX");
	CDebugString::GetInstance()->AddFormatString(0, 460, "LB��1�L�[�����������ԁF%d", PushCnt);

	CDebugString::GetInstance()->Draw();

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
		//�ˌ����͈ړ����x��������
		if (CGamePad::IsKeep_LR(RIGHT))
		{
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
		//�ˌ����͈ړ����x��������
		if (CGamePad::IsKeep_LR(RIGHT))
		{
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
		//�ˌ����͈ړ����x��������
		if (CGamePad::IsKeep_LR(RIGHT))
		{
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
		//�ˌ����͈ړ����x��������
		if (CGamePad::IsKeep_LR(RIGHT))
		{
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


	//�L�����N�^�[�̈ړ��p�x�v�Z
	cMoveRotate.y = CGamePad::StickRot(STICK_LEFT);

	//���͂����L�[���ƃv���C���[�̊p�x����A�ړ����x�����߂�
	cSpeed.x = sin(cMoveRotate.y) * fSpd;
	cSpeed.z = cos(cMoveRotate.y) * fSpd;

	//�ړ����x�����݂̍��W�ɉ��Z����
	cNextPos.x += cSpeed.x;
	cNextPos.z += cSpeed.z;
}

//�L�[�{�[�h�ړ�����
void CPlayer::Move_KEY()
{
	float XSpd = 0.0f;
	float ZSpd = 0.0f;

	if (CInput::IsKeyKeep(KEY_INPUT_W))
	{
		Id = STATE_RUN;
		ZSpd = -MOVESPEED;
	}
	if (CInput::IsKeyKeep(KEY_INPUT_S))
	{
		Id = STATE_RUN;
		ZSpd = MOVESPEED;
	}
	if (CInput::IsKeyKeep(KEY_INPUT_A))
	{
		Id = STATE_RUN;
		XSpd = MOVESPEED;
	}
	if (CInput::IsKeyKeep(KEY_INPUT_D))
	{
		Id = STATE_RUN;
		XSpd = -MOVESPEED;
	}

	//�L�����N�^�[�̈ړ��p�x�v�Z
	//cMoveRotate.y = atan2(XSpd, ZSpd * -1);
	cSpeed = VGet(XSpd, 0.0f, ZSpd);
	cNextPos = VAdd(cPos, cSpeed);
}


//���˃��N�G�X�g����W
void CPlayer::PlayerShot(CShotManager& cShotManager)
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
	ShotCoolCount = 0;
}


//�E�F�[�u�J�n����
void CPlayer::StartWave()
{
	if (CGamePad::IsPadKeep(DX_INPUT_PAD1, BUTTON_LB) || CInput::IsKeyKeep(KEY_INPUT_1))
	{
		PushCnt++;

		if (PushCnt > 50)
		{
			CWave::GetInstance()->WaveStart(STATE_WAVE_PREPAR);
			PushCnt = 0;
		}
	}
	else
	{
		PushCnt = 0;
	}
}


//�{�b�g�̈ʒu�Ɉړ�
void CPlayer::BackBotPosition(VECTOR vPos)
{
	if (CGamePad::IsPadKeep(DX_INPUT_PAD1, BUTTON_B) || CInput::IsKeyKeep(KEY_INPUT_Q))
	{
		ReturnCnt++;

		if (ReturnCnt > 50)
		{
			cPos = vPos;
			cNextPos = cPos;
			ReturnCnt = 0;
		}
	}
	else
	{
		ReturnCnt = 0;
	}
}
