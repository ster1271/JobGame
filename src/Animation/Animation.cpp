#include "Animation.h"

//������
void CAnim::Init()
{
	memset(&AnimDataInfo, -1, sizeof(AnimDataInfo));
}

//�㏈��
void CAnim::Exit()
{
	memset(&AnimDataInfo, -1, sizeof(AnimDataInfo));
}

//���N�G�X�g
void CAnim::Reqest(int iHndl, int iAnimID, float iAnimSpd, int iAnimHndl, bool NameCheck)
{
	//�O�̃A�j���[�V������o�����������珈�����Ȃ�
	if (AnimDataInfo.m_OldAnimID == iAnimID)
		return;

	//�A�j������
	DetachAnim(iHndl);

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
void CAnim::ReqestLoop(int iHndl, int iAnimID, float iAnimSpd, int iAnimHndl, bool NameCheck)
{

	Reqest(iHndl, iAnimID, iAnimSpd, iAnimHndl, NameCheck);
	//�A�j���Đ���Ԃ����[�v�ɕς���
	AnimDataInfo.m_State = ANIMESTATE_LOOP;
}

//�G���h���[�v�A�j�����N�G�X�g(�A�j�����ŏI�t���[���ɂȂ�����~�܂�)
void CAnim::ReqestEndLoop(int iHndl, int iAnimID, float iAnimSpd, int iAnimHndl, bool NameCheck)
{
	Reqest(iHndl, iAnimID, iAnimSpd, iAnimHndl, NameCheck);
	//�A�j���Đ���Ԃ��G���h���[�v�ɕς���
	AnimDataInfo.m_State = ANIMESTATE_END;
}

//�A�j�����f�^�b�`
void CAnim::DetachAnim(int iHndl)
{
	if (AnimDataInfo.m_iHndl != -1)
	{
		MV1DetachAnim(iHndl, AnimDataInfo.m_iHndl);
		AnimDataInfo.m_iHndl = -1;
	}
}

//�A�j���A�b�v�f�[�g
void CAnim::UpdateAnim(int iHndl)
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
			DetachAnim(iHndl);
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