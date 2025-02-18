#pragma once
#include <DxLib.h>

//�A�j���Đ����
enum ANIME_STATE
{
	ANIMESTATE_NORMAL = 0,
	ANIMESTATE_LOOP,
	ANIMESTATE_END,
};


//�A�j���֘A�̃f�[�^���܂Ƃ߂��\����
struct ANIME_DATA
{
	float m_EndFrame;
	float m_Frame;
	float m_Speed;
	int m_iHndl;
	int m_AnimID;
	int m_OldAnimID;
	int m_State;
};

static ANIME_DATA AnimDataInfo;	//�A�j���Đ��f�[�^

class CAnim
{
private:

public:
	//������
	static void Init();

	//�㏈��
	static void Exit();

	//�A�j���A�b�v�f�[�g
	static void UpdateAnim(int iHndl);

	//���N�G�X�g
	static void Reqest(int iHndl, int iAnimID, float iAnimSpd, int iAnimHndl = -1, bool NameCheck = false);

	//���[�v�A�j�����N�G�X�g(�A�j�����ŏI�t���[���ɂȂ�����ŏ��ɖ߂�)
	static void ReqestLoop(int iHndl, int iAnimID, float iAnimSpd, int iAnimHndl = -1, bool NameCheck = false);

	//�G���h���[�v�A�j�����N�G�X�g(�A�j�����ŏI�t���[���ɂȂ�����~�܂�)
	static void ReqestEndLoop(int iHndl, int iAnimID, float iAnimSpd, int iAnimHndl = -1, bool NameCheck = false);

	//�A�j�����f�^�b�`
	static void DetachAnim(int iHndl);
};