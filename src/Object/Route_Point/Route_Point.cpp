#include "Route_Point.h"

const char POINT_PATH[] = { "data/Map/Point.x" };


//�R���X�g���N�^
CRoute_Point::CRoute_Point()
{
}

//�f�X�g���N�^
CRoute_Point::~CRoute_Point()
{
}

//������
void CRoute_Point::Init()
{

}

//���f���ǂݍ���
void CRoute_Point::Load()
{
	if (Org_Hndl == -1)
	{
		Org_Hndl = MV1LoadModel(POINT_PATH);
	}
	iHndl = MV1DuplicateModel(Org_Hndl);
}

//�ݒu����
void CRoute_Point::Set_Point(const VECTOR& vPos)
{
	//���łɐ�������Ă���
	if (IsActive) return;

	cPos = vPos;
	cRotate = VGet(0.0, 0.0f, 0.0f);
	cSize = VGet(1.0f, 1.0f, 1.0f);

	IsActive = true;
}

