#pragma once
#include "../Common.h"

class  CDraw3D
{
public:

	//3D�̃{�b�N�X�\���֐�
	//��1�����F���W(���S�łȂ��Ă��悢)
	//��2�����F�\���������{�b�N�X�̃T�C�Y
	//��3�����F�F�̎w��(�f�t�H���g�͐ԂŐݒ�)
	static void DrawBox3D(VECTOR Pos, VECTOR Size, unsigned int Color = GetColor(255, 0, 0));
	
};


