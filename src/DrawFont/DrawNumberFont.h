#pragma once
#include "DxLib.h"

//�i���o�[�t�H���g�N���X
class CNumber
{
private:
	int Hundl[13];			//�i�[

	/*
	int NumberPosX;			//���W
	int NumberPosY;			//���W			
	VECTOR NumberPos;		//���W(VECTOR�^)
	*/

public:
	CNumber();
	~CNumber();

	//������
	void Init();

	//�㏈��
	void Fin();

	//�i���o�[�t�H���g�ǂݍ���
	void SetNumber(const char FontDataPath[128], int SizeX, int SizeY);

	//�i���o�[�t�H���g�`��(���{�`��, 16*32�̂ݗL��)
	void DrawNumber_Normal(int Number, VECTOR Pos);

	//�i���o�[�t�H���g�`��(2�{�`��, 16*32�̂ݗL��)
	void DrawNumber_Double(int Number, VECTOR Pos);

};
