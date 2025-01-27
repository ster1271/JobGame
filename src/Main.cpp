#include "Common.h"
#include "DrawFPS/fps.h"
#include "Scene/SceneManager.h"
#include "Debug/DebugString.h"
#include "Effect/effekseer.h"



// Win32�A�v���P�[�V������ WinMain�֐� ����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(TRUE);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) {
		return -1;
	}

	// ��ʃT�C�Y��ύX
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//�`�悷��X�N���[����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);
	// Z�\�[�g����
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	SetTransColor(255, 0, 255);	// ���ߐF�w��

	//���C�g�ݒ�
	SetUseLighting(TRUE);
	
	//-----------------------------------------
	//��ԍŏ��ɂP�񂾂���鏈���������ɏ���
	
	//�L�[�{�[�h������
	CInput::InitInput();
	//�Q�[���p�b�h������	
	CGamePad::InitGamePad();
	//�}�E�X������
	CMouse::InitMouse();

	//�V�[���}�l�[�W���[
	SceneManager cSceneManager;

	//FPS�̐錾�Ə�����
	CFps cFps;
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


			//�L�[�{�[�h���X�V
			CInput::StepInput();
			//�Q�[���p�b�h���X�V
			CGamePad::StepGamePad();
			//�}�E�X���X�V
			CMouse::StepMouse();

			//�G�X�P�[�v�L�[�܂��̓X�^�[�g�{�^���������ꂽ��I��
			if (CInput::IsKeyPush(KEY_INPUT_ESCAPE) || CGamePad::IsPadPush(DX_INPUT_PAD1, BUTTON_BACK))
				break;

			//��ʂɕ\�����ꂽ���̂�������
			ClearDrawScreen();

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
	CEffekseerCtrl::Exit();

	//-----------------------------------------
	//DX���C�u�����̌㏈��
	DxLib_End();

	return 0;
}

