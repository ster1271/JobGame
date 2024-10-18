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
	//�v���C������
	if (cCameraManager.GetCameraID() == CCameraManager::CAMERA_ID_PALY)
	{
		//�I�u�W�F�N�g�`��
		cObjectManager.Draw();
		//�L�����N�^�[�`��
		cCharacterManager.Draw();
		//�G�l�~�[�`��
		//cEnemyManager.Draw();
		//�^���b�g�`��
		//cTurretManager.Draw();
		//�e�`��
		//cShotManager.Draw();
		//�{�b�g�`��
		cBot.Draw();
		//�`�F�b�N�|�C���g�`��
		cCheck_Manager.Draw();

		cRoute_Search.Draw();
	}
	else if (cCameraManager.GetCameraID() == CCameraManager::CAMERA_ID_DEBUG)
	{
		//�I�u�W�F�N�g�`��
		cObjectManager.Draw();
		//�f�o�b�N���`��
		cCheck_Manager.DebugDraw();

		cGame_Pointer.Draw(cCheck_Manager.GetID());
	}

	//�J�������\��
	cCameraManager.Draw();
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
	//�G�l�~�[������
	cEnemyManager.Init();
	//�^���b�g������
	cTurretManager.Init();
	//�e������
	cShotManager.Init();
	//�{�b�g������
	cBot.Init();
	//�`�F�b�N�|�C���g������
	cCheck_Manager.Init();

	cGame_Pointer.Init();

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
	//�G�l�~�[�}�l�W���[�I������
	cEnemyManager.Exit();
	//�^���b�g�}�l�[�W���[�I������
	cTurretManager.Exit();
	//�e�I������
	cShotManager.Exit();
	//�{�b�g�N���X�I������
	cBot.Exit();
	//�`�F�b�N�|�C���g�I������
	cCheck_Manager.Exit();

	cGame_Pointer.Exit();

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
	//�G�l�~�[�f�[�^�ǂݍ���
	cEnemyManager.Load();
	//�^���b�g�f�[�^�ǂݍ���
	cTurretManager.Load();
	//�e�f�[�^�ǂݍ���
	cShotManager.Load();
	//�{�b�g�f�[�^�ǂݍ���
	cBot.Load();
	//�`�F�b�N�|�C���g�f�[�^�ǂݍ���
	cCheck_Manager.Load();

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

	//�X�V����
	//�v���C������
	if (cCameraManager.GetCameraID() == CCameraManager::CAMERA_ID_PALY)
	{
		//���C���L�������_�ύX
		if (CInput::IsKeyPush(KEY_INPUT_UP))
		{
			//���C���L�����֕ύX
			cCharacterManager.SetMainID(MainID_ATTACKER);
		}
		//else if (CInput::IsKeyPush(KEY_INPUT_DOWN))
		//{
		//	//CPU�L�����֕ύX
		//	//cCharacterManager.SetMainID(MainID_TANK);
		//	cCharacterManager.SetMainID(MainID_SUPPORT);
		//}

		//�I�u�W�F�N�g�X�V����
		cObjectManager.Step();
		//�L�����N�^�[�X�V����
		cCharacterManager.Step(cShotManager, cTurretManager);
		//�G�l�~�[�X�V����
		cEnemyManager.Step();
		//�^���b�g�X�V����
		cTurretManager.Step(cShotManager, cCharacterManager.GetPosition());
		//�e�X�V����
		cShotManager.Step(cCharacterManager.GetPosition());
		//�{�b�g�X�V����
		cBot.Step(cRoute_Search);
		//�`�F�b�N�|�C���g�X�V����
		cCheck_Manager.Step();
	}

	//�f�o�b�N������
	if (cCameraManager.GetCameraID() == CCameraManager::CAMERA_ID_DEBUG)
	{
		cGame_Pointer.Step(cCheck_Manager.GetID());

		//�f�o�b�N���X�V����
		cCheck_Manager.DebugStep(cGame_Pointer.GetPos());
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
	cCameraManager.Step(cCharacterManager.GetPosition(), cCharacterManager.GetRotate(), cGame_Pointer.GetPos());
}

