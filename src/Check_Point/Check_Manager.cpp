#include "Check_Manager.h"

const char POINT_PATH[] = { "data/Map/Point.x" };


//�R���X�g���N�^
CChecck_Manager::CChecck_Manager()
{
	memset(&WorldPos, 0, sizeof(VECTOR));
	memset(&fp, 0, sizeof(FILE));
	MouseX = MouseY = 0;;

	check_Hndl = -1;
	check_id = ID_NUM;
}

//�f�X�g���N�^
CChecck_Manager::~CChecck_Manager() {};

//������
void CChecck_Manager::Init()
{
	memset(&WorldPos, 0, sizeof(VECTOR));
	MouseX = MouseY = 0;;
	check_Hndl = -1;

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

//�f�o�b�N���̏���
void CChecck_Manager::DebugStep()
{
	//�}�E�X�̍��W�擾
	GetMousePoint(&MouseX, &MouseY);

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
		//�}�E�X�̃X�N���[�����W�����[���h���W�ɕϊ�(�}�E�X��Y���W��3D��Z���W�ƒu��������)
		WorldPos = ConvScreenPosToWorldPos(VGet(MouseX, 0.0f, MouseY));
		//Y���W������̍����ɂ���
		WorldPos.y = 5.0f;

		//���X�g�ɒǉ�����
		Point_info_List.push_back(WorldPos);


		fopen_s(&fp, "Data/ObjectFile/Object_file.txt", "a");

		if (fp != nullptr)
		{
			fprintf(fp, "X���W = %.1f, Y���W = %.1f, Z���W = %.1f \n", WorldPos.x, WorldPos.y, WorldPos.z);

			fclose(fp);
		}
	}
}

//�f�o�b�N���̕`��
void CChecck_Manager::DebugDraw()
{
	DrawFormatString(0, 30, GetColor(255, 0, 0), "�}�E�XX���W�F%d", MouseX);
	DrawFormatString(0, 45, GetColor(255, 0, 0), "�}�E�XY���W�F%d", MouseX);


	DrawFormatString(0, 60, GetColor(255, 0, 0), "�}�E�X���[���hX���W�F%f", WorldPos.x);
	DrawFormatString(0, 75, GetColor(255, 0, 0), "�}�E�X���[���hZ���W�F%f", WorldPos.z);



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
}
