#include "Bot.h"

const char BOT_FILE_PATH[] = { "" };
const float SPERE_R = 3.0f;

//�R���X�g���N�^
CBot::CBot()
{
}

//�f�X�g���N�^
CBot::~CBot()
{
}

//������
void CBot::Init()
{
	CObject::Init();
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


//�w��̏ꏊ�ɓ�������
void CBot::Move_Bot()
{

}

