#include "Wave.h"

CWave* CWave::cInstance = NULL;

//�R���X�g���N�^
CWave::CWave()
{
	Wave_ID = STATE_WAVE_NONE;
	IsWave = false;
}

//�f�X�g���N�^
CWave::~CWave() {}

//CWave���擾
CWave* CWave::GetInstance()
{
	//�܂���������Ă��Ȃ��Ȃ�
	if (cInstance == NULL)
	{
		cInstance = new CWave();
	}

	return cInstance;
}

//CWave���폜
void CWave::DeleteInstance()
{
	//�C���X�^���X��NULL�łȂ��Ȃ�
	if (cInstance != NULL)
	{
		delete cInstance;
		cInstance = NULL;				//�폜����NULL���
	}
}


//�E�F�[�u��ԕύX
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
		DrawFormatString(1000, 0, GetColor(255, 0, 0), "�E�F�[�u�J�n�܂ł��� %d�b", Cnt / 60);
		
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
