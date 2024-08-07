#include <DxLib.h>
#include "CameraManager.h"
#include "../Input/Input.h"

static const VECTOR DEFAULT_EYE_POS = { 0.0f, 0.0f, -20.0f };
static const VECTOR DEFAULT_FORCUS_POS = { 0.0f, 0.0f, 0.0f };
static const VECTOR DEFAULT_UP_VEC = { 0.0f, 1.0f, 0.0f };


//-------------------------
//�R���X�g���N�^
//-------------------------

CCameraManager::CCameraManager()
{
	//�����ɃQ�[�����̃J�����ɂ���
	eCurrentCameraID = CAMERA_ID_PALY;
	PlayerRotateY = 0.0f;
}


//-------------------------
//�f�X�g���N�^
//-------------------------
CCameraManager::~CCameraManager()
{

}

//-------------------------
//������
//-------------------------
void CCameraManager::Init()
{
	cPlayCam.Init(DEFAULT_EYE_POS, DEFAULT_FORCUS_POS, DEFAULT_UP_VEC);
	cDebugCam.Init(DEFAULT_EYE_POS);
}

//-------------------------
//������
//-------------------------
void CCameraManager::Init(VECTOR vPos, VECTOR vForcus, VECTOR vUp)
{
	cPlayCam.Init(vPos, vForcus, vUp);
	cDebugCam.Init(vPos);
}

//-------------------------
//�I������
//-------------------------
void CCameraManager::Exit()
{
}

//-------------------------
//���t���[���Ăԏ���
//-------------------------
void CCameraManager::Step(VECTOR vForcus, VECTOR fRot)
{
	//�J�����̃^�C�v�ɍ��킹�āA�X�V������ύX����
	switch (eCurrentCameraID)
	{
	case CAMERA_ID_PALY:
		cPlayCam.Step(vForcus, fRot);
		cPlayCam.Update();
		break;

	case CAMERA_ID_DEBUG:
		cDebugCam.Step();
		cDebugCam.Update();
		
	default:
		break;
	}
	
}


//�`��
void CCameraManager::Draw()
{
	switch (eCurrentCameraID)
	{
	case CCameraManager::CAMERA_ID_DEBUG:

		cDebugCam.Draw();
		break;
	default:
		break;
	}
}

//-------------------------
//�J�����̃j�A�E�t�@�[�ݒ�
//-------------------------
void CCameraManager::SetNearFar(float fNear, float fFar)
{
	SetCameraNearFar(fNear, fFar);
}

//�J�����^�C�v�ύX
void CCameraManager::ChangeCamera(tagCAMERA_ID ID)
{
	// ID�ύX
	eCurrentCameraID = ID;

	// �ύX��ɃJ������������
	switch (eCurrentCameraID)
	{
	case CCameraManager::CAMERA_ID_DEBUG:
		// �f�o�b�O�J����������
		cDebugCam.Init(cPlayCam.GetPlayCameraPos(), PlayerRotateY);
	default:
		break;
	}

	return;
}


//�v���C���[�̊p�x��ۑ�
void CCameraManager::SetPlayerRot(float vRot)
{
	PlayerRotateY = vRot;
}