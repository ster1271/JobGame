#include "Collision.h"

//IsHitRect(2D)の定義
bool CCollision::IsHitRect(int myPos_X, int myPos_Y, int side, int Vertical,
	int pos_1X, int pos_1Y, int Rectside, int RectVertical)
{
	if (myPos_X < pos_1X + Rectside &&
		myPos_X + side > pos_1X &&
		myPos_Y + Vertical > pos_1Y &&
		myPos_Y < pos_1Y + RectVertical)
		return true;
	else
		return false;
}


//IsHitCircle(2D)の定義
bool CCollision::IsHitCircle(int PosX, int PosY, int circle1, int aPosX, int aPosY, int circle2)
{
	if ((circle1 + circle2) * (circle1 + circle2) >
		(aPosX - PosX) * (aPosX - PosX) + (aPosY - PosY) * (aPosY - PosY))
	{
		return true;
	}
	else
		return false;
}

// ボックス同士の当たり判定(3D)
bool CCollision::CheckHitBoxToBox(VECTOR APos, VECTOR ASize, VECTOR BPos, VECTOR BSize)
{
	if (APos.x < BPos.x + BSize.x &&
		APos.x + ASize.x > BPos.x &&
		APos.y + ASize.y > BPos.y &&
		APos.y < BPos.y + BSize.y &&
		APos.x < BPos.x + BSize.x &&
		APos.x + ASize.x > BPos.x &&
		APos.z + ASize.z > BPos.z &&
		APos.z < BPos.z + BSize.z)
	{
		return true;
	}
	else
		return false;
}

// 球同士の当たり判定(2D)
bool CCollision::CheckHitSphereToSphere(VECTOR APos, float ASpereR, VECTOR BPos, float BSpereR)
{
	VECTOR tempPos;

	tempPos.x = APos.x - BPos.x;
	tempPos.y = APos.y - BPos.y;
	tempPos.z = APos.z - BPos.z;

	float tempR = ASpereR + BSpereR;

	if ((tempR * tempR) > (tempPos.x * tempPos.x) + (tempPos.y * tempPos.y) + (tempPos.z * tempPos.z))
	{
		return true;
	}
	else
		return false;

}
