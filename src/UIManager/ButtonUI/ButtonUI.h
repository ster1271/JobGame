#pragma once
#include "../UIBase/BaseUI.h"
#include "../../Player/Player.h"

//�{�^��
enum ButtonID
{
	BUTTONID_A,
	BUTTONID_B,
	BUTTONID_X,
	BUTTONID_Y,

	BUTTONID_NUM
};

const char ButtonFileName[BUTTONID_NUM][128] =
{
	"data/UI/button/Button_A.png",
	"data/UI/button/Button_B.png",
	"data/UI/button/Button_X.png",
	"data/UI/button/Bottun_Y.png",
};

class CButtonUI :public CUIBase
{
private:
	int ButtonHndl[BUTTONID_NUM];
	int GaugeFlameHndl;
	int GaugeHndl;
	int CurrentGaugeVol;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CButtonUI();
	~CButtonUI();

	//������
	void Init();

	//�ǂݍ���
	bool Load();

	//���t���[���s������
	void Step(const int Count);

	//�`��
	void Draw();

	//�㏈��
	void Exit();
};
