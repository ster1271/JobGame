#include "DrawFont.h"

//�R���X�g���N�^
CDrawFont::CDrawFont(){}

//�f�X�g���N�^
CDrawFont::~CDrawFont(){}

//������
void CDrawFont::Init()
{
	for (int FontIndex = 0; FontIndex < FONTID_NUM; FontIndex++)
	{
		FontHndl[FontIndex] = -1;
	}

}

//�I������
void CDrawFont::Exit()
{
	//���[�h�����t�H���g���������
	for (int FontIndex = 0; FontIndex < FONTID_NUM; FontIndex++)
	{
		RemoveFontResourceEx(FontFilePath[FontIndex], FR_PRIVATE, NULL);
		FontHndl[FontIndex] = -1;
	}
}

//�f�[�^�̓ǂݍ���
bool CDrawFont::LoadAllFontData()
{
	bool IsLoadFont = true;
	int Index = 0;

	for (int FontIndex = 0; FontIndex < FONTID_NUM; FontIndex++)
	{
		//�V�����t�H���g�f�[�^��ǂݍ���
		int a = AddFontResourceEx(FontFilePath[FontIndex], FR_PRIVATE, NULL);
		if (a == 0)
		{
			return false;
		}

		//�ǂݍ��񂾃t�H���g�f�[�^���n���h���ɕۑ�
		//����1�F�ǂݍ��ރt�H���g�f�[�^�p�X
		//����2�F�t�H���g�̃T�C�Y
		//����2�F�t�H���g�̉��̑���(0�Ȃ牏�Ȃ�)
		for (int SizeIndex = 1; SizeIndex < 5; SizeIndex++)
		{
			FontHndl[Index] = CreateFontToHandle(FontName[FontIndex], 10 * SizeIndex, 1, DX_FONTTYPE_NORMAL);

			//1�ł����[�h���s������΃t���O���I�t��
			if (FontHndl[Index] == -1)
			{
				IsLoadFont = false;
			}

			Index++;
		}
	}
	return IsLoadFont;
}

//�`��
void CDrawFont::Draw(int PosX, int PosY, FontSizeID Id,
	const TCHAR* String, unsigned int Color)
{
	DrawFormatStringToHandle(PosX, PosY, Color, FontHndl[Id], String);
}