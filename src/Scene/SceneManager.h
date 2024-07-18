#pragma once
#include <DxLib.h>
#include "PlayScene.h"
#include "TitleScene.h"
#include "ResultScene.h"
#include "../SoundManager/SoundManager.h"
#include "../Input/Input.h"


class SceneManager
{
private:
	enum tagSCENE
	{
		SCENE_TITLE,	//�^�C�g�����
		SCENE_PLAY,		//�Q�[����
		SCENE_RESULT,	//���U���g���

		SCENE_NUM
	};

	tagSCENE eSceneID;				//�V�[���ۑ�

	CTitleScene cTitleScene;		//�^�C�g���V�[��
	CPlayScene cPlayScene;			//�v���C�V�[��
	CResultScene cResultScene;		//���U���g�V�[��

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	SceneManager();
	~SceneManager();

	//�J��Ԃ��s������
	void Loop();

	//�`�揈��
	void Draw();

};