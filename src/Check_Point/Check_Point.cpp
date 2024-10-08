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
void CCheck_Point::Init(FILE* fp)
{
	CCheck_Base::Init();

	tmp = 0;
	tmp_Hndl = -1;

	VECTOR vPos = VGet(0.0f, 0.0f, 0.0f);
	
	//�ǂݍ���
	//�t�@�C�����J��
	fopen_s(&fp, "Data/ObjectFile/Object_file.txt", "r");

	if (fp != nullptr)
	{
		while (fscanf_s(fp, "%f, %f, %f", &vPos.x, &vPos.y, &vPos.z) != EOF)
		{
			Set_Point(vPos);
		}
	}

	fclose(fp);
	
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





