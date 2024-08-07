#include "PlayScene.h"



//��`�֘A----------------------------------

//------------------------------------------


//------------------------------------------
//�R���X�g���N�^
//------------------------------------------
CPlayScene::CPlayScene()
{
	//�ЂƂ܂��������ɂ��Ă���
	eSceneID = PLAY_SCENE_INIT;
}


//------------------------------------------
//�f�X�g���N�^
//------------------------------------------
CPlayScene::~CPlayScene()
{
	//�O�̈�
	Exit();
}

//------------------------------------------
//���t���[���Ăԏ���
//------------------------------------------
int CPlayScene::Loop()
{
	int iRet = 0;
	switch (eSceneID)
	{
	case PLAY_SCENE_INIT:
		Init();
		eSceneID = PLAY_SCENE_LAOD;
		break;

	case PLAY_SCENE_LAOD:
		Load();
		eSceneID = PLAY_SCENE_LOOP;
		break;

	case PLAY_SCENE_LOOP:
		Step();
		Draw();
		break;

	case PLAY_SCENE_END:
		Exit();
		eSceneID = PLAY_SCENE_INIT;
		iRet = 1;
		break;

	default:
		break;
	}

	return iRet;
}


//-----------------------------------
//�X�V����
//-----------------------------------
void CPlayScene::Draw()
{
	cCharacterManager.Draw();

	DrawString(0, 0, "�v���C��ʂł�", GetColor(255, 255, 255));
	DrawString(0, 15, "Enter�ŃV�[���ړ�", GetColor(255, 255, 255));
}


//-----------------------------------
//������
//-----------------------------------
void CPlayScene::Init()
{
	//�J����������
	cCameraManager.Init();
	cCameraManager.SetNearFar(5.0f, 10000.0f);
	//�L�����N�^�[������
	cCharacterManager.Init();
}


//-----------------------------------
//�I������
//-----------------------------------
void CPlayScene::Exit()
{
	//�J�����}�l�[�W���[�I������
	cCameraManager.Exit();
	//�L�����N�^�[�}�l�[�W���[�I������
	cCharacterManager.Exit();
}


//-----------------------------------
//�f�[�^���[�h
//-----------------------------------
void CPlayScene::Load()
{
	cCharacterManager.Load();
}


//-----------------------------------
//���t���[���Ăԏ���
//-----------------------------------
void CPlayScene::Step()
{
	//�V�[���J�ڏ���(��)
	if (CInput::IsKeyPush(KEY_INPUT_RETURN))
	{
		eSceneID = PLAY_SCENE_END;
	}

	if (cCameraManager.GetCameraID() == CCameraManager::CAMERA_ID_PALY)
	{
		if (CInput::IsKeyPush(KEY_INPUT_LEFT))
		{
			
		}
		else if (CInput::IsKeyPush(KEY_INPUT_RIGHT))
		{

		}
		cCharacterManager.Step();
	}

	//�J�����̐؂�ւ�����
	if (CInput::IsKeyPush(KEY_INPUT_C))
	{
		cCameraManager.ChangeCamera(CCameraManager::CAMERA_ID_DEBUG);
	}
	else if (CInput::IsKeyPush(KEY_INPUT_V))
	{
		cCameraManager.ChangeCamera(CCameraManager::CAMERA_ID_PALY);
	}



	//�J�����X�V����
	/*cCameraManager.Step(cCharacterManager.GetPosition(), VGet(0.0f, 0.0f, 0.0f));*/
}
