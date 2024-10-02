#include "Check_Point.h"

const char POINT_PATH[] = { "data/Map/Point.x" };


//�R���X�g���N�^
Check_Point::Check_Point()
{
}

//�f�X�g���N�^
v::~CRoute_Point()
{
}

//������
void CRoute_Point::Init()
{
	VECTOR vPos = VGet(GetRand(400.0f) - 200.0f, 5.0f, GetRand(600.0f) - 300.0f);
	Set_Point(vPos);
}

//���f���ǂݍ���
void CRoute_Point::Load(int Hndl)
{
	iHndl = MV1DuplicateModel(Hndl);
}

//�ݒu����
void CRoute_Point::Set_Point(const VECTOR vPos)
{
	//���łɐ�������Ă���
	if (IsActive) return;

	cPos = vPos;
	cRotate = VGet(0.0, 0.0f, 0.0f);
	cSize = VGet(0.1f, 0.1f, 0.1f);

	IsActive = true;
}

