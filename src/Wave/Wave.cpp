#include "Wave.h"

CWave* CWave::cInstance = NULL;

//コンストラクタ
CWave::CWave()
{
	Wave_ID = STATE_WAVE_NONE;
	IsWave = false;
	IsNormal = false;
	IsBotMove = false;
	WaveTime = 0;
	StartWaveTime = -1;
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
		CSoundManager::SetVolume(SOUNDID_WAVE, 0.3f);
		CSoundManager::Play(SOUNDID_WAVE, DX_PLAYTYPE_LOOP, true);
		StartWaveTime = 600;
		break;

	case STATE_WAVE_NORMAL:
		CSoundManager::SetVolume(SOUNDID_WAVE, 0.4f);
		break;

	case STATE_WAVE_BOTMOVE:
		CSoundManager::SetVolume(SOUNDID_WAVE, 0.4f);
		break;

	case STATE_WAVE_END:
		SetIsWave(false);
		SetIsNormal(false);
		SetIsBotMove(false);
		StartWaveTime = 300;
		CSoundManager::Stop(SOUNDID_WAVE);
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
		
		//時間を増加させる
		WaveTime++;
		if (WaveTime > 100)
		{
			WaveStateChange(STATE_WAVE_PREPAR);			//ウェーブ準備中にする
			CWave::GetInstance()->SetIsNormal(true);	//通常ウェーブフラグをtrueにする
			WaveTime = 0;								//ウェーブ発生時間を初期化する
		}
		break;

	case STATE_WAVE_PREPAR:

		//UI表示のための時間を作る
		StartWaveTime--;
		if (StartWaveTime < 0)
		{
			StartWaveTime = 0;

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
	
		//UI表示のための時間を作る
		StartWaveTime--;
		if (StartWaveTime < 0)
		{
			StartWaveTime = 0;
			WaveStateChange(STATE_WAVE_NONE);
		}
		break;

	default:
		break;
	}
}

