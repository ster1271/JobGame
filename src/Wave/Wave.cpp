#include "Wave.h"

CWave* CWave::cInstance = NULL;

//コンストラクタ
CWave::CWave()
{
	Wave_ID = STATE_WAVE_NONE;
	IsWave = false;
	IsNormal = false;
	IsBotMove = false;

	Cnt = -1;
}

//デストラクタ
CWave::~CWave() {}

//CWaveを取得
CWave* CWave::GetInstance()
{
	//まだ生成されていないなら
	if (cInstance == NULL)
	{
		cInstance = new CWave();
	}

	return cInstance;
}

//CWaveを削除
void CWave::DeleteInstance()
{
	//インスタンスがNULLでないなら
	if (cInstance != NULL)
	{
		delete cInstance;
		cInstance = NULL;				//削除してNULL代入
	}
}


//ウェーブ状態変更
void CWave::WaveStateChange(WAVE_STATE id)
{
	Wave_ID = id;

	switch (Wave_ID)
	{
	case STATE_WAVE_NONE:
		break;

	case STATE_WAVE_PREPAR:
		Cnt = 600;
		break;

	case STATE_WAVE_NORMAL:
		break;

	case STATE_WAVE_BOTMOVE:
		break;

	case STATE_WAVE_END:
		Cnt = 600;
		break;

	default:
		break;
	}
}


void CWave::Step()
{
	switch (Wave_ID)
	{
	case STATE_WAVE_NONE:
		break;

	case STATE_WAVE_PREPAR:
		Cnt--;

		if (Cnt < 0)
		{
			Cnt = 0;

			SetIsWave(true);

			//ノーマルウェーブ
			if (IsNormal)
			{
				WaveStateChange(STATE_WAVE_NORMAL);
			}

			//ボット移動ウェーブ
			if (IsBotMove)
			{
				WaveStateChange(STATE_WAVE_BOTMOVE);
			}	
		}

		break;
	case STATE_WAVE_NORMAL:

		break;

	case STATE_WAVE_BOTMOVE:

		break;

	case STATE_WAVE_END:
		WaveStateChange(STATE_WAVE_NONE);
		SetIsWave(false);
		SetIsNormal(false);
		SetIsBotMove(false);
		break;

	default:
		break;
	}
}

