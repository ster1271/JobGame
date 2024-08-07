#pragma once

#include "../Input/Input.h"
#include "../CollisionManager/CollisionManager.h"
#include "../Camera/CameraManager.h"
#include "../Character/CharacterManager.h"


class CPlayScene
{
private:
	enum tagPLAY_SCENE
	{
		PLAY_SCENE_INIT,
		PLAY_SCENE_LAOD,
		PLAY_SCENE_LOOP,
		PLAY_SCENE_END,

		PLAY_SCENE_NUM
	};

	tagPLAY_SCENE eSceneID;

	CCameraManager cCameraManager;			//�J�����}�l�[�W���[
	CCharacterManager cCharacterManager;	//�L�����N�^�[�}�l�[�W���[

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CPlayScene();
	~CPlayScene();

	//�J��Ԃ��s������
	int Loop();

	//�`�揈��
	void Draw();

private:
	//������
	void Init(void);

	//�I������
	void Exit();

	//�f�[�^���[�h
	void Load();

	//���t���[���Ăԏ���
	void Step();

};
