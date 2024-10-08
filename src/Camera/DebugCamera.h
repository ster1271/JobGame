#pragma once
#include <DxLib.h>

//�J�����N���X
class CDebugCamera
{
private:
	VECTOR CameraPos;	//���_
	VECTOR FocusPos;	//�����_
	VECTOR vRot;		//�J�����̊p�x

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CDebugCamera();
	~CDebugCamera();

	//������
	void Init();
	void Init(VECTOR vPos, float fRot = 0.0f);

	//���t���[���Ăԏ���
	void Step(VECTOR vPos);

	//�X�V�����f�[�^�𔽉f������
	void Update();

	//�f�o�b�N�J�������̕\��
	void Draw();
};