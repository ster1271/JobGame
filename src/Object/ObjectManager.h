#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "Object.h"
#include "Sky/Sky.h"
#include "Ground/Ground.h"
#include "Route_Point/Route_Point.h"

using namespace std;

//�I�u�W�F�N�g�}�l�[�W���[�N���X
class CObjectManager
{
private:
	CSky cSky;			//�V���N���X
	CGround cGround;	//�}�b�v�N���X

	int Point_Hndl;
	Check_Point Check_Point[5];
	//CObject�^��Route_Point�i�[�z��
	//vector<CObject*> Point_List;


public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CObjectManager();
	~CObjectManager();

	//������
	void Init();

	//�ǂݍ��݊֘A
	void Load();

	//�`��
	void Draw();

	//���t���[���s������
	void Step();

	//�X�V����
	void Update();

	//�㏈��
	void Exit();

	//�ݒu����
	void Set_Point(const VECTOR& vPos);
};
