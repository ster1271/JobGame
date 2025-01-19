#include "Wave.h"

CWave* CWave::cInstance = NULL;

//コンストラクタ
CWave::CWave()
{
	Wave_ID = STATE_WAVE_NONE;
	IsWave = false;
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


	Cnt = 780;
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
			Wave_ID = STATE_WAVE_NORMAL;
			IsWave = true;
			Cnt = 0;
		}

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

void CWave::Draw()
{
	switch (Wave_ID)
	{
	case STATE_WAVE_NONE:
		break;
	case STATE_WAVE_PREPAR:
		DrawFormatString(1000, 0, GetColor(255, 0, 0), "ウェーブ開始まであと %d秒", Cnt / 60);
		
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
