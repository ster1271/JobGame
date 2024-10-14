#include "Bot.h"

const char BOT_FILE_PATH[] = { "" };
const float MOVE_SPEED = 5.0f;
const float SPERE_R = 5.0f;

#define DEG_TO_RAD(a)	((a) * DX_PI_F / 180.0f)	//���W�A���p�ɕϊ����鎮

//�R���X�g���N�^
CBot::CBot()
{
	tmp_dir = 0;
	tmp_Range = 0;
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

	tmp = 0;

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
void CBot::Step(vector<VECTOR> List)
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

		Move_Bot(List);	//�ǔ�����
		break;

	default:
		break;
	}
	
	//�X�V����
	Update();
}


//�w��̏ꏊ�ɓ�������
void CBot::Move_Bot(vector<VECTOR> List)
{
	//�{�b�g����w��̒n�_�֍s���x�N�g�����v�Z
	VECTOR Vtmp;
	Vtmp.x = List[tmp].x - cPos.x;
	Vtmp.y = 0.0f;
	Vtmp.z = List[tmp].z - cPos.z;

	//�i�s�����̂ǂ��瑤�ɂ���̂��𒲂ׂ�
	float Dir = 0.0f;

	VECTOR vSpd = VGet(0.0f, 0.0f, 0.0f);	//�{�b�g�̈ړ��x�N�g��
	vSpd.x = sinf(cRotate.y) * -MOVE_SPEED;
	vSpd.y = 0.0f;
	vSpd.z = cosf(cRotate.y) * -MOVE_SPEED;

	//�O�όv�Z
	Dir = Vtmp.x * vSpd.z - vSpd.x * Vtmp.z;
	//�m�F�p
	tmp_dir = Dir;

	//��]����p�x�����߂�
	if (Dir >= 0.0f)
	{
		cRotate.y += 0.01f;
	}
	else if (Dir < 0.0f)
	{
		cRotate.y -= 0.01f;
	}

	//���W�ɑ��x�����Z����
	cPos.x += sinf(cRotate.y) * -0.2f;
	cPos.z += cosf(cRotate.y) * -0.2f;

	//�v���C���[�Ƃ̋������v�Z
	float Range = (List[tmp].x - cPos.x) * (List[tmp].x - cPos.x) + (List[tmp].z - cPos.z) * (List[tmp].z - cPos.z);
	Range = sqrt(Range);
	//�m�F�p
	tmp_Range = Range;

	//���������l�ɒB������Id��ύX����
	if (Range < 0.1f)
	{
		tmp++;
		
		//������x�v�Z���Ȃ���
		Vtmp.x = List[tmp].x - cPos.x;
		Vtmp.y = 0.0f;
		Vtmp.z = List[tmp].z - cPos.z;

		vSpd.x = sinf(cRotate.y) * -MOVE_SPEED;
		vSpd.y = 0.0f;
		vSpd.z = cosf(cRotate.y) * -MOVE_SPEED;

		//�O�όv�Z
		Dir = Vtmp.x * vSpd.z - vSpd.x * Vtmp.z;

		//�A�[�N�^���W�F���g�Ŋp�x���o��
		//float NextRot = atan2

		if (Dir >= 0.0f)
		{
			//�v���X������
		}
		else
		{
			//�}�C�i�X������

		}

		if (tmp == List.size())
		{
			State_Id = STATE_STOP;
			tmp = 0;
		}
	}
}

//�o�H�T��
void CBot::Route_Search(VECTOR GoalPos)
{
	//�����̏��������ɏ�(��),��(��O),�E,��,�E��,�E��,����,����

	Search_info.Distance += 50.0f;

	//�X�^�[�g����̋��������߂�
	Search_info.Range_From_Start[0] = 1.0f;
	Search_info.Range_From_Start[1] = 1.0f;
	Search_info.Range_From_Start[2] = 1.0f;
	Search_info.Range_From_Start[3] = 1.0f;
	Search_info.Range_From_Start[4] = 1.0f;
	Search_info.Range_From_Start[5] = 1.0f;
	Search_info.Range_From_Start[6] = 1.0f;
	Search_info.Range_From_Start[7] = 1.0f;

	//�������n�_����S�[���܂ł̒������������߂�
	/*for (int Index = 0; Index < 8; Index++)
	{

	}*/
	Search_info.Renge_To_Goal[0] = hypot((GoalPos.x - cPos.x), (GoalPos.z - (cPos.z + Search_info.Distance)));	//��
	Search_info.Renge_To_Goal[1] = hypot((GoalPos.x - cPos.x), (GoalPos.z - (cPos.z - Search_info.Distance)));	//��
	Search_info.Renge_To_Goal[2] = hypot((GoalPos.x - (cPos.x + Search_info.Distance)), (GoalPos.z - cPos.z));	//�E
	Search_info.Renge_To_Goal[3] = hypot((GoalPos.x - (cPos.x - Search_info.Distance)), (GoalPos.z - cPos.z));	//��
	Search_info.Renge_To_Goal[4] = hypot((GoalPos.x - (cPos.x + Search_info.Distance)), (GoalPos.z - (cPos.z + Search_info.Distance)));	//�E��
	Search_info.Renge_To_Goal[5] = hypot((GoalPos.x - (cPos.x + Search_info.Distance)), (GoalPos.z - (cPos.z - Search_info.Distance)));	//�E��
	Search_info.Renge_To_Goal[6] = hypot((GoalPos.x - (cPos.x - Search_info.Distance)), (GoalPos.z - (cPos.z + Search_info.Distance)));	//����
	Search_info.Renge_To_Goal[7] = hypot((GoalPos.x - (cPos.x - Search_info.Distance)), (GoalPos.z - (cPos.z - Search_info.Distance)));	//����

	//���v�����̍ŏ������߂�
	for (int Index = 0; Index < 8; Index++)
	{
		Search_info.Total_Renge[Index] = Search_info.Range_From_Start[Index] + Search_info.Renge_To_Goal[Index];
		
		if (Index == 0)
		{
			Search_info.Min_Total_Renge = Search_info.Total_Renge[0];
		}
		else
		{
			if (Search_info.Total_Renge[Index] < Search_info.Min_Total_Renge)
			{
				Search_info.Min_Total_Renge = Search_info.Total_Renge[Index];
				//�ŏ��̏ꏊ�̒l���i�[����
				//���݂�Center_Pos�ɗ��ꂽ���W���𑫂�
				Search_info.Center_Pos = VGet(cPos.x, 0.0f, cPos.z);
			}
		}
	}

	
}

