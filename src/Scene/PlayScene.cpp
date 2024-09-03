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
	//�I�u�W�F�N�g�`��
	cObjectManager.Draw();
	//�L�����N�^�[�`��
	cCharacterManager.Draw();
	//�{�b�g�`��
	cBot.Draw();

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
	//�I�u�W�F�N�g������
	cObjectManager.Init();
	//�L�����N�^�[������
	cCharacterManager.Init();
	//�{�b�g������
	cBot.Init();
}


//-----------------------------------
//�I������
//-----------------------------------
void CPlayScene::Exit()
{
	//�J�����}�l�[�W���[�I������
	cCameraManager.Exit();
	//�I�u�W�F�N�g�}�l�[�W���[�I������
	cObjectManager.Exit();
	//�L�����N�^�[�}�l�[�W���[�I������
	cCharacterManager.Exit();
	//�{�b�g�N���X�I������
	cBot.Exit();
}


//-----------------------------------
//�f�[�^���[�h
//-----------------------------------
void CPlayScene::Load()
{
	//�I�u�W�F�N�g�f�[�^�ǂݍ���
	cObjectManager.Load();
	//�L�����N�^�[�f�[�^�ǂݍ���
	cCharacterManager.Load();
	//�{�b�g�f�[�^�ǂݍ���
	cBot.Load();
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

	//�J�������_�؂�ւ�
	if (cCameraManager.GetCameraID() == CCameraManager::CAMERA_ID_PALY)
	{
		//���C���L�������_�ύX
		if (CInput::IsKeyPush(KEY_INPUT_UP))
		{
			cCharacterManager.SetMainID(MainID_ATTACKER);
		}
		else if (CInput::IsKeyPush(KEY_INPUT_DOWN))
		{
			//cCharacterManager.SetMainID(MainID_TANK);
			cCharacterManager.SetMainID(MainID_SUPPORT);
		}

		//���_�ʒu�ύX(�A���O����ύX����)
		if (CInput::IsKeyKeep(KEY_INPUT_LEFT))
		{

		}
		else if (CInput::IsKeyPush(KEY_INPUT_DOWN))
		{

		}

		//�I�u�W�F�N�g�X�V����
		cObjectManager.Step();
		//�L�����N�^�[�X�V����
		cCharacterManager.Step();
		//�{�b�g�X�V����
		cBot.Step();
	}

	//�f�o�b�N�J�����Ƃ̐؂�ւ�����
	if (CInput::IsKeyPush(KEY_INPUT_C))
	{
		cCameraManager.ChangeCamera(CCameraManager::CAMERA_ID_DEBUG);
	}
	else if (CInput::IsKeyPush(KEY_INPUT_V))
	{
		cCameraManager.ChangeCamera(CCameraManager::CAMERA_ID_PALY);
	}

	//�J�����X�V����
	cCameraManager.Step(cCharacterManager.GetPosition(), VGet(0.0f, 0.0f, 0.0f));
}
