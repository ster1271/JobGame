#pragma once 
#include "DxLib.h"
#include "../Input/Input.h"
#include "../Object/Object.h"

//�{�b�g�N���X
class CBot :public CObject
{
private:
	bool IsMove;
	float tmp_dir;
public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CBot();
	~CBot();

	//������
	void Init();

	//�ǂݍ���
	bool Load();

	//�`��
	void Draw();

	//���t���[���s������
	void Step(VECTOR Set_Point);

	//�w��̏ꏊ�ɓ�������
	void Move_Bot(VECTOR Set_point);

};
