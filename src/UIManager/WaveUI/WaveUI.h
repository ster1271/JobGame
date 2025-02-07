#pragma once
#include "../UIBase/BaseUI.h"
#include "../../DrawNumberFont/DrawNumberFont.h"
#include "../../DrawFont/DrawFont.h"
#include "../../Wave/Wave.h"


class CWaveUI : public CUIBase
{
private:
	int BgHndl;
	int Alpha;			//���ߒl
	int ChangeCount;	//�X�C�b�`��

public:
	//void SetAlpha(int Cnt) { Alpha = Cnt; }	//���ߒl�ݒ�

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

