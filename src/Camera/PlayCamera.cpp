#include "DxLib.h"
#include "math.h"
#include "PlayCamera.h"
#include "../MyLibrary/MyLibrary.h"

//�J�����̋���
#define CAMERA_LENGTH	(80.0f)

//���_�̍���
#define CAMERA_OFFSET_Y	(50.0f)

//�����_�̍���
#define FORCUS_OFFSET_Y	(30.0f)

//�R���X�g���N�^
CPlayCamera::CPlayCamera()
{
	//������
	memset(&CameraPos, 0, sizeof(VECTOR));
	memset(&ForcusPos, 0, sizeof(VECTOR));
	memset(&Up, 0, sizeof(VECTOR));

}

//�f�X�g���N�^
CPlayCamera::~CPlayCamera()
{

}

//������
void CPlayCamera::Init()
{
	//�O�̂��ߏ����l��ݒ�
	CameraPos = VGet(0.0f, 0.0f, 1.0f);
	ForcusPos = VGet(0.0f, 0.0f, 0.0f);
	Up = VGet(0.0f, 1.0f, 0.0f);
	
}

//������
void CPlayCamera::Init(VECTOR vPos, VECTOR vForcusPos, VECTOR vUp)
{
	CameraPos = vPos;
	ForcusPos = vForcusPos;
	Up = vUp;
}

//���t���[���Ăԏ���
void CPlayCamera::Step(VECTOR vForcus, VECTOR fRot)
{
	VECTOR vDir;
	vDir.x = sinf(fRot.y) * CAMERA_LENGTH;
	vDir.z = cosf(fRot.y) * CAMERA_LENGTH;

	//���_�̍����͌Œ�
	vDir.y = CAMERA_OFFSET_Y;

	//�����_(�v���C���[)�̈ʒu����v�Z���ʂ̋������ړ�������΃J�����̎��_�ɂȂ�
	CameraPos = VAdd(vForcus, vDir);

	//�����_�̓^�[�Q�b�g�̈ʒu�𗘗p����
	ForcusPos = vForcus;
	ForcusPos.y = FORCUS_OFFSET_Y;
}

//�X�V�����f�[�^�𔽉f������
void CPlayCamera::Update()
{
	SetCameraPositionAndTargetAndUpVec(CameraPos, ForcusPos, Up);
}

