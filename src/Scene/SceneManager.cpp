#include "SceneManager.h"

//=============��`�֘A================


//=====================================

//-------------------------------------
//�R���X�g���N�^
//-------------------------------------
SceneManager::SceneManager()
{
	//�^�C�g����ʂ��Ȃ��̂�SCENE_PLAY��
	eSceneID = SCENE_TITLE;
	CInput::InitInput();
	CSoundManager::Init();
	CSoundManager::LoadAllData();
}

//-------------------------------------
//�f�X�g���N�^
//-------------------------------------
SceneManager::~SceneManager()
{
	CSoundManager::Exit();
}



//-------------------------------------
//���t���[���Ăԏ���
//-------------------------------------
void SceneManager::Loop()
{
	switch (eSceneID)
	{
	case SCENE_TITLE:
		if (cTitleScene.Loop() != 0)
		{
			eSceneID = SCENE_PLAY;
		}
		break;

	case SCENE_PLAY:
		if (cPlayScene.Loop() != 0)
		{
			eSceneID = SCENE_RESULT;
		}
		break;

	case SCENE_RESULT:
		if (cResultScene.Loop() != 0)
		{
			eSceneID = SCENE_TITLE;
		}
		break;

	case SCENE_NUM:

		break;

	default:
		break;
	}
}


//-------------------------------------
//���t���[���Ăԏ���
//-------------------------------------
void SceneManager::Draw()
{
	switch (eSceneID)
	{
	case SCENE_TITLE:

		break;

	case SCENE_PLAY:

		break;

	case SCENE_RESULT:

		break;

	case SCENE_NUM:

		break;

	default:
		break;
	}
}
