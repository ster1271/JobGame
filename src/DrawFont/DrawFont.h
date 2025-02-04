#pragma once
#include "DxLib.h"

enum FontID
{
	FONT_ID_CP,			//�`�F�b�N�|�C���g�t�H���g


	FONTID_NUM			//���ԍ�
};

enum FontSizeID
{
	FONT_ID_CP_10,			//�`�F�b�N�|�C���g�t�H���g
	FONT_ID_CP_20,			//�`�F�b�N�|�C���g�t�H���g
	FONT_ID_CP_30,			//�`�F�b�N�|�C���g�t�H���g
	FONT_ID_CP_40,			//�`�F�b�N�|�C���g�t�H���g
	FONT_ID_CP_50,			//�`�F�b�N�|�C���g�t�H���g

	FONTSIZE_NUM
};



static const char FontFilePath[FONTID_NUM][128]
{
	"data/FontData/CPFont.otf",
};

static const char FontName[FONTID_NUM][128]
{
	"�`�F�b�N�|�C���g�t�H���g",
};

static int FontHndl[FONTSIZE_NUM];

class CDrawFont
{
private:

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CDrawFont();
	~CDrawFont();

	//������
	static void Init();

	//�I������
	static void Exit();

	//�f�[�^�̓ǂݍ���
	static bool LoadAllFontData();

	//�`��
	static void Draw(int PosX, int PosY, FontSizeID Id,
		const TCHAR *String, unsigned int Color = GetColor(255, 255, 255));

};
