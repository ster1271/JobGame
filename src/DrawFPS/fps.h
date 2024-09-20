#pragma once
#include <DxLib.h>
#include "../Common.h"

//�ݒ�t���[�����[�g�i60FPS�j
#define FRAME_RATE	(60)

//�P�t���[���̎��ԁi�~���b�j
#define FRAME_TIME	(1000 / FRAME_RATE)

struct FrameRateInfo
{
	int currentTime;	//���݂̎���
	int LastFrameTime;	//�O��̃t���[�����s���̎���
	int g_count;			//�t���[���J�E���g�p
	int calcFpsTime;	//FPS���v�Z��������
	float fps;			//�v�Z����FPS(�\���p)
};

class CFps
{
public:
	//�t���[�����[�g���ϐ�
	FrameRateInfo frameRateInfo;

public:
	//������
	void Init();

	//FPS�v�Z
	void CalcFPS();

	//FPS�\��(�f�o�b�N�p�j
	void DrawFPS();
};
