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
	int Cnt;				//���ԃJ�E���g
	
	int hnd;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CWave();
	~CWave();

	//CGameData���擾
	static CWave* GetInstance();

	//CGameData���폜
	static void DeleteInstance();


	bool GetIsWave() { return IsWave; }				//�t���O�̎擾
	WAVE_STATE GetWaveState() { return Wave_ID; }	//�E�F�[�u�̏�Ԏ擾

	void WaveStateChange(WAVE_STATE id);	//�E�F�[�u��ԕύX

	void Step();					

	void Draw();

};