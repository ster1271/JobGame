#pragma once
#include "../../Common.h"
#include "../../Object/Object.h"

//�u���b�N�N���X
class CBlock :public CObject
{
private:

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CBlock();
	~CBlock();

	//������
	void Init();

	//���t���[���s��
	void Step();

	//�㏈��
	void Exit();
};