#pragma once
#include <DxLib.h>

//�I�u�W�F�N�g�N���X
class CObject
{

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CObject();
	~CObject();

protected:
	VECTOR cPos;		//���W
	int cHp;			//HP
	float cGravity;		//�d��
	float cYspeed;		//Y�X�s�[�h

	VECTOR cRotate;		//��]�l

	int iHndl;			//�n���h��
};
