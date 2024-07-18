#include <DxLib.h>
#include "PlayScene.h"
#include "../CollisionManager/CollisionManager.h"
#include "../Input/Input.h"


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
	DrawString(0, 0, "�v���C��ʂł�", GetColor(255, 255, 255));
	DrawString(0, 15, "Enter�ŃV�[���ړ�", GetColor(255, 255, 255));
}


//-----------------------------------
//������
//-----------------------------------
void CPlayScene::Init()
{

}


//-----------------------------------
//�I������
//-----------------------------------
void CPlayScene::Exit()
{

}


//-----------------------------------
//�f�[�^���[�h
//-----------------------------------
void CPlayScene::Load()
{
	
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
}
