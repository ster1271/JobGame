#pragma once
#include "../Wave/Wave.h"
#include "WaveUI/WaveUI.h"

//UI�}�l�[�W���[
class CUIManager
{
private:
	

	CWaveUI cWaveUI;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CUIManager();
	~CUIManager();

	//�ǂݍ���
	void Load();

	//�`��
	void Draw();
};
