#pragma once
#include "DxLib.h"

class  CDraw3D
{
public:

	//3D�̃{�b�N�X�\���֐�
	//��1�����F���W(���S�łȂ��Ă��悢)
	//��2�����F�\���������{�b�N�X�̃T�C�Y
	//��3�����F���S���W�łȂ����̃Y��(���łɒ��S�̎��͏����Ȃ��Ă悢)
	static void DrawBox3D(VECTOR Pos, VECTOR Size, VECTOR Gap = { 0.0f, 0.0f, 0.0f });
	
};


