#include "Wave.h"

CWave* CWave::cInstance = NULL;

//�R���X�g���N�^
CWave::CWave()
{
	Wave_ID = STATE_WAVE_NONE;
	IsWave = false;
	IsNormal = false;
	IsBotMove = false;

	Cnt = -1;
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

			//�m�[�}���E�F�[�u
			if (IsNormal)
			{
				WaveStateChange(STATE_WAVE_NORMAL);
			}

			//�{�b�g�ړ��E�F�[�u
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

