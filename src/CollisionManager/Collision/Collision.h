#pragma once
#include "DxLib.h"

//�R���W�����N���X
class CCollision
{
public:
	//IsHitRect�̃v���g�^�C�v�錾
	static bool IsHitRect(int myPos_X, int myPos_Y, int side, int Vertical,
		int pos_1X, int pos_1Y, int Rectside, int RectVertical);

	//IsHitCircle�̃v���g�^�C�v�錾
	static bool IsHitCircle(int PosX, int PosY, int circle1, int aPosX, int aPosY, int circle2);

	// �{�b�N�X���m�̓����蔻��
	static bool CheckHitBoxToBox(VECTOR MyPos, VECTOR MySize, VECTOR Pos, VECTOR Size);

	// �����m�̓����蔻��
	static bool CheckHitSphereToSphere(VECTOR APos, float ASpereR, VECTOR BPos, float BSpereR);
};

