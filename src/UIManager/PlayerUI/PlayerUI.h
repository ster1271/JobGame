#pragma once
#include "../UIBase/BaseUI.h"

class CPlayerUI :public CUIBase
{
private:
	int HPHndl;
	 

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CPlayerUI();
	~CPlayerUI();

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
