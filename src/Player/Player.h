#pragma once
#include "../Base/Base.h"
#include "../GamePad/GamePad.h"

enum PLAYER_STATE
{
	STATE_NONE = 0,
	STATE_DEFAULT,	//�ҋ@���[�V����
	STATE_RUN,		//���胂�[�V����
	STATE_SHOT,		//���������[�V����
};

//�A�^�b�J�[�N���X
class CPlayer : public CBase
{
private:
	VECTOR cNextPos;
	PLAYER_STATE Id;
	PLAYER_STATE oldId;

	DINPUT_JOYSTATE pad;

	void Default();
	void Run();
	void RunShot();

public:
	VECTOR GetNextPos() { return cNextPos; }

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
