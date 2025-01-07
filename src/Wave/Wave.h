#pragma once
#include <DxLib.h>

//�E�F�[�u�̏��
enum WAVE_STATE
{
	STATE_WAVE_NONE,		//�������ĂȂ�
	STATE_WAVE_PREPAR,		//�E�F�[�u������
	STATE_WAVE_NORMAL,		//�m�[�}���E�F�[�u��
	STATE_WAVE_BOTMOVE,		//�{�b�g�ړ��E�F�[�u��
	STATE_WAVE_END,			//�E�F�[�u�I��
};

//�E�F�[�u�N���X
class CWave
{
private:
	//CWave�N���X�̃|�C���^�ϐ�
	static CWave* cInstance;

	WAVE_STATE Wave_ID;		//�E�F�[�u�̏��

	bool IsWave;			//�E�F�[�u�t���O

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CWave();
	~CWave();

	bool GetIsWave() { return IsWave; }				//�t���O�̎擾
	WAVE_STATE GetWaveState() { return Wave_ID; }	//�E�F�[�u�̏�Ԏ擾

	void WaveStart(WAVE_STATE id);	//�E�F�[�u�J�n
	void WaveEnd(WAVE_STATE id);	//�E�F�[�u�I��

	void Draw();					//�E�F�[�u��

	//CGameData���擾
	static CWave* GetInstance();

	//CGameData���폜
	static void DeleteInstance();
};