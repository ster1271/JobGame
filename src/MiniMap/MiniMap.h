#pragma once
#include "../Common.h"

//�~�j�}�b�v�N���X
class CMiniMap
{
private:


public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CMiniMap();
	~CMiniMap();

	//������
	void Init();

	//�f�[�^�ǂݍ���
	void Load();

	//�`��
	void Draw();

	//���t���[���s������
	void Step();

	//���X�V
	void UpData();

	//�㏈��
	void Exit();
};

