#include "ResultScene.h"


//-------------------------------------
//�R���X�g���N�^
//-------------------------------------
CResultScene::CResultScene()
{
	//�Ƃ肠�����������Ɉړ�������
	eSceneID = RESULT_SCENE_INIT;
}
//-------------------------------------
//�f�X�g���N�^
//-------------------------------------
CResultScene::~CResultScene()
{
	Exit();
}

//-------------------------------------
//������
//-------------------------------------
void CResultScene::Init()
{

}

//-------------------------------------
//���[�h
//-------------------------------------
void CResultScene::Load()
{
	
}


//-------------------------------------
//���[�v���鏈��
//-------------------------------------
int CResultScene::Loop()
{
	int iRet = 0;
	switch (eSceneID)
	{
	case RESULT_SCENE_INIT:
		Init();
		eSceneID = RESULT_SCENE_LAOD;
		break;

	case RESULT_SCENE_LAOD:
		Load();
		eSceneID = RESULT_SCENE_LOOP;
		break;

	case RESULT_SCENE_LOOP:
		Step();
		break;

	case RESULT_SCENE_END:
		Exit();
		iRet = 1;
		break;


	default:
		break;
	}

	return iRet;
}


//-------------------------------------
//���g�̏���
//-------------------------------------
void CResultScene::Step()
{
	//�V�[���J�ڏ���(��)
	if (CInput::IsKeyPush(KEY_INPUT_RETURN) || CGamePad::IsPadPush(DX_INPUT_PAD1, BUTTON_Y))
	{
		eSceneID = RESULT_SCENE_END;
	}
}

//-------------------------------------
//�`�揈��
//-------------------------------------
void CResultScene::Draw()
{
	DrawString(0, 0, "���U���g��ʂł�", GetColor(255, 255, 255));
	DrawString(0, 15, "Enter�܂���Y�{�^���ŃV�[���ړ�", GetColor(255, 255, 255));

}

//-------------------------------------
//�㏈��1
//-------------------------------------
void CResultScene::Exit()
{
	//�V�[��ID��INIT�ɖ߂�
	eSceneID = RESULT_SCENE_INIT;
}
