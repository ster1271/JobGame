#pragma once
#include <DxLib.h>

class CShotBase
{
protected:
	VECTOR cPos;			//���W
	VECTOR cRotate;			//��]�l
	VECTOR cSize;			//�g�k�l
	VECTOR cSpeed;			//�ړ����x
	float Yspeed;			//Y�X�s�[�h

	int iHndl;				//���f���̃n���h��
	float Radius;			//���f���̔��a
	bool IsActive;			//�����t���O

public:

	//�`�揈��
	void Draw();

	//���X�V
	void UpDate();

	//���W�擾
	VECTOR GetPos() { return cPos; }

	//�t���O��񏊓�
	bool GetIsActive() { return IsActive; }

};
