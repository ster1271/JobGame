#include "DebugCamera.h"
#include "../Input/Input.h"
#include <math.h>
#include "../MyLibrary/MyLibrary.h"

//�J�����̋���
#define CAMERA_LENGTH	(30.0f)

//���_�̍���
#define CAMERA_OFFSET_Y	(10.0f)

//�����_�̍���
#define FORCUS_OFFSET_Y	(10.0f)

//�J�����̈ړ����x
#define CAMERA_MOVE_SPEED	(1.0f)

//�J�����̉�]���x
#define CAMERA_ROTATE_SPEED	(0.02f)

CDebugCamera::CDebugCamera()
{
	//������
	memset(&CameraPos, 0, sizeof(VECTOR));
	memset(&vRot, 0, sizeof(VECTOR));
}

CDebugCamera::~CDebugCamera()
{

}


//������
void CDebugCamera::Init()
{
	CameraPos = VGet(0.0f, 0.0f, 1.0f);
	vRot = VGet(0.0f, 0.0f, 0.0f);

}
void CDebugCamera::Init(VECTOR vPos, float fRot)
{
	CameraPos = vPos;
	vRot.y = fRot + DX_PI_F;
}

//���t���[���Ăԏ���
void CDebugCamera::Step()
{
	//�J�����̈ړ�
	float fSpd = 0.0f;
	if (CInput::IsKeyKeep(KEY_INPUT_W))
	{
		fSpd = CAMERA_MOVE_SPEED;
	}
	else if (CInput::IsKeyKeep(KEY_INPUT_S))
	{
		fSpd = -CAMERA_MOVE_SPEED;
	}
	float fRot = 0.0f;
	if (CInput::IsKeyKeep(KEY_INPUT_A)) {
		fSpd = -CAMERA_MOVE_SPEED;
		fRot = 90.0f * DX_PI_F / 180.0f;
	}
	else if (CInput::IsKeyKeep(KEY_INPUT_D)) {
		fSpd = CAMERA_MOVE_SPEED;
		fRot = 90.0f * DX_PI_F / 180.0f;
	}

	// �J�����̌����̑���
	if (CInput::IsKeyKeep(KEY_INPUT_UP)) {
		vRot.x -= CAMERA_ROTATE_SPEED;
	}
	else if (CInput::IsKeyKeep(KEY_INPUT_DOWN)) {
		vRot.x += CAMERA_ROTATE_SPEED;
	}
	else if (CInput::IsKeyKeep(KEY_INPUT_LEFT)) {
		vRot.y -= CAMERA_ROTATE_SPEED;
	}
	else if (CInput::IsKeyKeep(KEY_INPUT_RIGHT)) {
		vRot.y += CAMERA_ROTATE_SPEED;
	}

	// ���͂����L�[���ƃJ�����̊p�x����A�ړ����x�����߂�
	CameraPos.x += sinf(vRot.y + fRot) * fSpd;
	CameraPos.z += cosf(vRot.y + fRot) * fSpd;
}

//�X�V�����f�[�^�𔽉f������
void CDebugCamera::Update()
{
	SetCameraPositionAndAngle(CameraPos, vRot.x, vRot.y, vRot.z);
}

//-----------------------
//�f�o�b�N�J�������̕\��
//-----------------------
void CDebugCamera::Draw()
{
	DrawString(0, 0, "�f�o�b�N�J�������[�h", GetColor(255, 255, 255));
	DrawFormatString(0, 15, GetColor(255, 255, 255), "���WX�F%f, ���WY�F%f, ���WZ�F%f", CameraPos.x, CameraPos.y, CameraPos.z);
}