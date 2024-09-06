#pragma once
#include "DxLib.h"
#include "math.h"
#include "../Input/Input.h"

//�I�u�W�F�N�g�N���X
class CObject
{
protected:
	VECTOR cPos;		//���W
	VECTOR cSize;		//�T�C�Y
	VECTOR cRotate;		//��]�l
	

	int iHndl;			//�n���h��

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CObject();
	~CObject();

	//������
	void Init();

	//�ǂݍ��݊֘A
	bool Load(const char FILEPATH[]);

	//�`��
	void Draw();

	//���t���[���s������
	virtual void Step();

	//�X�V����
	void Update();

	//�㏈��
	void Exit();

	//���W�擾
	VECTOR GetPos() { return cPos; }

	//�T�C�Y�擾
	VECTOR GetSize() { return cSize; }

	//��]�n�擾
	VECTOR GetRotate() { return cRotate; }
};
