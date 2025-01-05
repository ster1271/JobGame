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

//�E�F�[�u�J�n
void CWave::WaveStart(WAVE_STATE id)
{
	if (id == STATE_WAVE_NONE)
		return;

	if (id == STATE_WAVE_PREPAR)
	{
		IsWave = true;					//�t���O��true��
		Wave_ID = STATE_WAVE_PREPAR;	//��Ԃ���������
	}
}

//�E�F�[�u�I��
void CWave::WaveEnd(WAVE_STATE id)
{
	if (id == STATE_WAVE_NONE)
		return;

	if (id == STATE_WAVE_END)
	{
		IsWave = false;				//�t���O��false��
		Wave_ID = STATE_WAVE_NONE;	//��Ԃ��������Ă��Ȃ���
	}
}
