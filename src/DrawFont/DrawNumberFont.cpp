#include "../DrawNumberFont/DrawNumberFont.h"

int Hundl[13];			//�i�[


//�R���X�g���N�^
CNumber::CNumber()
{
	for (int i = 0; i < 13; i++)
	{
		Hundl[i] = 0;
	}
	
	/*
	NumberPos = { 0.0f, 0.0f, 0.0f };
	NumberPosX = 0;
	NumberPosY = 0;
	*/
}
//�f�X�g���N�^
CNumber::~CNumber()
{
	for (int i = 0; i < 13; i++)
	{
		DeleteGraph(Hundl[i]);
	}

	/*
	NumberPos = { 0.0f, 0.0f, 0.0f };
	NumberPosX = 0;
	NumberPosY = 0;
	*/
}


//������
void CNumber::Init()
{
	for (int i = 0; i < 13; i++)
	{
		Hundl[i] = 0;
	}

	/*
	NumberPos = { 0.0f, 0.0f, 0.0f };
	NumberPosX = 0;
	NumberPosY = 0;
	*/
}

//�㏈��
void CNumber::Fin()
{
	for (int i = 0; i < 13; i++)
	{
		DeleteGraph(Hundl[i]);
	}

	/*
	NumberPos = { 0.0f, 0.0f, 0.0f };
	NumberPosX = 0;
	NumberPosY = 0;
	*/
}

//�i���o�[�t�H���g�ǂݍ���
//������	�t�H���g�f�[�^�̃p�X
//������	�c��
//��O����	����
void CNumber::SetNumber(const char FontDataPath[128], int SizeX, int SizeY)
{
	//�ی��ŏ��������Ă���
	for (int i = 0; i < 13; i++)
	{
		if (Hundl[i] != 0)
		{
			Hundl[i] = 0;
		}
	}

	//�ǂݍ���
	LoadDivGraph(FontDataPath, 13, 13, 1, SizeX, SizeY, Hundl);
}


//�i���o�[�t�H���g�`��
//*���{�̂ݗL��(16*32)
//������	���ꂽ������
//������	�\�����������W
void CNumber::DrawNumber_Normal(int Number, VECTOR Pos)
{
	//�|�C���g�`��
	int DrawNumber = Number;

	int count = 0;

	//DrawNumber��0�ɂȂ����Ƃ�
	if (DrawNumber == 0) {
		DrawGraph((int)Pos.x - count * 20, (int)Pos.y, Hundl[0], true);
	}
	//DrawNumber��0�ȊO�̎�
	while (DrawNumber > 0)
	{
		int num = DrawNumber % 10;
		DrawNumber = DrawNumber / 10;
		DrawGraph((int)Pos.x - count * 20, (int)Pos.y, Hundl[num], true);
		count++;
	}
}

//�i���o�[�t�H���g�`��(VECTOR�^)
// //*2�{�̂ݗL��(16*32)
//������	���ꂽ������
//������	�\�����������W(VECTOR�^)
void CNumber::DrawNumber_Double(int Number, VECTOR Pos)
{
	//�|�C���g�`��
	int DrawNumber = Number;

	int count = 0;

	//DrawNumber��0�ɂȂ����Ƃ�
	if (DrawNumber == 0) {
		DrawRotaGraph((int)Pos.x - count * 35, (int)Pos.y, 2.0f, 0.0f, Hundl[0], true);
	}
	//DrawNumber��0�ȊO�̎�
	while (DrawNumber > 0)
	{
		int num = DrawNumber % 10;
		DrawNumber = DrawNumber / 10;
		DrawRotaGraph((int)Pos.x - count * 35, (int)Pos.y, 2.0f, 0.0f, Hundl[num], true);
		count++;
	}
}