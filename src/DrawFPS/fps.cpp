#include "fps.h"

//������
void CFps::Init()
{
	memset(&frameRateInfo, 0, sizeof(FrameRateInfo));
}

//FPS�v�Z
void CFps::CalcFPS()
{
	//�O���FPS���v�Z�������Ԃ���o�ߎ��Ԃ����߂�
	int difTime = frameRateInfo.currentTime - frameRateInfo.calcFpsTime;

	//�O���FPS���v�Z�������Ԃ���
	//�P�b�ȏ�o�߂��Ă�����FPS���v�Z����
	if (difTime > 1000)
	{
		//�t���[���񐔂��~���b�ɍ��킹��
		//�����܂ŏo�������̂�float�ɃL���X�g
		float frameCount = (float)(frameRateInfo.g_count * 1000.0f);

		//FPS�����߂�
		//���z�̐��l��6000/1000��60�ƂȂ�
		frameRateInfo.fps = frameCount / difTime;

		//�t���[���J�E���g���N���A
		frameRateInfo.g_count = 0;

		//FPS���v�Z�������Ԃ��X�V
		frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
	}
}

//FPS�\��
void CFps::DrawFPS()
{
	unsigned int color = GetColor(255, 0, 0);
	DrawFormatString(SCREEN_SIZE_X-100, SCREEN_SIZE_Y-20, color, "FPS[%.2f]", frameRateInfo.fps);
}