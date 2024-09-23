#include "ShotBase.h"

//描画処理
void CShotBase::Draw()
{
	if (IsActive)
	{
		MV1DrawModel(iHndl);

		DrawFormatString(500, 0, GetColor(255, 0, 0), "X座標：%f", cPos.x);
		DrawFormatString(500, 15, GetColor(255, 0, 0), "Y座標：%f", cPos.y);
		DrawFormatString(500, 30, GetColor(255, 0, 0), "Z座標：%f", cPos.z);
		/*DrawSphere3D(vPos, m_Radius, 16, GetColor(255, 255, 255), GetColor(255, 255, 255), FALSE);*/

	}
}

//情報更新
void CShotBase::UpDate()
{
	MV1SetPosition(iHndl, cPos);
	MV1SetScale(iHndl, cSize);
	MV1SetRotationXYZ(iHndl, cRotate);
}