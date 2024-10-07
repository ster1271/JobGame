#include "Check_Point.h"

//�R���X�g���N�^
CCheck_Point::CCheck_Point()
{
	memset(&Point_info_List, 0, sizeof(VECTOR));
	tmp_Hndl = -1;
	tmp = -1;
}

//�f�X�g���N�^
CCheck_Point::~CCheck_Point()
{
	Exit();
}

//������
void CCheck_Point::Init()
{
	CCheck_Base::Init();

	tmp = 0;
	tmp_Hndl = -1;
	
	VECTOR vPos;
	vPos = VGet(GetRand(400.0f) - 200.0f, 5.0f, GetRand(600.0f) - 300.0f);
	Set_Point(vPos);
}

//���f���ǂݍ���
void CCheck_Point::Load(int Hndl)
{
	//���f���̃R�s�[
	iHndl = MV1DuplicateModel(Hndl);
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

}

//�㏈��
void CCheck_Point::Exit()
{
	CCheck_Base::Exit();

	if (tmp_Hndl != -1)
	{
		MV1DeleteModel(tmp_Hndl);
		tmp_Hndl = -1;
	}
}

//�ݒu����
void CCheck_Point::Set_Point(const VECTOR vPos)
{
	cPos = vPos;
	cSize= VGet(0.1f, 0.1f, 0.1f);
	IsActive = true;

	Point_info_List.push_back(cPos);
}

/*
//�t�@�C���ǂݍ���
void CCheck_Point::LoadFile()
{
	FILE* fp;

	//�t�@�C�����J��
	fopen_s(&fp, "data/file/CheckPoint.txt", "r");

	if (fp != nullptr)
	{
		//1�s�ڂ�ǂݍ���
		fscanf_s(fp, "%f %f %f", &cPos[0].x, &cPos[0].y, &cPos[0].z);
	}

	//�t�@�C�������
	fclose(fp);
}
*/

