#pragma once
#include <DxLib.h>


class CCharacter
{
public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CCharacter();
	~CCharacter();

	//������
	void Init();

	//�ǂݍ��݊֘A
	virtual void Load() = 0;

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
