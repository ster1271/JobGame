#pragma once
#include <DxLib.h>

class CSoundManager
{
public:
	enum tagSoundID
	{
		SOUNDID_BGM,		//�Q�[������BGM
		SOUNDID_SE_PLSHOT,	//�v���C���[�̔��ˉ�
		SOUNDID_SE_EXPLORE,	//������

		SOUNDID_NUM
	};

private:
	static int m_iHndl[SOUNDID_NUM];	//�T�E���h�n���h��

public:
	CSoundManager();
	~CSoundManager();

	//������
	static void Init();

	//�I������
	static void Exit();

	//�f�[�^�̓ǂݍ���
	static bool LoadAllData();


	//----�擾�֌W-----

	//�Đ����Ԏ擾(�~���b)
	//���k�`���̍Đ��f�[�^�͕s��
	static int GetSoundTime(tagSoundID iID);

	//�Đ����Ԏ擾(�~���b)
	static int GetSoundAllTime(tagSoundID iID);

	//���y�Đ�����
	//	iID : �f�[�^�ǂݍ��݂����ۂ�ID�ԍ�
	//  return : true = �Đ���, false = ��~��
	static bool IsPlay(tagSoundID iID);


	//----�ݒ�֘A----

	//�Đ��J�n���Ԑݒ�
	//  ms : �Đ��J�n����(�~���b)
	//	Play()�O�ɐݒ肵�APlay()�ł͓r������Đ��ɂ��Ă�������
	//	�g�p���͕K����~���Ă���ɂ��܂��傤
	static void SetStartFrame(tagSoundID iID, int ms);

	//�{�����[���ݒ�
	// fVol : �{�����[��(0.0 �` 1.0)
	static void SetVolume(tagSoundID iID, float fVol);


	//----���y�Đ��֌W----

	//���y�Đ�
	// iID		: �f�[�^�̓ǂݍ��݂����ۂ�ID�ԍ�
	// iType	: �Đ��^�C�v DX���C�u�����Ɠ���
	// isStart	: true = �ŏ�����Đ�, false = �r������Đ�
	// return	: 0 = ����, -1 = �G���[
	static int Play(tagSoundID iID, int iType = DX_PLAYTYPE_BACK, bool isStart = true);

	//���y��~
	// iID		:�@�f�[�^�ǂݍ��݂����ۂ�ID�ԍ�
	// return	:  0 = ����, -1 = �G���[
	static int Stop(tagSoundID iID);

	//�S���y��~
	static void StopAll();



};
