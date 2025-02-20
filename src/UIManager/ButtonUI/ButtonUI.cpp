#include "ButtonUI.h"

const char GAUGE_FLAME_PATH[] = { "data/UI/button/gauge_frame.png" };
const char GAUGE_PATH[] = { "data/UI/button/gauge.png" };

//�R���X�g���N�^�E�f�X�g���N�^
CButtonUI::CButtonUI()
{
	for (int i = 0; i < BUTTONID_NUM; i++)
	{
		ButtonHndl[i] = -1;
	}
	GaugeFlameHndl = -1;
	GaugeHndl = -1;

	Cnt = 0;
}

CButtonUI::~CButtonUI(){}

//������
void CButtonUI::Init()
{
	GaugeFlameHndl = -1;
	GaugeHndl = -1;
	Cnt = 0.0f;

	for (int i = 0; i < BUTTONID_NUM; i++)
	{
		ButtonHndl[i] = -1;
	}
}

//�ǂݍ���
bool CButtonUI::Load()
{
	GaugeFlameHndl = LoadGraph(GAUGE_FLAME_PATH);
	GaugeHndl = LoadGraph(GAUGE_PATH);	

	//�{�^���S�Ẳ摜�n���h���̓ǂݍ���
	bool IsLoaded = true;
	for (int i = 0; i < BUTTONID_NUM; i++)
	{
		ButtonHndl[i] = LoadGraph(ButtonFileName[i]);
		//1�ł����[�h���s������΃t���O���I�t��
		if (ButtonHndl[i] == -1)
		{
			IsLoaded = false;
		}
	}

	return IsLoaded;
}

//���t���[���s������
void CButtonUI::Step(const int Count)
{
	Cnt = Count * 2;
}

//�`��
void CButtonUI::Draw()
{
	DrawCircleGauge(300, 300, Cnt, GaugeHndl, 0.0f);
	DrawBillboard3D(VGet(1250.0f, 20.0f, 1150.0f), 0.5, 0.5f, 15, 0.0f, GaugeFlameHndl, true, false, false);
	DrawBillboard3D(VGet(1250.0f, 20.0f, 1150.0f), 0.5, 0.5f, 15, 0.0f, ButtonHndl[BUTTONID_A], true, false, false);
}

//�㏈��
void CButtonUI::Exit()
{
	GaugeFlameHndl = -1;
	GaugeHndl = -1;
}