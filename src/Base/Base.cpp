#include "Base.h"

//�R���X�g���N�^
CBase::CBase()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&Life, 0, sizeof(float));
	memset(&AnimData, 0, sizeof(ANIME_DATA));

	AnimData.m_iHndl = -1;
	AnimData.m_AnimID = -1;
}

//�f�X�g���N�^
CBase::~CBase()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&Life, 0, sizeof(float));
	memset(&AnimData, 0, sizeof(ANIME_DATA));

	AnimData.m_iHndl = -1;
	AnimData.m_AnimID = -1;
}

//������
void CBase::Init()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&Life, 0, sizeof(float));
	memset(&AnimData, 0, sizeof(ANIME_DATA));

	AnimData.m_iHndl = -1;
	AnimData.m_AnimID = -1;

}

//�ǂݍ��݊֘A
bool CBase::Load(const char FILEPATH[])
{
	//���f���̓ǂݍ���
	iHndl = MV1LoadModel(FILEPATH);

	/*�ǂݍ��ݐ��� = true, �ǂݍ��ݎ��s = false*/	
	if (iHndl != -1)
		return true;
	else
		return false;
}

//�`��
void CBase::Draw()
{
	//���f���̕`��
	MV1DrawModel(iHndl);
}

//�X�V����
void CBase::Update()
{
	MV1SetPosition(iHndl, cPos);		//���W�̍X�V
	MV1SetScale(iHndl, cSize);			//�T�C�Y�̍X�V
	MV1SetRotationXYZ(iHndl, cRotate);	//��]�l�̍X�V
}

//�㏈��
void CBase::Exit()
{
	//�n���h���̍폜
	if (iHndl != -1)
	{
		MV1DeleteModel(iHndl);
		iHndl = -1;
	}

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
	memset(&Life, 0, sizeof(float));
}


//���N�G�X�g
void CBase::Reqest(int iAnimID, float iAnimSpd, int iAnimHndl, bool NameCheck)
{
	//�O�̃A�j���[�V������o�����������珈�����Ȃ�
	if (AnimData.m_OldAnimID == iAnimID)
		return;

	//�A�j������
	DetachAnim();

	//�A�j���Đ�&�e��f�[�^���Z�b�g
	AnimData.m_iHndl = MV1AttachAnim(iHndl, iAnimID, iAnimHndl, NameCheck);
	AnimData.m_AnimID = iAnimID;
	AnimData.m_OldAnimID = AnimData.m_AnimID;
	AnimData.m_EndFrame = MV1GetAnimTotalTime(iHndl, iAnimID);
	AnimData.m_Frame = 0.0f;
	AnimData.m_Speed = iAnimSpd;
	AnimData.m_State = ANIMESTATE_NORMAL;

}

//���[�v�A�j�����N�G�X�g(�A�j�����ŏI�t���[���ɂȂ�����ŏ��ɖ߂�)
void CBase::ReqestLoop(int iAnimID, float iAnimSpd, int iAnimHndl, bool NameCheck)
{
	
	Reqest(iAnimID, iAnimSpd, iAnimHndl, NameCheck);
	//�A�j���Đ���Ԃ����[�v�ɕς���
	AnimData.m_State = ANIMESTATE_LOOP;
}

//�G���h���[�v�A�j�����N�G�X�g(�A�j�����ŏI�t���[���ɂȂ�����~�܂�)
void CBase::ReqestEndLoop(int iAnimID, float iAnimSpd, int iAnimHndl, bool NameCheck)
{
	Reqest(iAnimID, iAnimSpd, iAnimHndl, NameCheck);
	//�A�j���Đ���Ԃ��G���h���[�v�ɕς���
	AnimData.m_State = ANIMESTATE_END;
}

//�A�j�����f�^�b�`
void CBase::DetachAnim()
{
	if (AnimData.m_iHndl != -1)
	{
		MV1DetachAnim(iHndl, AnimData.m_iHndl);
		AnimData.m_iHndl = -1;
	}
}

//�A�j���A�b�v�f�[�g
void CBase::UpdateAnim()
{
	if (AnimData.m_iHndl == -1)return;	//�A�j���[�V�������Đ�����Ă��Ȃ�

	//�A�j���[�V�������x�X�V
	AnimData.m_Frame += AnimData.m_Speed;

	if (AnimData.m_Frame >= AnimData.m_EndFrame)
	{
		//�ŏI�t���[���ɂȂ�����A��Ԃɂ��킹�ē����ς���
		switch (AnimData.m_State)
		{
		case ANIMESTATE_NORMAL:	//�ʏ�I��
			DetachAnim();
			AnimData.m_EndFrame = 0.0f;
			AnimData.m_Frame = 0.0f;
			AnimData.m_Speed = 0.0f;
			return;

		case ANIMESTATE_LOOP:	//���[�v���ŏ��ɖ߂�
			AnimData.m_Frame = 0.0f;
			break;

		case ANIMESTATE_END:
			AnimData.m_State = AnimData.m_EndFrame;
			break;

		default:
			break;
		}
	}

	//�Đ����Ԑݒ�
	MV1SetAttachAnimTime(iHndl, AnimData.m_iHndl, AnimData.m_Frame);
}

