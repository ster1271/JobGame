#pragma once
#include <DxLib.h>

//�I�u�W�F�N�g�N���X
class CObject
{

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CObject();
	~CObject();

	//������
	void Init();

	//�ǂݍ��݊֘A
	void Load(const char FILEPATH[]);

	//���t���[���s������()
	virtual void Step() = 0;

	//�X�V����
	void Updata();

	//�㏈��
	void Exit();

protected:
	VECTOR cPos;		//���W
	VECTOR cSize;		//�T�C�Y
	VECTOR cRotate;		//��]�l

	int iHndl;			//�n���h��
};
