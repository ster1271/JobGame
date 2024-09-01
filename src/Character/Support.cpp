#include "Support.h"

const char SUPPORT_PATH[] = { "" };

const float SPERE_R = 3.0f;
#define MOVESPEED	(0.3f)


//�R���X�g���N�^�E�f�X�g���N�^
CSupport::CSupport()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
}

CSupport::~CSupport()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
}

//������
void CSupport::Init()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	cPos = VGet(0.0f, 0.0f, 0.0f);
	cSize = VGet(1.0f, 1.0f, 1.0f);
	cRotate = VGet(0.0f, 0.0f, 0.0f);
}

//�f�[�^�ǂݍ���
void CSupport::Load()
{
	iHndl = MV1LoadModel(SUPPORT_PATH);
}

//���t���[���s������
void CSupport::Step()
{
	if (CInput::IsKeyKeep(KEY_INPUT_W))
	{
		cPos.z -= MOVESPEED;
	}
	if (CInput::IsKeyKeep(KEY_INPUT_S))
	{
		cPos.z += MOVESPEED;
	}
	if (CInput::IsKeyKeep(KEY_INPUT_A))
	{
		cPos.x += MOVESPEED;
	}
	if (CInput::IsKeyKeep(KEY_INPUT_D))
	{
		cPos.x -= MOVESPEED;
	}

}

//�X�V����
void CSupport::Update()
{
	MV1SetPosition(iHndl, cPos);		//���W�̍X�V
	MV1SetScale(iHndl, cSize);			//�T�C�Y�̍X�V
	MV1SetRotationXYZ(iHndl, cRotate);	//��]�l�̍X�V
}

//�`��
void CSupport::Draw()
{
	MV1DrawModel(iHndl);

	DrawFormatString(0, 100, GetColor(255, 255, 255), "�T�|�[�gX���W:%f", cPos.x);
	DrawFormatString(0, 115, GetColor(255, 255, 255), "�T�|�[�gY���W:%f", cPos.y);
	DrawFormatString(0, 130, GetColor(255, 255, 255), "�T�|�[�gZ���W:%f", cPos.z);

}

//�I������
void CSupport::Exit()
{
	//�n���h���̍폜
	if (iHndl != -1)
	{
		MV1DeleteModel(iHndl);
		iHndl = -1;
	}

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
}
