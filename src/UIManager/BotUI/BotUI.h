#pragma once
#include "../UIBase/BaseUI.h"

class CBotUI :public CUIBase
{
private:


public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CBotUI();
	~CBotUI();

	//������
	void Init();

	//�ǂݍ���
	void Load();

	//���t���[���s������
	void Step();

	//�`��
	void Draw();

	//�㏈��
	void Exit();

};