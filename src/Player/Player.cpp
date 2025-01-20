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
	Move();

	//�}�E�X�|�C���^�̍��W�擾
	GetMousePoint(&MouseX, &MouseY);
	
	//�e���ˏ���
	ShotCoolCount++;
	if (CMouse::IsMouseKeep(MOUSE_INPUT_LEFT) || CGamePad::IsKeep_LR(RIGHT))
	{
		Id = STATE_SHOT;						//�A�j���[�V������ύX����
		fSpd = -SHOTMOVESPEED;					//�ړ����x��ύX����
		Player_Rotation();						//�v���C���[�̊p�x�ύX(�ˌ���)

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
		DrawFormatString(0, 60, GetColor(255, 0, 0), "�}�E�XX���W:%d", MouseX);
		DrawFormatString(0, 75, GetColor(255, 0, 0), "�}�E�XY���W:%d", MouseY);
	}

	if (CGamePad::GetPadNumState() != 0)
	{
		CDebugString::GetInstance()->AddString(0, 285, "�R���g���[���[�ő��쒆");
		CDebugString::GetInstance()->AddString(0, 300, "���X�e�B�b�N�ňړ�");
		CDebugString::GetInstance()->AddString(0, 315, "RT�{�^���Ŏˌ�");
		CDebugString::GetInstance()->AddString(0, 330, "�E�X�e�B�b�N�Ŏˌ����p�x�ύX");
		CDebugString::GetInstance()->AddString(0, 345, "A�{�^���Ń^���b�g�ݒu");
		CDebugString::GetInstance()->AddString(0, 360, "B�{�^���������Ń{�b�g�Ƀ��[�v");
		CDebugString::GetInstance()->AddString(0, 375, "�S�[����LB�{�^���������ŃE�F�[�u�X�^�[�g");
		CDebugString::GetInstance()->AddFormatString(0, 390, "LB�{�^�������������ԁF%d", PushCnt);
		CDebugString::GetInstance()->AddString(0, 405, "X�{�^���Ń}�b�v�\���؂�ւ�");
	}
	else
	{
		CDebugString::GetInstance()->AddString(0, 285, "�L�[�{�[�h�ő��쒆");
		CDebugString::GetInstance()->AddString(0, 300, "WASD�ňړ�");
		CDebugString::GetInstance()->AddString(0, 315, "�}�E�X���N���b�N�Ŏˌ�");
		CDebugString::GetInstance()->AddString(0, 330, "�}�E�X�|�C���^�Ŏˌ����p�x�ύX");
		CDebugString::GetInstance()->AddString(0, 345, "E�L�[�Ń^���b�g�ݒu");
		CDebugString::GetInstance()->AddString(0, 360, "Q�L�[�������Ń{�b�g�Ƀ��[�v");
		CDebugString::GetInstance()->AddString(0, 375, "�S�[����1�L�[�������ŃE�F�[�u�X�^�[�g");
		CDebugString::GetInstance()->AddFormatString(0, 390, "1�L�[�����������ԁF%d", PushCnt);
		CDebugString::GetInstance()->AddString(0, 405, "TAB�L�[�Ń}�b�v�\���؂�ւ�");
	}
	
	CDebugString::GetInstance()->Draw();
}

//�I������
void CPlayer::Exit()
{
	CHumanBase::Exit();
}

//�ړ�����
void CPlayer::Move()
{
	VECTOR KeyBuf = VECTOR_ZERO;
	fSpd = 0.0f;

	if (CGamePad::Stick(STICK_LY_NEG) || CInput::IsKeyKeep(KEY_INPUT_W))
	{
		fSpd = -MOVESPEED;
		KeyBuf.z = -1000;
		Id = STATE_RUN;

		//�ˌ����͈ړ����x��x������
		if (CMouse::IsMouseKeep(MOUSE_INPUT_LEFT) || CGamePad::IsKeep_LR(RIGHT))
		{
			fSpd = -SHOTMOVESPEED;
		}
	}
	if (CGamePad::Stick(STICK_LY_POS) || CInput::IsKeyKeep(KEY_INPUT_S))
	{
		fSpd = -MOVESPEED;
		KeyBuf.z = 1000;
		Id = STATE_RUN;

		//�ˌ����͈ړ����x��x������
		if (CMouse::IsMouseKeep(MOUSE_INPUT_LEFT) || CGamePad::IsKeep_LR(RIGHT))
		{
			fSpd = -SHOTMOVESPEED;
		}
	}
	if (CGamePad::Stick(STICK_LX_NEG) || CInput::IsKeyKeep(KEY_INPUT_A))
	{
		fSpd = -MOVESPEED;
		KeyBuf.x = 1000;
		Id = STATE_RUN;

		//�ˌ����͈ړ����x��x������
		if (CMouse::IsMouseKeep(MOUSE_INPUT_LEFT) || CGamePad::IsKeep_LR(RIGHT))
		{
			fSpd = -SHOTMOVESPEED;
		}
	}
	if (CGamePad::Stick(STICK_LX_POS) || CInput::IsKeyKeep(KEY_INPUT_D))
	{
		fSpd = -MOVESPEED;
		KeyBuf.x = -1000;
		Id = STATE_RUN;

		//�ˌ����͈ړ����x��x������
		if (CMouse::IsMouseKeep(MOUSE_INPUT_LEFT) || CGamePad::IsKeep_LR(RIGHT))
		{
			fSpd = -SHOTMOVESPEED;
		}
	}
	
	//�����Ă��邩�ǂ���
	if (fSpd == 0.0f)
	{
		Id = STATE_DEFAULT;
	}
	else
	{
		cRotate.y = cMoveRotate.y;
	}

	//�L�����N�^�[�̈ړ��p�x�v�Z
	cMoveRotate.y = (float)atan2((int)KeyBuf.x * -1, (int)KeyBuf.z * -1);

	if(CGamePad::GetPadNumState() != 0)
	{
		cMoveRotate.y = CGamePad::StickRot(STICK_LEFT);
	}

	//���͂����L�[���ƃv���C���[�̊p�x����A�ړ����x�����߂�
	cSpeed.x = sin(cMoveRotate.y) * fSpd;
	cSpeed.z = cos(cMoveRotate.y) * fSpd;

	//�ړ����x�����݂̍��W�ɉ��Z����
	cNextPos = VAdd(cPos, cSpeed);
}

//���˃��N�G�X�g����
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
			CWave::GetInstance()->WaveStateChange(STATE_WAVE_PREPAR);
			
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
