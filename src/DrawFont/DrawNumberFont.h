#pragma once
#include "DxLib.h"

//�i���o�[�t�H���g�N���X
class CNumber
{
private:
	
	/*
	int NumberPosX;			//���W
	int NumberPosY;			//���W			
	VECTOR NumberPos;		//���W(VECTOR�^)
	*/

public:
	CNumber();
	~CNumber();

	//������
	static void Init();

	//�㏈��
	static void Fin();

	//�i���o�[�t�H���g�ǂݍ���
	static void SetNumber(const char FontDataPath[128], int SizeX, int SizeY);

	//�i���o�[�t�H���g�`��(���{�`��, 16*32�̂ݗL��)
	static void DrawNumber_Normal(int Number, VECTOR Pos);

	//�i���o�[�t�H���g�`��(2�{�`��, 16*32�̂ݗL��)
	static void DrawNumber_Double(int Number, VECTOR Pos);

};
