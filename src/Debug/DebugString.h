#pragma once
#include "DxLib.h"
#include <list>
#include <string>

using namespace std;

//�f�o�b�O�t���O
constexpr bool isDebug = true;

//�����̃f�t�H���g�J���[
#define DEFAULT_COLOR	GetColor(255, 0, 0)

//���X�g�̃T�C�Y
constexpr int TEXTINFO_LIST_SIZE = 100;

//�\��������̃T�C�Y
constexpr int CHAR_SIZE = 512;

//�f�o�b�N�����\���p�\����
struct TextInfo
{
	int x;					//�\�����W�FX
	int y;					//�\�����W�FY
	string debugString;		//����
	unsigned int color;		//�����F
	bool isUse;				//�g�p�t���O
};


class CDebugString
{
private:
	/*�R���X�g���N�^�E�f�X�g���N�^
	(����ɃN���X������Ȃ��悤�ɂ��邽�߂�private�ɍ��)*/
	CDebugString();
	~CDebugString();

	static CDebugString* cInstance;		//�C���X�^���X

	list<TextInfo> cTextInfoList;		//�e�L�X�g���i�[���X�g

	//list�Ƀf�[�^��ǉ�
	void AddTextInfo(TextInfo textinfo);


public:
	static void Create();				//�C���X�^���X�̐���

	static void Destroy();				//�C���X�^���X�̍폜

	static CDebugString* GetInstance();	//�C���X�^���X�̎擾

	//�f�o�b�N�����f�[�^��ǉ�
	void AddString(int x, int y, string string);
	void AddFormatString(int x, int y, const char* format, ...);

	//�`��
	void Draw();

	//�o�̓��O�ɕ\��
	void DrawLogString(string string);
	void DrawLogFormatString(const char* format, ...);

};
