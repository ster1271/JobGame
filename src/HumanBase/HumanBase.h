#pragma once
#include "../Common.h"

//�v���C���[����
enum PLAYER_DIR
{
	DIR_RIGHT = 0,	//�E
	DIR_LEFT,		//��
	DIR_UP,			//��
	DIR_DOWN,		//��
	DIR_BACK,		//��
	DIR_NEAR,		//��O

	DIR_NUM,		//���ԍ�
};

class CHumanBase
{
protected:
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
	ANIME_DATA AnimDataInfo;	//�A�j���Đ��f�[�^

	VECTOR cPos;				//���W
	VECTOR cNextPos;			//1�t���[����̍��W
	VECTOR cRotate;				//�L�����N�^�[�̌����̉�]��
	VECTOR cMoveRotate;			//�L�����N�^�[�̕����w��̉�]��
	VECTOR cSpeed;				//�L�����N�^�[���x
	VECTOR cScale;				//�T�C�Y
	VECTOR cSize;				//���f���̕�

	bool IsActive;				//�����t���O
	int iHndl;					//�n���h��
	float Life;					//���C�t
	int PushCnt;				//�{�^�������Ă��鎞��
	int ReturnCnt;				//�{�b�g�ɖ߂邽�߂̎���
	float StoreRot;			//�p�x�ۑ�

	bool IsDir[DIR_NUM];	//�����t���O


public:

	VECTOR GetPos() { return cPos; }						//���W�擾
	VECTOR GetNextPos() { return cNextPos; }				//���W�擾
	void SetNextPos(VECTOR NewPos) { cNextPos = NewPos; }	//���W�ݒ�
	VECTOR GetRotate() { return cRotate; }					//��]�l�擾
	VECTOR GetSpeed() { return cSpeed; }					//���x�擾
	VECTOR GetSize() { return cSize; }						//�T�C�Y�擾
	bool GetIsActive() { return IsActive; }					//�t���O�擾
	bool GetDir(int dir) { return IsDir[dir]; }				//�����t���O�擾


	//�R���X�g���N�^�E�f�X�g���N�^
	CHumanBase();
	~CHumanBase();

	//������
	void Init();

	//�f�[�^�ǂݍ���
	void Load(const char FILEPATH[]);

	//�`��
	void Draw();

	//���t���[���s������
	void Step();

	//���X�V
	void UpData();

	//�㏈��
	void Exit();

	//�A�j���A�b�v�f�[�g
	void UpdateAnim();

	//���N�G�X�g
	void Reqest(int iAnimID, float iAnimSpd, int iAnimHndl = -1, bool NameCheck = false);

	//���[�v�A�j�����N�G�X�g(�A�j�����ŏI�t���[���ɂȂ�����ŏ��ɖ߂�)
	void ReqestLoop(int iAnimID, float iAnimSpd, int iAnimHndl = -1, bool NameCheck = false);

	//�G���h���[�v�A�j�����N�G�X�g(�A�j�����ŏI�t���[���ɂȂ�����~�܂�)
	void ReqestEndLoop(int iAnimID, float iAnimSpd, int iAnimHndl = -1, bool NameCheck = false);

	//�A�j�����f�^�b�`
	void DetachAnim();

	//�L�����N�^�[��]����
	void Player_Rotation();

	//�����t���O�ݒ�
	void SetDir();											


};
