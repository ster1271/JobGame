#pragma once
#include "../Base/Base.h"

enum ANIME_STATE
{
	ANIMEID_DEFAULT = 0,//�f�t�H���g(����T�|�[�Y)
	ANIMEID_WALK,		//����
	ANIMEID_RUNSHOT,	//���茂��


	ANIME_NUM,			//�A�j���[�V�����̑���
};

//�A�^�b�J�[�N���X
class CAttacker : public CBase
{
private:
	int ID;
	void Default() {};
	void Walk() {};
	void RunShot() {};
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
