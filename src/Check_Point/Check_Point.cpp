#include "Check_Point.h"

//�R���X�g���N�^
CCheck_Point::CCheck_Point()
{
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
}

//�ݒu����
void CCheck_Point::Set_Point(const VECTOR vPos)
{
	cPos = vPos;
	cSize= VGet(0.1f, 0.1f, 0.1f);
	IsActive = true;
}


//�t�@�C���ǂݍ���
void CCheck_Point::LoadFile()
{

}

//�t�@�C����������
void CCheck_Point::WriteFile(const VECTOR vPos)
{
	
}





