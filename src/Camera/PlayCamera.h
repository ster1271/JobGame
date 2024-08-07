#pragma once
#include <DxLib.h>

//�J�����N���X
class CPlayCamera
{
private:
	VECTOR CameraPos;			//�J�����̎��_
	VECTOR ForcusPos;			//�J�����̒����_
	VECTOR Up;					//�J�����̏����

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CPlayCamera();
	~CPlayCamera();

	//������
	void Init();
	void Init(VECTOR vPos, VECTOR vForcusPos, VECTOR vUp);

	//���t���[���Ăԏ���
	void Step(VECTOR vForcus, VECTOR fRot);

	//�X�V�����f�[�^�𔽉f������
	void Update();

	//�J�����̍��W�擾
	VECTOR GetPlayCameraPos() { return CameraPos; }

	//�J�����̒����_���擾
	VECTOR GetForcusPosition() { return ForcusPos; }

	//�J�����̏�����x�N�g�����擾
	VECTOR GetCameraUp() { return Up; }
};



