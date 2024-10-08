#include "Check_Manager.h"

const char POINT_PATH[] = { "data/Map/Point.x" };


//�R���X�g���N�^
CChecck_Manager::CChecck_Manager()
{
	memset(&fp, 0, sizeof(FILE));

	check_Hndl = -1;
	check_id = ID_NUM;
}

//�f�X�g���N�^
CChecck_Manager::~CChecck_Manager() {};

//������
void CChecck_Manager::Init()
{
	check_Hndl = -1;

	for (int Index = 0; Index < Point_info_List.size(); Index++)
	{
		cCheck_Point[Index].Init(fp);
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

//�f�o�b�N���̏���
void CChecck_Manager::DebugStep(VECTOR vPos)
{

	//�I�u�W�F�N�g�̕ύX����
	if (CInput::IsKeyPush(KEY_INPUT_1))
	{
		check_id = ID_CHECK_POINT;
	}
	else if (CInput::IsKeyPush(KEY_INPUT_2))
	{
		check_id = ID_ENEMY_SPAWN;
	}

	//�I�u�W�F�N�g�̐ݒu����
	if ((CInput::IsKeyPush(KEY_INPUT_P)))
	{

		//���X�g�ɒǉ�����
		Point_info_List.push_back(vPos);


		fopen_s(&fp, "Data/ObjectFile/Object_file.txt", "a");

		if (fp != nullptr)
		{
			fprintf(fp, "%.1f, %.1f, %.1f \n", vPos.x, vPos.y, vPos.z);

			fclose(fp);
		}
	}
}

//�f�o�b�N���̕`��
void CChecck_Manager::DebugDraw()
{
	switch (check_id)
	{
	case ID_CHECK_POINT:
		DrawFormatString(800, 30, GetColor(255, 0, 0), "�`�F�b�N�|�C���g����[");
		break;
	case ID_ENEMY_SPAWN:
		DrawFormatString(800, 30, GetColor(255, 0, 0), "�G�����|�C���g����[");
		break;
	case ID_NUM:
		DrawFormatString(800, 30, GetColor(255, 0, 0), "���������ĂȂ���");
		break;
	default:
		break;
	}

	DrawFormatString(800, 50, GetColor(255, 0, 0), "�ݒu���̐�:%d", Point_info_List.size());

}