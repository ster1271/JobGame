#include "HumanBase.h"


//�R���X�g���N�^
CHumanBase::CHumanBase()
{
	memset(&AnimDataInfo, 0, sizeof(ANIME_DATA));
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cNextPos, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&cMoveRotate, 0, sizeof(VECTOR));
	memset(&cScale, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));

	IsActive = false;

	Life = -1;
	iHndl = -1;
	PushCnt = 0;
	ReturnCnt = 0;
}

//�f�X�g���N�^
CHumanBase::~CHumanBase(){}


//������
void CHumanBase::Init()
{
	memset(&AnimDataInfo, 0, sizeof(ANIME_DATA));

	//�ϐ��̏�����
	cPos = VECTOR_ZERO;
	cNextPos = VECTOR_ZERO;
	cRotate = VECTOR_ZERO;
	cMoveRotate = VECTOR_ZERO;
	cScale = VECTOR_ZERO;
	cSize = VECTOR_ZERO;

	IsActive = false;

	Life = 0;
	iHndl = 0;
	PushCnt = 0;
	ReturnCnt = 0;
}

//�f�[�^�ǂݍ���
void CHumanBase::Load(const char FILEPATH[])
{
	iHndl = MV1LoadModel(FILEPATH);
}

//�`��
void CHumanBase::Draw()
{
	if (IsActive)
	{
		MV1DrawModel(iHndl);
	}
	else
	{
		CDraw3D::DrawBox3D(cPos, cSize);
	}

}

//���t���[���s������
void CHumanBase::Step(){}

//���X�V
void CHumanBase::UpData()
{
	MV1SetPosition(iHndl, cPos);		//���W�̍X�V
	MV1SetScale(iHndl, cScale);			//�T�C�Y�̍X�V
	MV1SetRotationXYZ(iHndl, cRotate);	//��]�l�̍X�V

	UpdateAnim();						//�A�j���[�V�����̏��X�V
}

//�㏈��
void CHumanBase::Exit()
{
	memset(&AnimDataInfo, 0, sizeof(ANIME_DATA));
	//�ϐ��̏�����
	cPos = VECTOR_ZERO;
	cNextPos = VECTOR_ZERO;
	cRotate = VECTOR_ZERO;
	cMoveRotate = VECTOR_ZERO;
	cScale = VECTOR_ZERO;
	cSize = VECTOR_ZERO;

	IsActive = false;

	Life = -1;
	iHndl = -1;
	PushCnt = 0;
	ReturnCnt = 0;
}


//���N�G�X�g
void CHumanBase::Reqest(int iAnimID, float iAnimSpd, int iAnimHndl, bool NameCheck)
{
	//�O�̃A�j���[�V������o�����������珈�����Ȃ�
	if (AnimDataInfo.m_OldAnimID == iAnimID)
		return;

	//�A�j������
	DetachAnim();

	//�A�j���Đ�&�e��f�[�^���Z�b�g
	AnimDataInfo.m_iHndl = MV1AttachAnim(iHndl, iAnimID, iAnimHndl, NameCheck);
	AnimDataInfo.m_AnimID = iAnimID;
	AnimDataInfo.m_OldAnimID = AnimDataInfo.m_AnimID;
	AnimDataInfo.m_EndFrame = MV1GetAnimTotalTime(iHndl, iAnimID);
	AnimDataInfo.m_Frame = 0.0f;
	AnimDataInfo.m_Speed = iAnimSpd;
	AnimDataInfo.m_State = ANIMESTATE_NORMAL;

}

//���[�v�A�j�����N�G�X�g(�A�j�����ŏI�t���[���ɂȂ�����ŏ��ɖ߂�)
void CHumanBase::ReqestLoop(int iAnimID, float iAnimSpd, int iAnimHndl, bool NameCheck)
{

	Reqest(iAnimID, iAnimSpd, iAnimHndl, NameCheck);
	//�A�j���Đ���Ԃ����[�v�ɕς���
	AnimDataInfo.m_State = ANIMESTATE_LOOP;
}

