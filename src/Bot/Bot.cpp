#include "Bot.h"

const char BOT_FILE_PATH[] = { "" };
const float SPERE_R = 3.0f;

#define DEG_TO_RAD(a)	((a) * DX_PI_F / 180.0f)	//���W�A���p�ɕϊ����鎮

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
	cPos = VGet(0.0f, 10.0f, 100.0f);
	cSize = VGet(1.0f, 1.0f, 1.0f);
	cRotate = VGet(0.0f, 0.0f, 0.0f);

	IsMove = false;
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

	DrawFormatString(0, 150, GetColor(0, 0, 0), "�{�b�gX���W:%f", cPos.x);
	DrawFormatString(0, 165, GetColor(0, 0, 0), "�{�b�gY���W:%f", cPos.y);
	DrawFormatString(0, 180, GetColor(0, 0, 0), "�{�b�gZ���W:%f", cPos.z);
	DrawFormatString(0, 195, GetColor(0, 0, 0), "����:%f", tmp_dir);
}

//�}�C�t���[���s������
void CBot::Step(VECTOR Set_Point)
{
	if (CInput::IsKeyPush(KEY_INPUT_1))
	{
		IsMove = true;
	}


	if (IsMove)
	{
		//�ǔ�����
		Move_Bot(Set_Point);
	}
	
	//�X�V����
	Update();
}


//�w��̏ꏊ�ɓ�������
void CBot::Move_Bot(VECTOR Set_Point)
{
	//�{�b�g����w��̒n�_�֍s���x�N�g�����v�Z
	VECTOR Vtmp;
	Vtmp.x = Set_Point.x - cPos.x;
	Vtmp.z = 0.0f;
	Vtmp.y = Set_Point.z - cPos.z;

	//�i�s�����̂ǂ��瑤�ɂ���̂��𒲂ׂ�
	float Dir = 0.0f;

	VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);	//�{�b�g�̈ړ����x
	vSpd.x = cosf(DEG_TO_RAD(cRotate.x));
	vSpd.y = sinf(DEG_TO_RAD(cRotate.x));
	vSpd.z = 0.0f;

	Dir = (Vtmp.x * vSpd.y) - (vSpd.x * Vtmp.y);
	//�m�F�p
	tmp_dir = Dir;

	//��]����p�x�����߂�
	if (Dir > 0.0f)
	{
		cRotate.x -= 1.0f;
	}
	else if (Dir < 0.0f)
	{
		cRotate.x += 1.0f;
	}
	else
	{
		IsMove = false;
	}

	vSpd.x = cosf(DEG_TO_RAD(cRotate.x));
	vSpd.y = sinf(DEG_TO_RAD(cRotate.x));

	//���W�ɑ��x�����Z����
	cPos.x += vSpd.x * 0.5f;
	cPos.z += vSpd.y * 0.5f;

}

