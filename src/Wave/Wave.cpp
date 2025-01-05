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

//ウェーブ開始
void CWave::WaveStart(WAVE_STATE id)
{
	if (id == STATE_WAVE_NONE)
		return;

	if (id == STATE_WAVE_PREPAR)
	{
		IsWave = true;					//フラグをtrueに
		Wave_ID = STATE_WAVE_PREPAR;	//状態を準備中に
	}
}

//ウェーブ終了
void CWave::WaveEnd(WAVE_STATE id)
{
	if (id == STATE_WAVE_NONE)
		return;

	if (id == STATE_WAVE_END)
	{
		IsWave = false;				//フラグをfalseに
		Wave_ID = STATE_WAVE_NONE;	//状態を何もしていないに
	}
}
