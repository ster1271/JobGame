#include "Check_Manager.h"

const char POINT_PATH[] = { "data/Map/Point.x" };


//�R���X�g���N�^
CChecck_Manager::CChecck_Manager()
{
	check_Hndl = -1;
}

//�f�X�g���N�^
CChecck_Manager::~CChecck_Manager() {};

//������
void CChecck_Manager::Init()
{
	for (int Index = 0; Index < MAX_NUM; Index++)
	{
		cCheck_Point[Index].Init();
	}
}

//�f�[�^�ǂݍ���
void CChecck_Manager::Load()
{
	check_Hndl = MV1LoadModel(POINT_PATH);

	for (int Index = 0; Index < MAX_NUM; Index++)
	{
		cCheck_Point[Index].Load(check_Hndl);
	}
}

//�㏈��
void CChecck_Manager::Exit()
{
	for (int Index = 0; Index < MAX_NUM; Index++)
	{
		cCheck_Point[Index].Exit();
	}
}

//���X�V
void CChecck_Manager::Updata()
{
	for (int Index = 0; Index < MAX_NUM; Index++)
	{
		cCheck_Point[Index].Updata();
	}
}

//�`��
void CChecck_Manager::Draw()
{
	for (int Index = 0; Index < MAX_NUM; Index++)
	{
		cCheck_Point[Index].Draw();
	}
}

void CChecck_Manager::Step()
{
	for (int Index = 0; Index < MAX_NUM; Index++)
	{
		cCheck_Point[Index].Step();
	}

	Updata();
}