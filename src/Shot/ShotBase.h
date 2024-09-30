#pragma once
#include <math.h>
#include <DxLib.h>

class CShotBase
{
protected:
	VECTOR cPos;			//���W
	VECTOR cRotate;			//��]�l
	VECTOR cSize;			//�g�k�l
	VECTOR cSpeed;			//�ړ����x

	int iHndl;				//���f���̃n���h��
	float Radius;			//���f���̔��a
	bool IsActive;			//�����t���O

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CShotBase();
	~CShotBase();

	//�`�揈��
	virtual void Draw();

	//���X�V
	void UpDate();

	//���N�G�X�g
	bool RequestShot(const VECTOR& vPos, const VECTOR& vSpeed);

	//�㏈��
	void Exit();

	//���W�擾
	VECTOR GetPos() { return cPos; }

	//�t���O��񏊓�
	bool GetIsActive() { return IsActive; }

	//�����蔻��̏���
	void HitCalc()
	{
		//����������t���O������
		IsActive = false;
	}

};
