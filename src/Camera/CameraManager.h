#pragma once
#include "PlayCamera.h"
#include "DebugCamera.h"

class CCameraManager
{
public:

	//�J�����̃^�C�v
	enum tagCAMERA_ID
	{
		CAMERA_ID_PALY,		//�Q�[�����̃J����
		CAMERA_ID_DEBUG,    //�f�o�b�O�p�̃J����(����쐬)

		CAMERA_ID_NUM
	};

private:
	CPlayCamera cPlayCam;			//�v���C���[�J����
	CDebugCamera cDebugCam;			//�f�o�b�N�J����
	tagCAMERA_ID eCurrentCameraID;	//���݂̃J����ID

	float			PlayerRotateY;	//�v���C���[�̊p�x

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CCameraManager();
	~CCameraManager();

	void Init();
	void Init(VECTOR vPos, VECTOR vFocus, VECTOR vUp);

	//�I������
	void Exit();

	//�X�V����
	void Step(VECTOR vForcus, VECTOR fRot);

	//�`��
	void Draw();

	//�J�����̃j�A�E�t�@�[�ݒ�
	void SetNearFar(float fNear, float fFar);

	//�J�����̃^�C�v�ύX
	void ChangeCamera(tagCAMERA_ID ID);

	//���݂̃J�����^�C�v�擾
	tagCAMERA_ID GetCameraID() { return eCurrentCameraID; }

	//�v���C���[�̍��W�Ɗp�x��ۑ�
	void SetPlayerRot(float vRot);

};