//�G���h���[�v�A�j�����N�G�X�g(�A�j�����ŏI�t���[���ɂȂ�����~�܂�)
void CHumanBase::ReqestEndLoop(int iAnimID, float iAnimSpd, int iAnimHndl, bool NameCheck)
{
	Reqest(iAnimID, iAnimSpd, iAnimHndl, NameCheck);
	//�A�j���Đ���Ԃ��G���h���[�v�ɕς���
	AnimDataInfo.m_State = ANIMESTATE_END;
}

//�A�j�����f�^�b�`
void CHumanBase::DetachAnim()
{
	if (AnimDataInfo.m_iHndl != -1)
	{
		MV1DetachAnim(iHndl, AnimDataInfo.m_iHndl);
		AnimDataInfo.m_iHndl = -1;
	}
}

//�A�j���A�b�v�f�[�g
void CHumanBase::UpdateAnim()
{
	if (AnimDataInfo.m_iHndl == -1)return;	//�A�j���[�V�������Đ�����Ă��Ȃ�

	//�A�j���[�V�������x�X�V
	AnimDataInfo.m_Frame += AnimDataInfo.m_Speed;

	if (AnimDataInfo.m_Frame >= AnimDataInfo.m_EndFrame)
	{
		//�ŏI�t���[���ɂȂ�����A��Ԃɂ��킹�ē����ς���
		switch (AnimDataInfo.m_State)
		{
		case ANIMESTATE_NORMAL:	//�ʏ�I��
			DetachAnim();
			AnimDataInfo.m_EndFrame = 0.0f;
			AnimDataInfo.m_Frame = 0.0f;
			AnimDataInfo.m_Speed = 0.0f;
			return;

		case ANIMESTATE_LOOP:	//���[�v���ŏ��ɖ߂�
			AnimDataInfo.m_Frame = 0.0f;
			break;

		case ANIMESTATE_END:
			AnimDataInfo.m_State = AnimDataInfo.m_EndFrame;
			break;

		default:
			break;
		}
	}

	//�Đ����Ԑݒ�
	MV1SetAttachAnimTime(iHndl, AnimDataInfo.m_iHndl, AnimDataInfo.m_Frame);
}


//�L�����N�^�[��]����
void CHumanBase::Player_Rotation()
{
	if (CGamePad::Stick(STICK_RX_POS))
	{
		cRotate.y -= 0.03f;
	}
	else if (CGamePad::Stick(STICK_RX_NEG))
	{
		cRotate.y += 0.03f;
	}

	
}

//�����t���O�ݒ�
void CHumanBase::SetDir()
{
	if (cNextPos.x > cPos.x)
	{
		//�E�ɓ����Ă���
		IsDir[DIR_RIGHT] = true;
	}
	else
	{
		IsDir[DIR_RIGHT] = false;
	}

	if (cNextPos.x < cPos.x)
	{
		//���ɓ����Ă���
		IsDir[DIR_LEFT] = true;
	}
	else
	{
		IsDir[DIR_LEFT] = false;
	}

	if (cNextPos.y > cPos.y)
	{
		//��ɓ����Ă���
		IsDir[DIR_UP] = true;
	}
	else
	{
		IsDir[DIR_UP] = false;
	}

	if (cNextPos.y < cPos.y)
	{
		//���ɓ����Ă���
		IsDir[DIR_DOWN] = true;
	}
	else
	{
		IsDir[DIR_DOWN] = false;
	}

	if (cNextPos.z > cPos.z)
	{
		//���ɓ����Ă���
		IsDir[DIR_BACK] = true;
	}
	else
	{
		IsDir[DIR_BACK] = false;
	}

	if (cNextPos.z < cPos.z)
	{
		//��O�ɓ����Ă���
		IsDir[DIR_NEAR] = true;
	}
	else
	{
		IsDir[DIR_NEAR] = false;
	}
}

