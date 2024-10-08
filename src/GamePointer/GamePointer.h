#pragma once
#include "DxLib.h"
#include "../Draw3D/Draw3D.h"
#include "math.h"
#include "../Input/Input.h"

class CGame_Pointer
{
private:
	VECTOR cPos;
	VECTOR cBoxSize;

	int	iHndl;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CGame_Pointer();
	~CGame_Pointer();

	//������
	void Init();
	
	//�ǂݍ���
	void Load();

	//���t���[���s������
	void Step();

	//�`��
	void Draw();

	//�㏈��
	void Exit();

	//���W�擾
	VECTOR GetPos() { return cPos; }


};