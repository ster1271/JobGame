#pragma once

#include "DxLib.h"
#include "math.h"
#include "../Input/Input.h"


//�I�u�W�F�N�g�N���X
class CItemBse
{
protected:
	VECTOR cPos;		//���W
	VECTOR cSize;		//�T�C�Y
	VECTOR cRotate;		//��]�l

	int Org_Hndl;
	int iHndl;			//�n���h��

	bool IsActive;		//�t���O

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CItemBse();
	~CItemBse();

	//������
	void Init();

	//�ǂݍ��݊֘A
	void Load(int Org_Hndl);

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

	//�ݒu����
	virtual void Set_Item(const VECTOR& vPos);
};
