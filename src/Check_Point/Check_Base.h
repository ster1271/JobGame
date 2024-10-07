#pragma once
#include <DxLib.h>
#include <iostream>
#include <vector>
#include <math.h>

//�`�F�b�N�|�C���g�x�[�X�N���X
class CCheck_Base
{
protected:
	VECTOR cPos;		//���W
	VECTOR cSize;		//�T�C�Y
	VECTOR cRotate;		//��]�l

	int iHndl;			//�n���h��

	bool IsActive;		//�t���O

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CCheck_Base();
	~CCheck_Base();

	//������
	void Init();

	//�f�[�^�ǂݍ���
	void Load(int Hndl);

	//�㏈��
	void Exit();

	//���X�V
	void Updata();

	//�`��
	virtual void Draw();

	virtual void Step();

};

