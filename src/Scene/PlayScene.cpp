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
		//�}�b�v�S�ʕ`�� 
		cMapManager.Draw();
		//�L�����N�^�[�`��
		cPlayer.Draw();
		//�^���b�g�`��
		cTurretManager.Draw();
		//�G�l�~�[�`��
		cEnemyManager.Draw();
		//�e�`��
		cShotManager.Draw();
		//�{�b�g�`��
		cBot.Draw();
		//�~�j�}�b�v�`��
		cMiniMap.Draw();
	}
	else if (cCameraManager.GetCameraID() == CCameraManager::CAMERA_ID_DEBUG)
	{
		//�I�u�W�F�N�g�`��
		cObjectManager.Draw();
		//�f�o�b�N���`��
	}

	//�J�������\��
	cCameraManager.Draw();

	CDebugString::GetInstance()->Draw();

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
	//�}�b�v�S�ʏ�����
	cMapManager.Init();
	//�L�����N�^�[������
	cPlayer.Init();
	//�G�l�~�[������
	cEnemyManager.Init();
	//�^���b�g������
	cTurretManager.Init();
	//�e������
	cShotManager.Init();
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
	//�}�b�v�S�ʏI������
	cMapManager.Exit();
	//�L�����N�^�[�I������
	cPlayer.Exit();
	//�G�l�~�[�}�l�W���[�I������
	cEnemyManager.Exit();
	//�^���b�g�}�l�[�W���[�I������
	cTurretManager.Exit();
	//�e�I������
	//cShotManager.Exit();
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
	//�}�b�v�S�ʃf�[�^�ǂݍ���
	cMapManager.Load();
	//�L�����N�^�[�f�[�^�ǂݍ���
	cPlayer.Load();
	//�G�l�~�[�f�[�^�ǂݍ���
	cEnemyManager.Load();
	//�^���b�g�f�[�^�ǂݍ���
	cTurretManager.Load();
	//�e�f�[�^�ǂݍ���
	cShotManager.Load();
	//�{�b�g�f�[�^�ǂݍ���
	cBot.Load();
	//�~�j�}�b�v�`��
	cMiniMap.Load();
}


//-----------------------------------
//���t���[���Ăԏ���
//-----------------------------------
void CPlayScene::Step()
{
	//�V�[���J�ڏ���(��)
	if (cBot.GetFinish())
	{
		eSceneID = PLAY_SCENE_END;
	}

	//�X�V����
	//�v���C������
	if (cCameraManager.GetCameraID() == CCameraManager::CAMERA_ID_PALY)
	{
		//�I�u�W�F�N�g�X�V����
		cObjectManager.Step();
		//�}�b�v�S�ʏ��� 
		cMapManager.Step();
		//�~�j�}�b�v�`��
		cMiniMap.Step(cPlayer.GetPos(), cPlayer.GetRotate(), cMapManager);
		//�L�����N�^�[�X�V����
		cPlayer.Step(cShotManager, cTurretManager, cMapManager, cBot.GetPos());
		cPlayer.UpData();
		//�G�l�~�[�X�V����
		cEnemyManager.Step(cBot, cMapManager);
		//�^���b�g�X�V����
		cTurretManager.Step(cShotManager, cEnemyManager);
		//�e�X�V����
		cShotManager.Step(cPlayer.GetPos());
		//�{�b�g�X�V����
		cBot.Step(cMapManager);



		//=======�����蔻�菈��==========//
		cCollisionManager.PlayerToMap(cPlayer, cMapManager);
		cCollisionManager.TurretShotToEnemy(cShotManager, cEnemyManager);
		cCollisionManager.PlayerShotToEnemy(cShotManager, cEnemyManager);
		cCollisionManager.PlayerShotToMap(cShotManager, cMapManager);
		cCollisionManager.TurretShotToMap(cShotManager, cMapManager);
		cCollisionManager.PlayerToGoal(cPlayer, cMapManager);
	}

	//�f�o�b�N������
	if (cCameraManager.GetCameraID() == CCameraManager::CAMERA_ID_DEBUG)
	{

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
	cCameraManager.Step(cPlayer.GetPos(), cPlayer.GetRotate(), VGet(0.0f,0.0f,0.0f));
}

