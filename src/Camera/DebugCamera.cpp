#include "DebugCamera.h"
#include "../Input/Input.h"
#include <math.h>
#include "../MyLibrary/MyLibrary.h"

//�J�����̋���
#define CAMERA_LENGTH	(-30.0f)

//���_�̍���
#define CAMERA_OFFSET_Y	(400.0f)

//�����_�̍���
#define FOCUS_OFFSET_Y	(10.0f)

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
	CameraPos = VGet(0.0f, 30.0f, 0.0f);
	vRot = VGet(DX_PI_F, 0.0f, 0.0f);

}
void CDebugCamera::Init(VECTOR vPos, float fRot)
{
	CameraPos = vPos;
	vRot = VGet(DX_PI_F / 2.0f, 0.0f, 0.0f);
}

//���t���[���Ăԏ���
void CDebugCamera::Step(VECTOR vPos)
{
	VECTOR vDir;
	vDir.x = sinf(vRot.y) * CAMERA_LENGTH + 20.0f;
	vDir.z = cosf(vRot.y) * CAMERA_LENGTH - 200.0f;


	//���_�̍����͌Œ�
	vDir.y = CAMERA_OFFSET_Y;


	//�����_(�v���C���[)�̈ʒu����v�Z���ʂ̋������ړ�������΃J�����̎��_�ɂȂ�
	CameraPos = VAdd(vPos, vDir);

	FocusPos = vPos;
}

//�X�V�����f�[�^�𔽉f������
void CDebugCamera::Update()
{
	SetCameraPositionAndTargetAndUpVec(CameraPos, FocusPos, VGet(0.0f, 1.0f, 0.0f));
}

//-----------------------
//�f�o�b�N�J�������̕\��
//-----------------------
void CDebugCamera::Draw()
{
	DrawString(0, 0, "�f�o�b�N�J�������[�h", GetColor(255, 255, 255));
	DrawString(0, 15, "P�Őݒu", GetColor(255, 255, 255));
	DrawString(0, 30, "1:�`�F�b�N�|�C���g 2:�G�̃X�|�[���n�_", GetColor(255, 255, 255));
	DrawFormatString(0, 45, GetColor(255, 0, 0), "���WX�F%f, ���WY�F%f, ���WZ�F%f", CameraPos.x, CameraPos.y, CameraPos.z);
}

//�㏈��
void CDebugCamera::Exit()
{
	//������
	memset(&CameraPos, 0, sizeof(VECTOR));
	memset(&vRot, 0, sizeof(VECTOR));
}