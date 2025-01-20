#include "WaveUI.h"

const char WAVE_UI_PATH[] = { "data/UI/wave/wave.png" };


//������
void CWaveUI::Init()
{
	CUIBase::Init();
	BgHndl = -1;
}

//�ǂݍ���
void CWaveUI::Load()
{
	BgHndl = LoadGraph(WAVE_UI_PATH);
}

//���t���[���s������
void CWaveUI::Step()
{

}

//�`��
void CWaveUI::Draw()
{
	switch (CWave::GetInstance()->GetWaveState())
	{
	case STATE_WAVE_NONE:

		break;

	case STATE_WAVE_PREPAR:

		SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, 255);
		DrawBox(0, 0, 1280, 720, GetColor(255, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, 0);


		DrawRotaGraph(1280 / 2, 100, 2.0f, 0.0f, BgHndl, true, false, false);
		break;

	case STATE_WAVE_NORMAL:

		break;

	case STATE_WAVE_BOTMOVE:

		break;

	case STATE_WAVE_END:

		break;

	default:
		break;
	}
}

//�㏈��
void CWaveUI::Exit()
{
	CUIBase::Exit();
	BgHndl = -1;
}