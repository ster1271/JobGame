#include "Bot.h"

const char BOT_FILE_PATH[] = { "" };
const float SPERE_R = 3.0f;

//�R���X�g���N�^
CBot::CBot()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
}

//�f�X�g���N�^
CBot::~CBot()
{
	//�n���h���̏�����
	iHndl = -1;

	//�ϐ��̏�����
	memset(&cPos, 0, sizeof(VECTOR));
	memset(&cSize, 0, sizeof(VECTOR));
	memset(&cRotate, 0, sizeof(VECTOR));
}

//������
void CBot::Init()
{
	//�n���h���̏�����
	iHndl = -1;

	cPos = VGet(0.0f, 10.0f, 50.0f);
	cSize = VGet(1.0f, 1.0f, 1.0f);
	cRotate = VGet(0.0f, 0.0f, 0.0f);
}

//�ǂݍ���
bool CBot::Load()
{
	iHndl = MV1LoadModel(BOT_FILE_PATH);

	if (iHndl != -1)
		return true;
	else
		return false;
}

//�`��
void CBot::Draw()
{
	//��������true�Ȃ烂�f����false�Ȃ狅��\��
	if (iHndl != -1)
	{
		MV1DrawModel(iHndl);
	}
	else
	{
		DrawSphere3D(cPos, SPERE_R, 32, GetColor(255, 0, 0), GetColor(255, 0, 0), TRUE);
	}
}

//�}�C�t���[���s������
void CBot::Step()
{
	//�X�V����
	Update();
}

