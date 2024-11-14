#pragma once
#include "../Base/Base.h"
#include "../GamePad/GamePad.h"

const VECTOR PLAYER_SIZE = VGet(15.0f, 30.0f, 15.0f);

//�A�j���[�V�������
enum PLAYER_STATE
{
	STATE_NONE = 0,
	STATE_DEFAULT,	//�ҋ@���[�V����
	STATE_RUN,		//���胂�[�V����
	STATE_SHOT,		//���������[�V����
};

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

//�A�^�b�J�[�N���X
class CPlayer : public CBase
{
private:
	VECTOR cNextPos;		//1�t���[����̍��W
	bool IsDir[DIR_NUM];	//�����t���O
	PLAYER_STATE Id;
	PLAYER_STATE oldId;

	DINPUT_JOYSTATE pad;

	void Default();
	void Run();
	void RunShot();

public:
	
	VECTOR GetNextPos() { return cNextPos; }				//���W�̎擾
	void SetNextPos(VECTOR NewPos) { cNextPos = NewPos;	}	//���W�̐ݒ�

	VECTOR GetModelSize() { return PLAYER_SIZE; }			//�v���C���[�̃T�C�Y�擾

	bool GetDir(int dir) { return IsDir[dir]; }				//�����t���O�擾
	void SetDir();											//�����t���O�ݒ�

	//�R���X�g���N�^�E�f�X�g���N�^
	CPlayer();
	~CPlayer();

	//������
	void Init();

	//�f�[�^�ǂݍ���
	void Load();

	//���t���[���s������
	void Step(CShotManager& cShotManager, CTurretManager& cTurretManager);

	//�`��
	void Draw();

	//�I������
	void Exit();
};
