#include "ShotBase.h"

//�`�揈��
void CShotBase::Draw()
{
	if (IsActive)
	{
		MV1DrawModel(iHndl);

		DrawFormatString(500, 0, GetColor(255, 0, 0), "X���W�F%f", cPos.x);
		DrawFormatString(500, 15, GetColor(255, 0, 0), "Y���W�F%f", cPos.y);
		DrawFormatString(500, 30, GetColor(255, 0, 0), "Z���W�F%f", cPos.z);
		/*DrawSphere3D(vPos, m_Radius, 16, GetColor(255, 255, 255), GetColor(255, 255, 255), FALSE);*/

	}
}

//���X�V
void CShotBase::UpDate()
{
	MV1SetPosition(iHndl, cPos);
	MV1SetScale(iHndl, cSize);
	MV1SetRotationXYZ(iHndl, cRotate);
}