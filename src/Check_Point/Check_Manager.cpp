#include "Check_Manager.h"

const char POINT_PATH[] = { "data/Map/Point.x" };


//�R���X�g���N�^
CChecck_Manager::CChecck_Manager()
{
	memset(&MousePos, 0, sizeof(VECTOR));
	MouseX = MouseY = 0;;

	check_Hndl = -1;
	check_id = ID_NUM;
}

//�f�X�g���N�^
CChecck_Manager::~CChecck_Manager() {};

//������
void CChecck_Manager::Init()
{
	MousePos = VGet(0.0f, 0.0f, 0.0f);
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

	if (CInput::IsKeyPush(KEY_INPUT_1))
	{
		check_id = ID_CHECK_POINT;
	}
	else if (CInput::IsKeyPush(KEY_INPUT_2))
	{
		check_id = ID_ENEMY_SPAWN;
	}


	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		//�}�E�X�̃X�N���[�����W�����[���h���W�ɕϊ�
		//MousePos = VGet(MouseX, MouseY, 0.0f);
		//MousePos = ConvScreenPosToWorldPos(MousePos);
	}
}

//�f�o�b�N���̕`��
void CChecck_Manager::DebugDraw()
{
	DrawFormatString(0, 60, GetColor(255, 255, 255), "�}�E�XX���W�F%d", MousePos.x);
	DrawFormatString(0, 75, GetColor(255, 255, 255), "�}�E�XY���W�F%d", MousePos.y);
	DrawFormatString(0, 90, GetColor(255, 255, 255), "�}�E�XY���W�F%d", MousePos.x);

	switch (check_id)
	{
	case ID_CHECK_POINT:
		DrawFormatString(0, 30, GetColor(255, 0, 0), "�`�F�b�N�|�C���g����[");
		break;
	case ID_ENEMY_SPAWN:
		DrawFormatString(0, 30, GetColor(255, 0, 0), "�G�����|�C���g����[");
		break;
	case ID_NUM:
		DrawFormatString(0, 30, GetColor(255, 0, 0), "���������ĂȂ���");
		break;
	default:
		break;
	}
}
