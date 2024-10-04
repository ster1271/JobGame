#include "Check_Point.h"

const char POINT_PATH[] = { "data/Map/Point.x" };

#define MAX_NUM	(5)

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
	tmp = 0;
	tmp_Hndl = -1;
	
	memset(cPos, 0, sizeof(VECTOR));
	memset(cRotate, 0, sizeof(VECTOR));
	memset(cSize, 0, sizeof(VECTOR));

	for (int Index = 0; Index < MAX_NUM; Index++)
	{

		VECTOR vPos;
		vPos = VGet(GetRand(400.0f) - 200.0f, 5.0f, GetRand(600.0f) - 300.0f);
		Set_Point(Index,vPos);
	}
}

//���f���ǂݍ���
void CCheck_Point::Load()
{
	if (tmp_Hndl == -1)
	{
		tmp_Hndl = MV1LoadModel(POINT_PATH);
	}

	for (int Index = 0; Index < MAX_NUM; Index++)
	{
		//���f���̃R�s�[
		iHndl[Index] = MV1DuplicateModel(tmp_Hndl);
	}
}

//���X�V
void CCheck_Point::UpData()
{
	for (int tmp = 0; tmp < MAX_NUM; tmp++)
	{
		MV1SetPosition(iHndl[tmp], cPos[tmp]);		//���W�̍X�V
		MV1SetScale(iHndl[tmp], cSize[tmp]);			//�T�C�Y�̍X�V
		MV1SetRotationXYZ(iHndl[tmp], cRotate[tmp]);	//��]�l�̍X�V
	}
}


//�`��
void CCheck_Point::Draw()
{
	for (int Index = 0; Index < MAX_NUM; Index++)
	{
		if (!IsActive)
			return;

		MV1DrawModel(iHndl[Index]);
	}
}

//���t���[���s������
void CCheck_Point::Step()
{
	for (int Index = 0; Index < MAX_NUM; Index++)
	{
		if (!IsActive)
			return;

		UpData();
	}
}

//�㏈��
void CCheck_Point::Exit()
{
	memset(cPos, 0, sizeof(VECTOR));
	memset(cRotate, 0, sizeof(VECTOR));
	memset(cSize, 0, sizeof(VECTOR));

	for (int Index = 0; Index < MAX_NUM; Index++)
	{
		if (iHndl[Index] != -1)
		{
			MV1DeleteModel(iHndl[Index]);
			iHndl[Index] = -1;
		}
	}
	if (tmp_Hndl != -1)
	{
		MV1DeleteModel(tmp_Hndl);
		tmp_Hndl = -1;
	}
}

//�ݒu����
void CCheck_Point::Set_Point(int Index, VECTOR vPos)
{
	cPos[Index] = vPos;
	cSize[Index] = VGet(0.1f, 0.1f, 0.1f);
	IsActive[Index] = true;

	Point_info_List.push_back(cPos[Index]);
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

