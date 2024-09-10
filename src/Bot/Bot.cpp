#include "Bot.h"

const char BOT_FILE_PATH[] = { "" };
const float SPERE_R = 5.0f;

#define DEG_TO_RAD(a)	((a) * DX_PI_F / 180.0f)	//���W�A���p�ɕϊ����鎮

//�R���X�g���N�^
CBot::CBot()
{
	State_Id = STATE_NUM;
}

//�f�X�g���N�^
CBot::~CBot()
{
	State_Id = STATE_NUM;
}

//������
void CBot::Init()
{
	CObject::Init();
	cPos = VGet(0.0f, 10.0f, 100.0f);
	cSize = VGet(1.0f, 1.0f, 1.0f);
	cRotate = VGet(0.0f, 0.0f, 0.0f);

	State_Id = STATE_NUM;
}

//�ǂݍ���
bool CBot::Load()
{
	iHndl = MV1LoadModel(BOT_FILE_PATH);
	State_Id = STATE_STOP;

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
	DrawFormatString(0, 195, GetColor(0, 0, 0), "�O��:%f", tmp_dir);
	DrawFormatString(0, 210, GetColor(0, 0, 0), "����:%f", tmp_Range);

}

//�}�C�t���[���s������
void CBot::Step(VECTOR Set_Point)
{
	

	switch (State_Id)
	{
	case CBot::STATE_STOP:

		//�e�X�g�p����
		if (CInput::IsKeyPush(KEY_INPUT_1))
		{
			//Id��ύX����
			State_Id = STATE_MOVE;
		}
		break;

	case CBot::STATE_MOVE:

		Move_Bot(Set_Point);	//�ǔ�����
		break;

	default:
		break;
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
	Vtmp.y = 0.0f;
	Vtmp.z = Set_Point.z - cPos.z;

	//�i�s�����̂ǂ��瑤�ɂ���̂��𒲂ׂ�
	float Dir = 0.0f;

	VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);	//�{�b�g�̈ړ��x�N�g��
	vSpd.x = sinf(cRotate.y) * -1.0f;
	vSpd.y = 0.0f;
	vSpd.z = cosf(cRotate.y) * -1.0f;
	
	//�O�όv�Z
	Dir = Vtmp.x * vSpd.z - vSpd.x * Vtmp.z;
	//�m�F�p
	tmp_dir = Dir;

	//��]����p�x�����߂�
	if (Dir >= 0.0f)
	{
		cRotate.y += 0.05f;
	}
	else if (Dir < 0.0f)
	{
		cRotate.y -= 0.05f;
	}

	//���W�ɑ��x�����Z����
	cPos.x += sinf(cRotate.y) * -0.3f;
	cPos.z += cosf(cRotate.y) * -0.3f;

	//�v���C���[�Ƃ̋������v�Z
	float Range = (Set_Point.x - cPos.x) * (Set_Point.x - cPos.x) + (Set_Point.z - cPos.z) * (Set_Point.z - cPos.z);
	Range = sqrt(Range);
	//�m�F�p
	tmp_Range = Range;

	//���������l�ɒB������Id��ύX����
	if (Range < 1.0f)
	{
		State_Id = STATE_STOP;
	}
}

