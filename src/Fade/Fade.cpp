#include "Fade.h"

CFade::tagFadeState CFade::m_eState = STATE_FADE_NONE;
bool CFade::m_bIsEndFlag = false;
int CFade::m_iAlpha = 0;
int CFade::m_iAddAlpha = 0;

// �A���t�@�l�̍ő�l
#define ALPHA_MAX 255

// �A���t�@�l�̍ŏ��l
#define ALPHA_MIN 0

// �R���X�g���N�^�E�f�X�g���N�^
CFade::CFade() {}
CFade::~CFade() {}

// �ʏ폈��
void CFade::Step(){
	switch (m_eState)
	{
	case CFade::STATE_FADE_IN:
		m_iAlpha += m_iAddAlpha;
		if (m_iAlpha > ALPHA_MAX) {
			m_iAlpha = ALPHA_MAX;
			m_bIsEndFlag = true;
		}
		break;
	case CFade::STATE_FADE_OUT:
		m_iAlpha -= m_iAddAlpha;
		if (m_iAlpha < ALPHA_MIN) {
			m_iAlpha = ALPHA_MIN;
			m_bIsEndFlag = true;
		}
		break;
	case CFade::STATE_FADE_NONE:
		break;
	}
}

// �`��
void CFade::Draw(){
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_iAlpha);
	DrawBox(0, 0, 640, 480, GetColor(255, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

// �t�F�[�h�J�n
void CFade::StartFade(tagFadeState fadeState, int addAlpha){
	if (m_eState != STATE_FADE_NONE)
		return;

	m_eState = fadeState;
	m_iAddAlpha = addAlpha;
	m_bIsEndFlag = false;

	switch (m_eState)
	{
	case CFade::STATE_FADE_IN:
		m_iAlpha = ALPHA_MIN;
		break;
	case CFade::STATE_FADE_OUT:
		m_iAlpha = ALPHA_MAX;
		break;
	}
}

bool CFade::GetIsEndFlag() {
	if (m_eState == STATE_FADE_NONE || !m_bIsEndFlag)
		return false;

	m_eState = STATE_FADE_NONE;
	m_bIsEndFlag = false;
	return true;
}