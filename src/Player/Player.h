#pragma once
#include "../GamePad/GamePad.h"
#include "../HumanBase/HumanBase.h"
#include "../Shot/ShotManager.h"
#include "../Turret/TurretManager.h"

const VECTOR PLAYER_POS = VGet(50.0f, 0.0f, 50.0f);
const VECTOR PLAYER_SIZE = VGet(15.0f, 30.0f, 15.0f);
const VECTOR PLAYER_SCALE = VGet(0.05f, 0.05f, 0.05f);
const float SPERE_R = 3.0f;
const float MOVESPEED = 2.0f;
const float ROT_SPEED = 0.05f;


//�A�j���[�V�������
enum PLAYER_STATE
{
	STATE_NONE = 0,
	STATE_DEFAULT,	//�ҋ@���[�V����
	STATE_RUN,		//���胂�[�V����
	STATE_SHOT,		//���������[�V����
};

//�A�^�b�J�[�N���X
class CPlayer : public CHumanBase
{
private:
	bool IsDir[DIR_NUM];	//�����t���O
	PLAYER_STATE Id;
	PLAYER_STATE oldId;
	float fSpd;

	void Default();
	void Run();
	void RunShot();

public:

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

	//�R���g���[���[�ړ�����
	void Move_CON();

};
