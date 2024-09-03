#pragma once
#include "../Object/Sky/Sky.h"
#include "../Object/Ground/Ground.h"


//�I�u�W�F�N�g�}�l�[�W���[�N���X
class CObjectManager
{
private:
	CSky cSky;			//�V���N���X
	CGround cGround;	//�}�b�v�N���X

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CObjectManager();
	~CObjectManager();

	//������
	void Init();

	//�ǂݍ��݊֘A
	void Load();

	//�`��
	void Draw();

	//���t���[���s������
	void Step();

	//�X�V����
	void Update();

	//�㏈��
	void Exit();
};
