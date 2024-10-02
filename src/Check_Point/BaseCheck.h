#pragma once
#include <DxLib.h>

class CBase_Check
{
protected:
	VECTOR cPos;		//���W
	VECTOR cSize;		//�T�C�Y
	VECTOR cRotate;		//��]�l

	int iHndl;			//�n���h��

	bool IsActive;		//�t���O
public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CBase_Check();
	~CBase_Check();

	//������
	void Init();

	//�ǂݍ���
	void Load();

	//�`��
	virtual void Draw() = 0;

	//���t���[���s������
	virtual void Step() = 0;

	//���X�V
	void UpData();

	//�㏈��
	void Exit();
};
