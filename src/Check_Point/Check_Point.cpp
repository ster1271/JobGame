#include "Check_Point.h"

const char POINT_PATH[] = { "data/Map/Point.x" };


//�R���X�g���N�^
CCheck_Point::CCheck_Point()
{
	tmp_Hndl = -1;
}

//�f�X�g���N�^
CCheck_Point::~CCheck_Point()
{
	Exit();
}

//������
void CCheck_Point::Init()
{
	CBase_Check::Init();
	tmp_Hndl = -1;
	VECTOR vPos;
	vPos = VGet(GetRand(400.0f) - 200.0f, 5.0f, GetRand(600.0f) - 300.0f);
	Set_Point(vPos);
}

//���f���ǂݍ���
void CCheck_Point::Load()
{
	if (tmp_Hndl == -1)
	{
		tmp_Hndl = MV1LoadModel(POINT_PATH);
	}

	//���f���̃R�s�[
	iHndl = MV1DuplicateModel(tmp_Hndl);
}

//�`��
void CCheck_Point::Draw()
{
	if (!IsActive)
		return;

	MV1DrawModel(iHndl);
}

//���t���[���s������
void CCheck_Point::Step()
{
	if (!IsActive)
		return;

	CBase_Check::UpData();
}

//�㏈��
void CCheck_Point::Exit()
{
	if (iHndl != -1)
	{
		MV1DeleteModel(iHndl);
		iHndl = -1;
	}

	if (tmp_Hndl != -1)
	{
		MV1DeleteModel(tmp_Hndl);
		tmp_Hndl = -1;
	}
}

//�ݒu����
void CCheck_Point::Set_Point(VECTOR vPos)
{
	cPos = vPos;
	cSize = VGet(0.1f, 0.1f, 0.1f);
	IsActive = true;
}

