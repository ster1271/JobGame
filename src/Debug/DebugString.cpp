#include "DebugString.h"
#include <cstdarg>	//�ψ����̏����ɕK�v
#include <cstdio>	//vsnprint�̎g�p�ɕK�v
#include <Windows.h>

//�C���X�^���X�̏�����
CDebugString* CDebugString::cInstance = nullptr;

//�R���X�g���N�^
CDebugString::CDebugString()
{
	//���X�g�̏�����
	cTextInfoList.resize(TEXTINFO_LIST_SIZE);
	for (TextInfo& value : cTextInfoList)
	{
		value.isUse = false;
	}
}

//�f�X�g���N�^
CDebugString::~CDebugString()
{
}


//�C���X�^���X�̐���
void CDebugString::Create()
{
	//�C���X�^���X�ɂ���������Ă��Ȃ�������
	if (cInstance == nullptr)
	{
		//�V����new����
		cInstance = new CDebugString();
	}
}


//�C���X�^���X�̍폜
void CDebugString::Destroy()
{
	//�C���X�^���X����������Ă�����
	if (cInstance != nullptr)
	{
		//delete����nullptr������
		delete cInstance;
		cInstance = nullptr;
	}
}


//�C���X�^���X�̎擾
CDebugString* CDebugString::GetInstance()
{
	if (cInstance == nullptr)
	{
		//�C���X�^���X����������Ă��Ȃ������琶������
		Create();
		return cInstance;
	}
	else
	{
		return cInstance;
	}
}


//�f�o�b�N�����f�[�^��ǉ�
void CDebugString::AddString(int x, int y, string string)
{
	TextInfo tmp = { x, y, string, DEFAULT_COLOR, true };
	AddTextInfo(tmp);
}

void CDebugString::AddFormatString(int x, int y, const char* format, ...)
{
	//�t�H�[�}�b�g�ς݂̕�������i�[����o�b�t�@
	char buffer[CHAR_SIZE];

	//�ψ���������
	va_list args;
	va_start(args, format);
	//�t�H�[�}�b�g�ς݂̕�����𐶐�
	vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);

	TextInfo tmp = { x, y, buffer, DEFAULT_COLOR, format };
	AddTextInfo(tmp);
}

//list�Ƀf�[�^��ǉ�
void CDebugString::AddTextInfo(TextInfo textInfo)
{
	for (TextInfo& value : cTextInfoList)
	{
		if (!value.isUse)
		{
			value = textInfo;
			return;
		}
	}
}


//�`��
void CDebugString::Draw()
{
	if (!isDebug)
		return;

	for (TextInfo& value : cTextInfoList)
	{
		if (value.isUse)
		{
			DrawString(value.x, value.y, value.debugString.c_str(), value.color);
			//�\�������疢�g�p�ɂ���
			value.isUse = false;
		}
	}
}

//�o�̓��O�ɕ\��
void CDebugString::DrawLogString(string string)
{
	string += "\n";
	OutputDebugString(string.c_str());
}

//�o�̓��O�ɕ\��
void CDebugString::DrawLogFormatString(const char* format, ...)
{
	if (!isDebug)
		return;

	//�t�H�[�}�b�g�ς݂̕�������i�[����o�b�t�@
	char buffer[CHAR_SIZE];

	//�ψ���������
	va_list args;
	va_start(args, format);
	//�t�H�[�}�b�g�ς݂̕�����𐶐�
	vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);

	DrawLogString(buffer);
}

