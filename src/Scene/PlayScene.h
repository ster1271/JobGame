#pragma once

#include "../Input/Input.h"
#include "../CollisionManager/CollisionManager.h"
#include "../Camera/CameraManager.h"
#include "../Shot/ShotManager.h"
#include "../Character/CharacterManager.h"
#include "../Enemy/EnemyManager.h"
#include "../Turret/TurretManager.h"
#include "../Object/ObjectManager.h"
#include "../Bot/Bot.h"

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

	//���W���i�[
	struct PosInfo
	{
		VECTOR PlayerPos;
		VECTOR TurretPos;
	};


	tagPLAY_SCENE eSceneID;
	PosInfo Posinfo;	

	CCameraManager cCameraManager;			//�J�����}�l�[�W���[
	CShotManager cShotManager;				//�V���b�g�}�l�[�W���[
	CCharacterManager cCharacterManager;	//�L�����N�^�[�}�l�[�W���[
	CEnemyManager cEnemyManager;			//�G�l�~�[�}�l�[�W���[
	CObjectManager cObjectManager;			//�I�u�W�F�N�g�}�l�[�W���[
	CTurretManager cTurretManager;			//�^���b�g�}�l�[�W���[
	CBot cBot;								//�{�b�g�N���X
	

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
