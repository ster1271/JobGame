#pragma once
#include "DxLib.h"

class CFade {
public:
	// �R���X�g���N�^�E�f�X�g���N�^
	CFade();
	~CFade();

	enum tagFadeState {
		STATE_FADE_IN,		// �t�F�[�h�C����
		STATE_FADE_OUT,		// �t�F�[�h�A�E�g��
		STATE_FADE_NONE,	// �������Ă��Ȃ�
	};

	// �ʏ폈��
	static void Step();

	// �`��
	static void Draw();

	// �t�F�[�h�J�n
	static void StartFade(tagFadeState fadeState, int addAlpha);

	// �t�F�[�h�I���t���O���擾
	static bool GetIsEndFlag();

private:
	// ���݂̏��
	static tagFadeState m_eState;

	// �t�F�[�h�����t���O
	static bool m_bIsEndFlag;

	// �A���t�@�l
	static int m_iAlpha;

	// ���Z����A���t�@�l�̒l
	static int m_iAddAlpha;
};