#pragma once
#include <DxLib.h>

class CGameData
{
public:
	int MaxScore;		//�ő�X�R�A
	int CurrentScore;	//���݃X�R�A	

	//�v���C���[�f�[�^
	struct PlayerData
	{
		int MaxHp;		//�v���C���[�̍ő僉�C�t
		int CurrentHp;	//�v���C���[�̌��݃��C�t
	};

	
	//�K�w�f�[�^
	struct FloarData
	{
		int MaxFloar;		//�ő�K�w
		int CurrentFloar;	//���݊K�w
	};


private:
	//CData�N���X�̃|�C���^�ϐ�
	static CGameData* cInstance;

	PlayerData cPlayerData;		//�v���C���[�f�[�^
	FloarData cFloarData;		//�K�w�f�[�^


	//�ő�X�R�A�擾�E�ݒ�
	int GetMaxScore() { return MaxScore; }
	void SetMaxScore(int Score) { MaxScore = Score; }

	//���݃X�R�A�擾�E�ݒ�
	int GetCurrentScore() { return CurrentScore; }
	void SetCurrentScore(int Score) { CurrentScore = Score; }

	//�v���C���[�f�[�^�擾
	PlayerData GetPlayerData() { return cPlayerData; }

	//�K�w�f�[�^�擾
	FloarData GetFloarData() { return cFloarData; }


public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CGameData();
	~CGameData();

	//CGameData���擾
	static CGameData* GetInstance();

	//CGameData���폜
	static void DeleteInstance();

};