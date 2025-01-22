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
		CPlayer::GetInstance()->Draw();
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
		//UI�`��
		cUIManager.Draw();
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
	TIME = 0;

	//�J����������
	cCameraManager.Init();
	cCameraManager.SetNearFar(5.0f, 10000.0f);
	//�I�u�W�F�N�g������
	cObjectManager.Init();
	//�}�b�v�S�ʏ�����
	cMapManager.Init();
	//�L�����N�^�[������
	CPlayer::GetInstance()->Init();
	//�G�l�~�[������
	cEnemyManager.Init();
	//�^���b�g������
	cTurretManager.Init();
	//�e������
	cShotManager.Init();
	//�{�b�g������
	cBot.Init();
	//UI�}�l�[�W���[������
	cUIManager.Init();
}


//-----------------------------------
//�I������
//-----------------------------------
void CPlayScene::Exit()
{
	TIME = 0;

	//�J�����}�l�[�W���[�I������
	cCameraManager.Exit();
	//�I�u�W�F�N�g�}�l�[�W���[�I������
	cObjectManager.Exit();
	//�}�b�v�S�ʏI������
	cMapManager.Exit();
	//�L�����N�^�[�I������
	CPlayer::GetInstance()->Exit();
	//�G�l�~�[�}�l�W���[�I������
	cEnemyManager.Exit();
	//�^���b�g�}�l�[�W���[�I������
	cTurretManager.Exit();
	//�e�I������
	cShotManager.Exit();
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
	CPlayer::GetInstance()->Load();
	//�G�l�~�[�f�[�^�ǂݍ���
	cEnemyManager.Load();
	//�^���b�g�f�[�^�ǂݍ���
	cTurretManager.Load();
	//�e�f�[�^�ǂݍ���
	cShotManager.Load();
	//�{�b�g�f�[�^�ǂݍ���
	cBot.Load();
	//�~�j�}�b�v�ǂݍ���
	cMiniMap.Load();
	//UI�ǂݍ���
	cUIManager.Load();
}


//-----------------------------------
//���t���[���Ăԏ���
//-----------------------------------
void CPlayScene::Step()
{
	TIME++;
	if (CWave::GetInstance()->GetWaveState() == STATE_WAVE_NONE)
	{
		//���Ԃ𑝉�������
		CWave::GetInstance()->SetWaveTime(TIME);
	}

	//�V�[���I������
	if (cBot.GetFinish())
	{
		eSceneID = PLAY_SCENE_END;
	}

	//�X�V����
	//�v���C������
	if (cCameraManager.GetCameraID() == CCameraManager::CAMERA_ID_PALY)
	{
		if (CWave::GetInstance()->GetWaveTime() > 1200)
		{
			CWave::GetInstance()->WaveStateChange(STATE_WAVE_PREPAR);
			CWave::GetInstance()->SetIsNormal(true);
			CWave::GetInstance()->SetWaveTime(0);
		}

		CDebugString::GetInstance()->AddFormatString(200, 200, "1200 / %d", CWave::GetInstance()->GetWaveTime());

		//�I�u�W�F�N�g�X�V����
		cObjectManager.Step();
		//�}�b�v�S�ʏ��� 
		cMapManager.Step();
		//�~�j�}�b�v�`��
		cMiniMap.Step(CPlayer::GetInstance()->GetPos(), CPlayer::GetInstance()->GetSpeed(), CPlayer::GetInstance()->GetRotate(), cMapManager);
		//�L�����N�^�[�X�V����
		CPlayer::GetInstance()->Step(cShotManager, cTurretManager, cMapManager, cBot.GetPos());
		CPlayer::GetInstance()->UpData();
		//�G�l�~�[�X�V����
		cEnemyManager.Step(cBot, cMapManager);
		//�^���b�g�X�V����
		cTurretManager.Step(cShotManager, cEnemyManager);
		//�e�X�V����
		cShotManager.Step(CPlayer::GetInstance()->GetPos());
		//�{�b�g�X�V����
		cBot.Step(cMapManager);
		//�E�F�[�u����
		CWave::GetInstance()->Step();

		//=======�����蔻�菈��==========//
		cCollisionManager.PlayerToMap(cMapManager);
		cCollisionManager.TurretShotToEnemy(cShotManager, cEnemyManager);
		cCollisionManager.PlayerShotToEnemy(cShotManager, cEnemyManager);
		cCollisionManager.PlayerShotToMap(cShotManager, cMapManager);
		cCollisionManager.TurretShotToMap(cShotManager, cMapManager);
		cCollisionManager.PlayerToGoal(cMapManager);
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
	cCameraManager.Step(CPlayer::GetInstance()->GetPos(), CPlayer::GetInstance()->GetRotate(), VECTOR_ZERO);
}

