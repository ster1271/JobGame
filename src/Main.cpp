#include "DxLib.h"
#include "Common.h"
#include "DrawFPS/fps.h"
#include "Input/Input.h"
#include "Scene/SceneManager.h"


// Win32�A�v���P�[�V������ WinMain�֐� ����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(true);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) {
		return -1;
	}

	// ��ʃT�C�Y��ύX
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//�`�悷��X�N���[����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);
	
	//-----------------------------------------
	//��ԍŏ��ɂP�񂾂���鏈���������ɏ���
	
	//�C���v�b�g������
	CInput::InitInput();

	//�V�[���}�l�[�W���[
	SceneManager cSceneManager;

	//FPS
	CFps cFps;

	//������
	cFps.Init();

	

	//-----------------------------------------

	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{
		Sleep(1);	//�V�X�e��������Ԃ�

		//���݂̎��Ԃ��擾
		cFps.frameRateInfo.currentTime = GetNowCount();

		//�ŏ��̃��[�v�Ȃ�
		//���݂̎��Ԃ��AFPS�̌v�Z���������Ԃɐݒ�
		if (cFps.frameRateInfo.calcFpsTime == 0.0f)
		{
			cFps.frameRateInfo.calcFpsTime = cFps.frameRateInfo.currentTime;
			cFps.frameRateInfo.fps = (float)FRAME_RATE;
		}

		//���݂̎��Ԃ��A�O��̃t���[�������
		//1000/60�~���b�i1/60�j�ȏ�o�߂��������珈�������s����
		if (cFps.frameRateInfo.currentTime - cFps.frameRateInfo.LastFrameTime >= FRAME_TIME)
		{
			//�t���[�����s���̎��Ԃ��X�V
			cFps.frameRateInfo.LastFrameTime = cFps.frameRateInfo.currentTime;

			//�t���[�������J�E���g
			cFps.frameRateInfo.g_count++;

			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			{
				//�G�X�P�[�v�L�[�������ꂽ��I��
				break;
			}

			//��ʂɕ\�����ꂽ���̂�������
			ClearDrawScreen();

			CInput::StepInput();

			//-----------------------------------------
			//��������Q�[���̖{�̂��������ƂɂȂ�
			//-----------------------------------------

			//�v�Z����
			cSceneManager.Loop();


			//�`�揈��
			cSceneManager.Draw();

			//FPS�v�Z
			cFps.CalcFPS();

			//FPS�\��
			cFps.DrawFPS();

			//-----------------------------------------
			//���[�v�̏I����
			//�t���b�v�֐�
			ScreenFlip();

		}
	}

	//-----------------------------------------
	//�Ō�ɂP�񂾂���鏈���������ɏ���

	//-----------------------------------------
	//DX���C�u�����̌㏈��
	DxLib_End();

	return 0;
}

