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
	bool IsNormal;			//�m�[�}���E�F�[�u�t���O
	bool IsBotMove;			//�{�b�g�ړ��E�F�[�u�t���O
	int Cnt;				//���ԃJ�E���g
	
public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CWave();
	~CWave();

	//CGameData���擾
	static CWave* GetInstance();

	//CGameData���폜
	static void DeleteInstance();


	bool GetIsWave() { return IsWave; }					//�t���O�̎擾
	bool GetIsNormal() { return IsNormal; }				//�t���O�̎擾
	bool GetIsBotMove() { return IsBotMove; }			//�t���O�̎擾
	void SetIsWave(bool Flag) { IsWave = Flag;}			//�t���O�̐ݒ�
	void SetIsNormal(bool Flag) { IsNormal = Flag; }	//�t���O�̐ݒ�
	void SetIsBotMove(bool Flag) { IsBotMove = Flag; }	//�t���O�̐ݒ�

	WAVE_STATE GetWaveState() { return Wave_ID; }	//�E�F�[�u�̏�Ԏ擾
	int GetWaveTime() { return Cnt / 60; }			//���Ԏ擾

	void WaveStateChange(WAVE_STATE id);	//�E�F�[�u��ԕύX

	void Step();					

	void Draw();

};