#include "WaveUI.h"

const char WAVE_UI_PATH[] = { "data/UI/wave/wave.png" };
const char FONT_NUMBER[] = { "data/UI/Number/number16x32_06.png" };


//コンストラクタ
CWaveUI::CWaveUI()
{
	BgHndl = -1;
	ChangeCount = 0;
	num = 0;
}

//デストラクタ
CWaveUI::~CWaveUI(){}

//初期化
void CWaveUI::Init()
{
	CUIBase::Init();
	BgHndl = -1;
	num = 80;
	ChangeCount = 0;
}

//読み込み
void CWaveUI::Load()
{
	BgHndl = LoadGraph(WAVE_UI_PATH);
	CNumber::SetNumber(FONT_NUMBER, 16, 32);
}

//毎フレーム行う処理
void CWaveUI::Step()
{

}

//描画
void CWaveUI::Draw()
{
	switch (CWave::GetInstance()->GetWaveState())
	{
	case STATE_WAVE_NONE:

		break;

	case STATE_WAVE_PREPAR:

		SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, num);
		DrawBox(0, 0, 1280, 720, GetColor(255, 0, 0), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		switch (ChangeCount)
		{
		case 0:
			num--;
			if (num < 0)
			{
				ChangeCount = 1;
			}
			break;

		case 1:
			num += 2;
			if (num > 80)
			{
				ChangeCount = 0;
			}
			break;

		default:
			break;
		}

		DrawRotaGraph(1280 / 2, 100, 2.0f, 0.0f, BgHndl, true, false, false);
		CNumber::DrawNumber_Normal(CWave::GetInstance()->GetTime(), VGet(635, 120, 0));
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

//後処理
void CWaveUI::Exit()
{
	CUIBase::Exit();
	BgHndl = -1;
}