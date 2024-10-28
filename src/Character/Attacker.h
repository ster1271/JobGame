#pragma once
#include "../Base/Base.h"

enum PLAYER_STATE
{
	STATE_NONE = 0,
	STATE_DEFAULT,
	STATE_RUN,
	STATE_SHOT,
};

//�A�^�b�J�[�N���X
class CAttacker : public CBase
{
private:
	PLAYER_STATE Id;

	void Default();
	void Run();
	void RunShot();
public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CAttacker();
	~CAttacker();

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
