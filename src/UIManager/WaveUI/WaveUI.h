#pragma once
#include "../UIBase/BaseUI.h"
#include "../../Wave/Wave.h"

class CWaveUI : public CUIBase
{
private:
	int BgHndl;

public:
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

