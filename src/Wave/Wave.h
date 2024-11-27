#pragma once
#include <DxLib.h>

//�E�F�[�u�̏��
enum WAVE_STATE
{
	STATE_WAVE_NONE,	//�������ĂȂ�
	STATE_WAVE_START,	//�E�F�[�u�J�n
	STATE_WAVE_END,		//�E�F�[�u�I��
};

//�E�F�[�u�N���X
class CWave
{
private:
	//CWave�N���X�̃|�C���^�ϐ�
	static CWave* cInstance;

	WAVE_STATE Wave_ID;		//�E�F�[�u�̏��
	bool IsWave;				//�E�F�[�u�t���O

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CWave();
	~CWave();

	bool GetIsWave() { return IsWave; }		//�t���O�̎擾

	void WaveStart(WAVE_STATE id);
	void WaveEnd(WAVE_STATE id);

	//CGameData���擾
	static CWave* GetInstance();

	//CGameData���폜
	static void DeleteInstance();
};