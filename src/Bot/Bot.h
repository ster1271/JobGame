#pragma once 
#include "DxLib.h"
#include "../Base/Base.h"

//�{�b�g�N���X
class CBot :public CBase
{
private:

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CBot();
	~CBot();

	//������
	void Init();

	//�ǂݍ���
	bool Load();

	//�`��
	void Draw();

	//���t���[���s������
	void Step();
};
