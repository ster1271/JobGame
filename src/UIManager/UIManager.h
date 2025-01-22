#pragma once
#include "../Wave/Wave.h"
#include "WaveUI/WaveUI.h"
#include "PlayerUI/PlayerUI.h"

//UI�}�l�[�W���[
class CUIManager
{
private:
	CPlayerUI cPlayerUI;
	CWaveUI cWaveUI;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CUIManager();
	~CUIManager();

	//������
	void Init();

	//�ǂݍ���
	void Load();

	//�`��
	void Draw();

	//���t���[���s������
	void Step();
};
