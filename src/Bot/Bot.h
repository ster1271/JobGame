#pragma once 
#include "DxLib.h"
#include "../Object/Object.h"

//�{�b�g�N���X
class CBot :public CObject
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

	//�w��̏ꏊ�ɓ�������
	void Move_Bot();

};
