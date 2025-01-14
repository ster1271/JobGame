#pragma once
#include "../GamePad/GamePad.h"
#include "../Mouse/Mouse.h"
#include "../HumanBase/HumanBase.h"
#include "../Shot/ShotManager.h"
#include "../Turret/TurretManager.h"
#include "../Wave/Wave.h"
#include "../Map/MapManager.h"

const VECTOR PLAYER_POS = VGet(50.0f, 0.0f, 50.0f);		//�������W
const VECTOR PLAYER_SIZE = VGet(15.0f, 30.0f, 15.0f);	//�v���C���[�T�C�Y
const VECTOR PLAYER_SCALE = VGet(0.05f, 0.05f, 0.05f);	//�v���C���[�X�P�[��
const float SPERE_R = 3.0f;								//���a
const float MOVESPEED = 1.5f;							//�ʏ�ړ��X�s�[�h
const float SHOTMOVESPEED = 0.5f;						//�ˌ����ړ��X�s�[�h
const float ROT_SPEED = 0.05f;							//��]�X�s�[�h
const int SHOT_COOL_TIME = 15;							//�e�̔��ˊԊu
const int PLAYER_MAX_LIFE = 100;						//�ő�̗�


//�A�j���[�V�������
enum PLAYER_STATE
{
	STATE_NONE = 0,
	STATE_DEFAULT,	//�ҋ@���[�V����
	STATE_RUN,		//���胂�[�V����
	STATE_SHOT,		//�ˌ����[�V����
};

//�A�^�b�J�[�N���X
class CPlayer : public CHumanBase
{
private:
	bool IsDir[DIR_NUM];	//�����t���O
	PLAYER_STATE Id;
	PLAYER_STATE oldId;
	float fSpd;
	int ShotCoolCount;			//�e�N�[���^�C���p�ϐ�

	void Default();
	void Run();
	void Shot();

public:

	//�R���X�g���N�^�E�f�X�g���N�^
	CPlayer();
	~CPlayer();

	//������
	void Init();

	//�f�[�^�ǂݍ���
	void Load();

	//���t���[���s������
	void Step(CShotManager& cShotManager, CTurretManager& cTurretManager, CMapManager& cMapManager, VECTOR BotPos);

	//�`��
	void Draw();

	//�I������
	void Exit();

	//���x�ύX
	void ChangeSpeed();

	//�ړ�����
	void Move();

	//���˃��N�G�X�g����
	void PlayerShot(CShotManager& cShotManager);

	//�E�F�[�u�J�n����
	void StartWave();

	//�{�b�g�̈ʒu�Ɉړ�
	void BackBotPosition(VECTOR vPos);

};
