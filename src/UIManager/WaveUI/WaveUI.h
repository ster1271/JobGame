#pragma once
#include "../UIBase/BaseUI.h"
#include "../../DrawFont/DrawNumberFont.h"
#include "../../Wave/Wave.h"


class CWaveUI : public CUIBase
{
private:
	int BgHndl;
	int StartHndl;
	int ClearHndl;
	int num;
	int ChangeCount;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CWaveUI();
	~CWaveUI();

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

